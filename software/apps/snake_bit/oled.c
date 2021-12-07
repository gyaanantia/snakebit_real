#include "oled.h"
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "nrf_delay.h"

static uint8_t screenbuffer[128 * 8];
const uint8_t LCDHEIGHT_ = 64;
const uint8_t LCDWIDTH_ = 128;

// Pointer to an initialized I2C instance to use for transactions
static const nrf_twi_mngr_t *i2c_manager = NULL;

// Helper function to perform a 1-byte I2C read of a given register
//
// i2c_addr - address of the device to read from
// reg_addr - address of the register within the device to read
//
// returns 8-bit read value
static uint8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr)
{
    uint8_t rx_buf = 0;
    nrf_twi_mngr_transfer_t const read_transfer[] = {
            // .transWrite =
            NRF_TWI_MNGR_WRITE(i2c_addr, &reg_addr, 1, NRF_TWI_MNGR_NO_STOP),

            // .transRead =
            NRF_TWI_MNGR_READ(i2c_addr, &rx_buf, 1, 0)

    };
    nrf_twi_mngr_perform(i2c_manager, NULL, read_transfer, 2, NULL);

    return rx_buf;
}

// Helper function to perform a 1-byte I2C write of a given register
//
// i2c_addr - address of the device to write to
// reg_addr - address of the register within the device to write
static void i2c_command(uint8_t i2c_addr, uint8_t command)
{

    uint8_t writeAdrs[2] = {I2C_COMMAND, command};
    nrf_twi_mngr_transfer_t const write_transfer[] = {

            NRF_TWI_MNGR_WRITE(i2c_addr, writeAdrs, 2, 0)};

    nrf_twi_mngr_perform(i2c_manager, NULL, write_transfer, 1, NULL);

    //Note: there should only be a single two-byte transfer to be performed
}

static void i2c_data(uint8_t i2c_addr, uint8_t data)
{

    uint8_t writeAdrs[2] = {I2C_DATA, data};
    nrf_twi_mngr_transfer_t const write_transfer[] = {

            NRF_TWI_MNGR_WRITE(i2c_addr, writeAdrs, 2, 0)};

    nrf_twi_mngr_perform(i2c_manager, NULL, write_transfer, 1, NULL);

    //Note: there should only be a single two-byte transfer to be performed
}

// i2cWriteMultiple(moled_i2c_address, (uint8_t *)&zeros, 0x80)
//static void i2c_write_multiple(uint8_t i2c_addr, uint8_t *data_bytes, size_t num_data_bytes)
//{
//    size_t bytes_left_to_write = num_data_bytes;
//
//    while (bytes_left_to_write > 0) {
//        size_t bytes_to_write;
//
//    }
//}

// This function creates a variably sized array which holds a slice of the screenbuffer,
// then writes that as data to the screen
// i2cWriteMultiple(moled_i2c_address, (uint8_t *)&screenmemory[i * 0x40], 0x40);
static void i2c_write_block(uint8_t i2c_addr, uint8_t control_byte, uint8_t* arr, int start_index, int stop_index)
{
    int size = stop_index - start_index;
    uint8_t writeArr[size * 2];
    int count = 0;
    for (int i = 1; i < size * 2; i += 2) {
        writeArr[i] = arr[start_index + count];
        count++;
    }

    for (int j = 0; j < size * 2; j += 2) {
        writeArr[j] = control_byte;
    }

//    for (int k = 0; k < size * 2; k++) {
//        printf("%x ", writeArr[k]);
//    }
//    printf("\n\n");

    nrf_twi_mngr_transfer_t const write_transfer[] = {
            NRF_TWI_MNGR_WRITE(i2c_addr, writeArr, size * 2, 0)
    };

    nrf_twi_mngr_perform(i2c_manager, NULL, write_transfer, 1, NULL);
}

static void write_data_block(uint8_t  i2c_addr, uint8_t* arr, int start_index, int stop_index)
{
    for (int i = start_index; i < stop_index; i++) {
        i2c_data(i2c_addr, arr[i]);
    }

}

