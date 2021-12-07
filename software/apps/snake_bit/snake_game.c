
#include <stdbool.h>
#include "oled.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "app_timer.h"
#include "microbit_v2.h"


NRF_TWI_MNGR_DEF(twi_mngr_instance, 1, 0);
APP_TIMER_DEF(timer1);

uint8_t score, apple_x, apple_y, direction;
bool apple_eaten, lost;

struct Node{
    uint8_t x, y;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

//typedef struct {
//  Node* head;
  ///Node* tail;
//} List;

// checks what buttons are pushed and changes global variable direction based on button push and  direction
void cur_direction(){
    if( (direction == 1) || (direction == 2) || (direction ==0)) {
        if(!nrf_gpio_pin_read(14)){
            direction = 3; // turns right
        }
    if(!nrf_gpio_pin_read(23)) {
        direction = 4; // turns left
    }
    } else if(direction == 3) {
        if(!nrf_gpio_pin_read(14)){
            direction = 1; // up
        }
        if(!nrf_gpio_pin_read(23)){
            direction = 2; //down
        }
    } else if(direction == 4) {
            if(!nrf_gpio_pin_read(14)){
                direction = 2; //down
            }
            if(!nrf_gpio_pin_read(23)){
                direction = 1;// up
            }
        }
}

void moving()
{
    uint8_t new_x = head->x;
    uint8_t new_y = head->y;
    if(direction == 2){
        new_y =  head->y +1;
    }
    if(direction == 1){
        new_y =  head->y -1;
    }
    if(direction == 3){
        new_x =  head->x +1;
    }
    if(direction == 4){
        new_x =  head->x -1;
    }
    struct Node* new_node = malloc(sizeof(struct Node));;
    new_node->x = new_x;
    new_node->y = new_y;
    new_node->next = head;
    new_node->prev = NULL;
    head->prev = new_node;

//    if(head != NULL){
//        head->prev = new_node;
//    }
    head = new_node;
    if(!apple_eaten){
       struct Node* temp =  tail;
       tail =  tail->prev;
       tail->next = NULL;
       free(temp);
    }
}


void new_apple(){
    apple_x = rand() % 64;
    apple_y = rand() % 48;
    while(apple_x == head->x && apple_y == head->y) {
        apple_x = rand() % 65;
        apple_y = rand() % 49;
    }
    apple_eaten = false;
}

void apple_eat(){
    if((head->x == apple_x) && (head->y == apple_y)) {
        score ++;
        apple_eaten = true;
    }
}

void lose(){
    if((head->y <= 0) ||  (head->y >= 48)){
        lost = true;
    }
    if((head->x <= 0) ||  (head->x >= 64)){
        lost = true;
    }
    struct Node* temp = head->next;
    while(temp != NULL) {
        if (head->x == temp->x) {
            if( head->y == temp->y) {
                lost = true;
            }
        }
        temp = temp->next;
    }
}

void new_game(){
    new_apple();
    direction = 1;
    struct Node* one = NULL;
    struct Node* two = NULL;
    struct Node* three = NULL;
    struct Node* four = NULL;
    struct Node* five = NULL;

    one = malloc(sizeof(struct Node));
    two = malloc(sizeof(struct Node));
    three = malloc(sizeof(struct Node));
    four = malloc(sizeof(struct Node));
    five = malloc(sizeof(struct Node));

    one->x = 32;
    one->y = 24;
    two->x = 32;
    two->y = 25;
    three->x = 32;
    three->y = 26;
    four->x = 32;
    four->y = 27;
    five->x = 32;
    five->y = 28;

    one->next = two;
    one->prev = NULL;
    two->next = three;
    two->prev = one;
    three->next = four;
    three->prev = two;
    four->next = five;
    four->prev = three;
    five->next = NULL;
    five->prev = four;

    head = one;
    tail = five;
    lost = false;

}

void draw_board(){
    int i = 0;
    struct Node* temp = head;
    while(temp != NULL ){
        pixel((temp->x), (temp->y)); // need the draw function
        if((temp->x == apple_x) && (temp->y==apple_y)){
            i = 1;
        }
        temp = temp->next;
    }
    if (i == 0){
         pixel(apple_x, apple_y); //need the draw function
    }
    display();
}

int main(){
    printf("Board started!\n");

    // Initialize I2C peripheral and driver
    nrf_drv_twi_config_t i2c_config = NRF_DRV_TWI_DEFAULT_CONFIG;
    i2c_config.scl = EDGE_P19;
    i2c_config.sda = EDGE_P20;
    i2c_config.frequency = (nrf_drv_twi_frequency_t) NRF_TWIM_FREQ_100K;
    i2c_config.interrupt_priority = 0;
    nrf_twi_mngr_init(&twi_mngr_instance, &i2c_config);
    oledtwi_init(&twi_mngr_instance, DISPLAY_ADDRESS);

    new_game();
    app_timer_init(); // this needs to be moved
    app_timer_create(&timer1, APP_TIMER_MODE_REPEATED, draw_board);
    app_timer_start(timer1, 32768/5000, NULL);

    while(!lost){
        if ((!nrf_gpio_pin_read(14)) || (!nrf_gpio_pin_read(23))){ // can maybe replace this with an interupt
        cur_direction();
        }
        lose();
        apple_eat();
//        if (lost){
//            struct Node* temp = head;
//            while(temp != NULL){
//                struct Node* other = temp->next;
//                free(temp);
//                temp = other;
//            }
//            printf("score: %i", score);
//            nrf_delay_ms(30);
//            new_game();
//        }
        moving();
        if (apple_eaten){
            new_apple();
        }

        int heart_beat_val = 75; // this needs to be replaced by the actual heart beat thing
        nrf_delay_ms(500/heart_beat_val);
    }
    printf("score: %i", score);
    nrf_delay_ms(30);

    struct Node* temp = head;
    while(temp != NULL){
        struct Node* other = temp->next;
        free(temp);
        temp = other;
    }
}
