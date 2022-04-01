#include "3140_concur.h"
#include "utils.h"
#include "lock.h"

//This test case tests for deadlock. p1 locks l1, and then p2 locks l2, and they both get stuck waiting for eachother to unlock.
//Correct functionality is when the red LED flashes 2 times and then the green LED turns on at then end, without any green flashes.

lock_t l1;
lock_t l2;

void p1(void){
	l_lock(&l1);
	delay();
	LEDRed_Toggle();
	delay();
	delay();
	LEDRed_Toggle();
	delay();
	l_lock(&l2);
	LEDGreen_Toggle();
	delay();
	LEDGreen_Toggle();
	delay();
	l_lock(&l1);
	l_lock(&l2);
}


void p2(void){
	l_lock(&l2);
	delay();
	delay();
	LEDRed_Toggle();
	delay();
	delay();
	delay();
	LEDRed_Toggle();
	delay();
	l_lock(&l1);
	LEDGreen_Toggle();
	delay();
	LEDGreen_Toggle();
	delay();
	l_lock(&l2);
	l_lock(&l1);
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

	process_start();
	LEDGreen_On();

	while(1);
	return 0;
}
