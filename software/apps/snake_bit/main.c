// snake_bit main app
//
// Run the snake_bit game

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "app_timer.h"
#include <math.h>

#include "nrf_delay.h"
#include "nrf_twi_mngr.h"
#include "nrfx_lpcomp.h"
#include "nrf_lpcomp.h"

#include "microbit_v2.h"
#include "lsm303agr.h"

// Includes for heartbeat
#include "heartbeat.h"

// Global variables
// NRF_TWI_MNGR_DEF(twi_mngr_instance, 1, 0);

int main(void) {
    extern uint16_t bpm;
    printf("Board started!\n");

    heartbeat_setup();

    // Loop forever
    while (true) {
        // Don't put any code in here. Instead put periodic code in a callback using a timer.
        nrf_delay_ms(1000);
        printf("bpm: %d\n", bpm);
    }
}
