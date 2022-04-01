#include "3140_concur.h"
#include "utils.h"
#include "lock.h"

//This test case tests to make sure that the order in which the locks are added to the queue and removed from the queue are correct.
//Since process 1 was created first, then 2, then 3, they run in that order. p1 locks both locks, and then when p2 tries to grab the
//second lock it is added to the queue. When p3 tries to grab the first lock it is added to the first locks queue. Since the first
//lock is unlocked before the second lock, p3 does its functionality before p2 does. Thus, correct functionality has 2 green LED flashes,
//then 1 red flash, then 1 green flash, then the green LED turns on and stays on.

lock_t l1;
lock_t l2;

void p1(void){
	l_lock(&l1);
	l_lock(&l2);
	delay();
	LEDGreen_Toggle();
	delay();
	LEDGreen_Toggle();
	delay();
	LEDGreen_Toggle();
	delay();
	LEDGreen_Toggle();
	delay();
	l_unlock(&l1);
	delay();
	l_unlock(&l2);
}


void p2(void){
	l_lock(&l2);
	delay();
	delay();
	LEDGreen_Toggle();
	delay();
	LEDGreen_Toggle();
	delay();
	l_unlock(&l2);
}

void p3(void){
	l_lock(&l1);
	delay();
	LEDRed_Toggle();
	delay();
	LEDRed_Toggle();
	delay();
	l_unlock(&l1);
}

int main(void){
	LED_Initialize();           /* Initialize the LEDs           */

	l_init (&l1);
	l_init (&l2);


	if (process_create (p1,20) < 0) {
	 	return -1;
	}
	if (process_create (p2,20) < 0) {
	 	return -1;
	}
	if (process_create (p3,20) < 0) {
	 	return -1;
	}

	process_start();
	LEDGreen_On();

	while(1);
	return 0;
}
