
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "nrf.h"
#include "nrfx_timer.h"
#include "nrfx_lpcomp.h"
#include "nrf_lpcomp.h"
#include "nrf_gpio.h"
#include "app_timer.h"
#include "app_error.h"

#include "microbit_v2.h"
#include "heartbeat.h"

uint8_t counter;
uint16_t avg_bpm;
APP_TIMER_DEF(heartbeat_timer);
static nrfx_timer_t TIMER4 = NRFX_TIMER_INSTANCE(1);

static void lpcomp_event_handler(nrf_lpcomp_event_t event) {
//    printf("Bing Bong! + %hu\n", counter);

//    app_timer_stop(heartbeat_timer);
    nrfx_timer_pause(&TIMER4);

    uint32_t diff = nrfx_timer_capture(&TIMER4, 1);
    avg_bpm += (60 * 125000) / diff; // (60 / (diff / 125000))

//    app_timer_start(heartbeat_timer, 40000, NULL);
    nrfx_timer_clear(&TIMER4);
    nrfx_timer_resume(&TIMER4);

//    printf("diff: %lu\n", diff);

    counter++;

    if(counter == 8){
//        nrfx_rtc_disable(&rtc);
        counter = 0;
//        printf("_/\\__/\\__ bpm: %d\n\n", avg_bpm >> 3);
        bpm = avg_bpm >> 3;
        avg_bpm = 0;
    }
}

// The assert for nrfx timers gets pissed off if we don't give it a non-null callback
static void dummy_handler(nrf_timer_event_t event, void* context) {
    return;
}

void heartbeat_setup() {

//    nrfx_rtc_config_t rtc_config = NRFX_RTC_DEFAULT_CONFIG;
//    nrfx_rtc_init(&rtc, &rtc_config, NULL);

    // configure high-speed timer
    // timer should be 1 MHz and 32-bit
    nrfx_timer_config_t timer_config = {
            .frequency = NRF_TIMER_FREQ_125kHz,
            .mode = NRF_TIMER_MODE_TIMER,
            .bit_width = NRF_TIMER_BIT_WIDTH_32,
            .interrupt_priority = 4,
            .p_context = NULL
    };
    nrfx_timer_init(&TIMER4, &timer_config, dummy_handler);
    nrfx_timer_enable(&TIMER4);

    app_timer_init();
    app_timer_create(&heartbeat_timer, APP_TIMER_MODE_SINGLE_SHOT, NULL);

    // We need to first configure AIN3 to receive input
    nrf_gpio_range_cfg_input(3, 10, NRF_GPIO_PIN_PULLUP);

    // Debug:
    nrf_gpio_pin_clear(4);
    printf("GPIO pin 4 level: %lu\n", nrf_gpio_pin_read(4));

    counter = 0;

    nrf_lpcomp_config_t hal_ = {
            .detection = NRF_LPCOMP_DETECT_UP,
            .reference = NRF_LPCOMP_REF_SUPPLY_6_8
    };

    nrf_lpcomp_input_t input_ = NRF_LPCOMP_INPUT_2;

    nrfx_lpcomp_config_t p_config_ = {
            .hal = hal_,
            .input = input_,
            .interrupt_priority = 1
    };

    // initialize the LPCOMP driver
    nrfx_err_t error_code = nrfx_lpcomp_init(&p_config_, lpcomp_event_handler);

    printf("nrfx_lpcomp_init is NRFX_SUCCESS: %d\n", error_code == NRFX_SUCCESS);

    // enable the LPCOMP peripheral and interrupts
    nrfx_lpcomp_enable();

}



