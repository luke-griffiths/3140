#include "3140_concur.h"
#include "utils.h"
#include "lock.h"

/* This test case tests for deadlock. p1 grabs the lock l1, and p2 grabs the lock l2, and they each try to grab the second lock, but are
 * added to that lock's block queue. Since they are both waiting for each other to release the lock deadlock occurs. Correct functionality
 * is when the red LED flashes 2 times and then the green LED turns on at then end, without any green flashes because the program cannot get
 * to that part due to deadlock.*/

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
	l_unlock(&l1);
	l_unlock(&l2);
}


void p2(void){
	l_lock(&l2);
	delay();
	delay();
	LEDRed_Toggle();
	delay();
	delay();
	LEDRed_Toggle();
	delay();
	l_lock(&l1);
	LEDGreen_Toggle();
	delay();
	LEDGreen_Toggle();
	delay();
	l_unlock(&l2);
	l_unlock(&l1);
}

int main(void){
	LED_Initialize();

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
