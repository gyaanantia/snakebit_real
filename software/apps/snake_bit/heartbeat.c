
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "app_timer.h"
#include "nrfx_lpcomp.h"
#include "nrf_lpcomp.h"

#include "microbit_v2.h"
#include "heartbeat.h"

static void lpcomp_event_handler(nrf_lpcomp_event_t event) {
    printf("Bing Bong!\n");
}

void heartbeat_setup() {

    nrf_lpcomp_config_t hal_ = {
            .detection = NRF_LPCOMP_DETECT_CROSS,
            .reference = NRF_LPCOMP_REF_SUPPLY_4_8
    };

    nrf_lpcomp_input_t input_ = NRF_LPCOMP_INPUT_3;

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



