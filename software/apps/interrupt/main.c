// Interrupt app
//
// Trigger GPIO and Software interrupts

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf.h"
#include "nrf_delay.h"

#include "microbit_v2.h"

// Initialize software interrupts
void software_interrupt_init(void) {
  NRF_EGU1->INTENSET = 0x1;
  NVIC_EnableIRQ(SWI1_EGU1_IRQn);
}

// Trigger a software interrupt
void software_interrupt_trigger(void) {
  NRF_EGU1->TASKS_TRIGGER[0] = 1;
}

void SWI1_EGU1_IRQHandler(void) {
  // Clear interrupt event
  NRF_EGU1->EVENTS_TRIGGERED[0] = 0;
  
  for (int i = 0; i < 2000; i += 100) {
     printf("Software Interrupt\n");
     nrf_delay_ms(i);

  }
}

void GPIOTE_IRQHandler(void) {
  // Clear interrupt event
  printf("Interrupted!\n");
  NRF_GPIOTE->EVENTS_IN[0] = 0;
  

}

int main(void) {
  printf("Board started!\n");

  // Step 5:
  // Trigger a GPIOTE interrupt
  // You can access the GPIOTE register map as NRF_GPIOTE->
  //    where the register name in all caps goes after the arrow.
  //    For example, NRF_GPIOTE->CONFIG[0]
  NRF_GPIOTE->CONFIG[0] = 0x00020E01;
  NRF_GPIOTE->INTENSET = 0x1;
  NVIC_EnableIRQ(GPIOTE_IRQn);
  NVIC_SetPriority(GPIOTE_IRQn, 0);

  // STEP 6:
  // Trigger a software interrupt
  // Use the software_interupt_* functions defined above
  software_interrupt_init();
  NVIC_SetPriority(SWI1_EGU1_IRQn, 1);

  // STEP 7:
  // Trigger a software interrupt and demonstrate that a GPIO interrupt
  //    can preempt it if at a lower priority number
  software_interrupt_trigger();
  // loop forever
  while (1) {

    printf("Looping\n");
    
    nrf_delay_ms(1000);
  }
}