void oledtwi_init(const nrf_twi_mngr_t* i2c, uint8_t address)
{
    i2c_manager = i2c;
    i2c_command(address, DISPLAYOFF);

    i2c_command(address, SETDISPLAYCLOCKDIV);
    i2c_command(address, 0x80);

    i2c_command(address, SETMULTIPLEX);
    i2c_command(address, LCDHEIGHT_ - 1);

    i2c_command(address, SETDISPLAYOFFSET);
    i2c_command(address, 0x0);

    i2c_command(address, SETSTARTLINE | 0x0);

    i2c_command(address, CHARGEPUMP);
    i2c_command(address, 0x14);

    i2c_command(address, NORMALDISPLAY);
    i2c_command(address, DISPLAYALLONRESUME);

    i2c_command(address, SEGREMAP | 0x1);
    i2c_command(address, COMSCANDEC);

    i2c_command(address, SETCOMPINS);

    i2c_command(address, 0x12);

    i2c_command(address, SETCONTRAST);
    i2c_command(address, 0x8F);

    i2c_command(address, SETPRECHARGE);
    i2c_command(address, 0x22);

    i2c_command(address, SETVCOMDESELECT);
    i2c_command(address, 0x30);

    i2c_command(address, DISPLAYON);

    clear(ALL, address);
}

void clear(uint8_t mode, uint8_t address)
{
    if (mode == ALL) {
        for (int i = 0; i < 8; i++) {
            set_page_address(i);
            set_column_address(0);

            for (int j = 0; j < 0x80; j++) {
                i2c_data(address, 0);
            }
        }
    } else {
        for (int k = 0; k < (sizeof(screenbuffer) / sizeof(screenbuffer[0])); k++) {
            screenbuffer[k] = 0;
        }
    }
}

void set_page_address(uint8_t pageAddress)
{
    i2c_command(DISPLAY_ADDRESS, 0x22);
    i2c_command(DISPLAY_ADDRESS, (pageAddress & (LCDHEIGHT_ - 1)));
    i2c_command(DISPLAY_ADDRESS, LCDHEIGHT_ - 1);
}

void set_column_address(uint8_t colAddress)
{
    if (sizeof(screenbuffer)/sizeof(screenbuffer[0]) == 384) {
        i2c_command(DISPLAY_ADDRESS, (0x10 | (colAddress >> 4)) + 0x02);
        i2c_command(DISPLAY_ADDRESS, (0x0F & colAddress));
    }
    i2c_command(DISPLAY_ADDRESS, 0x21);
    i2c_command(DISPLAY_ADDRESS, (colAddress & (LCDWIDTH_ - 1)));
    i2c_command(DISPLAY_ADDRESS, LCDWIDTH_ - 1);
}

int min(int a, int b)
{
    return (a > b) ? b : a;
}

void display()
{
    int lenBlock = 32;
    int lenLine = (int)LCDWIDTH_;
    int lenHeight = (int)LCDHEIGHT_;
    int nBlocks = (int)(ceil(lenLine/lenBlock));
    int mBlocks = (int)(ceil(lenHeight/8));

    for (int i = 0; i < mBlocks; i++) {
        set_page_address(i);
        int lineStart = i * lenLine;

        for (int iBlock = 0; iBlock < nBlocks; iBlock++) {
            int iStart = iBlock * lenBlock;
            set_column_address(iStart);
            int iEnd = iStart + min(lenLine - iStart, lenBlock); // what's left - not > 32 in len

            write_data_block(DISPLAY_ADDRESS, screenbuffer, lineStart + iStart, lineStart + iEnd);
        }
    }

//    print_screen();
}

void pixel(int x, int y)
{

    if (x < 0 || x >= 64 || y < 0 || y >= 48) {
        return;
    }

    x += 0x20;
    y += 0x10;

    int index = (int)(x + floor(y / 8) * LCDWIDTH_);

    screenbuffer[index] |= (1 << (y % 8));
}

void print_screen() {
    for (int i = 0; i < (8 * 128); i++) {
        printf("%x", screenbuffer[i]);
        if (i == ((128*8) - 1)){
            printf("\n");
        }
    }
}