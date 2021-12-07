
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "app_timer.h"
#include "nrfx_lpcomp.h"
#include "nrf_lpcomp.h"

#include "microbit_v2.h"
#include "heartbeat.h"

static void lpcomp_event_handler(nrf_lpcomp_event_t event) {
    if(event == NRF_LPCOMP_EVENT_UP){
        printf("Bing Bong!\n");
    }
}

void heartbeat_setup() {

    nrf_lpcomp_config_t hal_ = {
            .detection = NRF_LPCOMP_DETECT_UP,
            .reference = NRF_LPCOMP_REF_SUPPLY_7_8
    };

    nrf_lpcomp_input_t input_ = NRF_LPCOMP_INPUT_3;

    nrfx_lpcomp_config_t p_config_ = {
            .hal = hal_,
            .input = input_,
            .interrupt_priority = 1
    };

    // initialize the LPCOMP driver
    nrfx_lpcomp_init(&p_config_, lpcomp_event_handler);

    // enable the LPCOMP peripheral and interrupts
    nrfx_lpcomp_enable();

}



