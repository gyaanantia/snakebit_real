//// I2C sensors app
////
//// Read from I2C accelerometer/magnetometer on the Microbit
//
//#include <stdbool.h>
//#include <stdint.h>
//#include <stdio.h>
//#include "app_timer.h"
//#include <math.h>
//
//#include "nrf_delay.h"
//#include <nrf_twi_mngr.h>
//
//#include "microbit_v2.h"
//#include "lsm303agr.h"
//#include "oled.h"
//
//// Global variables
//NRF_TWI_MNGR_DEF(twi_mngr_instance, 1, 0);
////APP_TIMER_DEF(my_timer_1);
//
//int main_(void) {
//  printf("Board started!\n");
//
//  // Initialize I2C peripheral and driver
//  nrf_drv_twi_config_t i2c_config = NRF_DRV_TWI_DEFAULT_CONFIG;
//  i2c_config.scl = EDGE_P19;
//  i2c_config.sda = EDGE_P20;
//  i2c_config.frequency = (nrf_drv_twi_frequency_t) NRF_TWIM_FREQ_100K;
//  i2c_config.interrupt_priority = 0;
//  nrf_twi_mngr_init(&twi_mngr_instance, &i2c_config);
//
//  // Initialize the LSM303AGR accelerometer/magnetometer sensor
////  lsm303agr_init(&twi_mngr_instance);
////
////  app_timer_init();
////  app_timer_create(&my_timer_1, APP_TIMER_MODE_REPEATED, read_everything);
////  app_timer_start(my_timer_1, 32768, NULL);
//
//  oledtwi_init(&twi_mngr_instance, DISPLAY_ADDRESS);
//  clear(ALL, DISPLAY_ADDRESS);
//  pixel(32, 32);
//
//  // BOUNDS: 0x20 <= x <= 0x5F, 0x10 <= y <= 0x3F
////  pixel(32, 33);
////  pixel(33, 32);
////  pixel(33, 33);
//
//  display();
//  nrf_delay_ms(1000);
//  // Loop forever
//  while (1) {
//    // Don't put any code in here. Instead put periodic code in a callback using a timer.
//    nrf_delay_ms(1000);
//  }
//}

