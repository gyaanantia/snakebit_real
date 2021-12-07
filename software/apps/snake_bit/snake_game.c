
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "app_timer.h"
#include "microbit_v2.h"

APP_TIMER_DEF(timer1);

typedef uint_8_t score, apple_x, apple_y, direction;
typedef bool apple_eaten, lost;

typedef struct Node{
  uint_8_t x, y;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node* head;
typedef struct Node* tail;

//typedef struct {
//  Node* head;
  ///Node* tail;
//} List;

void cur_direction(){
  if( direction == 1 | direction == 2 | direction ==0){
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
   Node* temp =  tail;
    tail =  tail->prev;
   free(temp);// last element in list
 }
}


void new_apple(){
  apple_x = rand()%65;
  apple_y = rand()%33;
  while(apple_x== head->x && apple_y== head->y){
    apple_x = rand()%65;
    apple_y = rand()%33;
  }
  apple_eaten = false;
}

void apple_eaten(head, apple){
  if(head.x == apple_x && head.y == apple_y){
    score ++;
     apple_eaten = true;
  }
}

void lost(){
if(head->y <= 0 ||  head->y >=31){
   lost = true;
}
if(head->x<=0 ||  head->y>= 63){
   lost = true;
}
 Node* temp = head->next;
 while(temp!= tail ){
    if head->x == temp->x {
      if( head->y == temp->y){
     lost = true;
  }
  }
  temp = temp->next;
}
}
void new_game(){
  apple_x = rand()%65;
  apple_y = rand()%33;
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
  one->y = 13;
  two->x = 32;
  two->y = 14;
  three->x = 32;
  three->y = 15;
  four->x = 32;
  four->y = 16;
  five->x = 32;
  five->y = 17;

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
  apple_eaten = false;
  loss = false;


}
void draw_board(){
  struct Node* temp = head->next;
  while(temp!= tail ){
    draw(temp->x, temp->y); // need the draw function
    temp = temp -> next;
 }
 draw(apple_x, apple_y); //

}

void main(){
  new_game();
  app_
  while(1){
  if( !gpio_read(14) | !gpio_read(23)){ // can maybe replace this with an interupt
  cur_direction();
  }
  lost();
  apple_eaten();
  if(lost){
  printf("score: %i", score);
  delay 20;
  new_game();
}
moving();
if (apple_eaten()){
  new_apple();
}
app_timer_init(); // this has to go somewhere else probably in the baord init or something
app_timer_create(&timer1, APP_TIMER_MODE_REPEATED, draw_board);
app_timer_start(my_timer_1, 32768/500, NULL);
int heart_beat_val = 75;
delay 1000/heart_beat_val; // this is def wrong but we'll get back to this
}
}
