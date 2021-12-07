
#include <stdbool.h>
#include "oled.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "app_timer.h"
#include "microbit_v2.h"

APP_TIMER_DEF(timer1);

uint8_t score, apple_x, apple_y, direction;
bool apple_eaten, lost;

typedef struct Node{
  uint8_t x, y;
  struct Node* next;
  struct Node* prev;
};

struct Node* head;
struct Node* tail;

//typedef struct {
//  Node* head;
  ///Node* tail;
//} List;

void cur_direction(){
  if( (direction == 1) || (direction == 2) || (direction ==0)){
    if(!gpio_read(14)){
       direction = 3; // turns right
    }
    if(!gpio_read(23)){
       direction =4; // turns left
    }
  }
    else if(direction == 3){
      if(!gpio_read(14)){
         direction = 1; // up
      }
      if(!gpio_read(23)){
         direction = 2; //down
      }
    }
      else if(direction == 4){
        if(!gpio_read(14)){
           direction = 2; //down
        }
        if(!gpio_read(23)){
           direction = 1;// up
        }
      }
}

void moving(){
 int new_x = 0;
 int new_y = 0;
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
 if((head) != NULL){
    (head)->prev = new_node;
 }
 head = new_node;
 if(!apple_eaten){
   struct Node* temp =  tail;
    tail =  tail->prev;
   free(temp);
 }
}


void new_apple(){
  apple_x = rand()%65;
  apple_y = rand()%49;
  while(apple_x== head->x && apple_y== head->y){
    apple_x = rand()%65;
    apple_y = rand()%49;
  }
  apple_eaten = false;
}

void apple_eat(){
  if((head->x == apple_x) && (head->y == apple_y)){
    score ++;
     apple_eaten = true;
  }
}

void lose(){
if((head->y <= 0) ||  (head->y>=348)){
   lost = true;
}
if((head->x<=0) ||  (head->x>=64)){
   lost = true;
}
 struct Node* temp = head->next;
 while(temp!= tail ){
    if (head->x == temp->x) {
      if( head->y == temp->y){
     lost = true;
  }
  }
  temp = temp->next;
}
}
void new_game(){
  new_apple();
  direction = 0;
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
    temp = temp -> next;
 }
 if (i=0){
 pixel(apple_x, apple_y); //need the draw function
}
 display();
}

void main(){
  new_game();
  while(1){
  if ((!gpio_read(14)) | (!gpio_read(23))){ // can maybe replace this with an interupt
  cur_direction();
  }
  lose();
  apple_eat();
  if (lost){
  struct Node* temp = head;
  while(temp != NULL){
    struct Node* other = temp->next;
    free(temp); 
    temp = other;
   }
  printf("score: %i", score);
  nrf_delay_ms(30);
  new_game();
}
moving();
if (apple_eaten){
  new_apple();
}
app_timer_init(); // this needs to be moved
app_timer_create(&timer1, APP_TIMER_MODE_REPEATED, draw_board);
app_timer_start(timer1, 32768/500, NULL);
int heart_beat_val = 75; // this needs to be replaced by the actual heart beat thing
nrf_delay_ms(1000/heart_beat_val);
}
}
