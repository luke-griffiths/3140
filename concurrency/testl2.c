#include "3140_concur.h"
#include "utils.h"
#include "lock.h"

/*This test case tests to make sure that the order in which the locks are added to the queue and removed from the queue are correct. Initially,
 * p1 locks both locks, and then when p2 tries to grab the second lock it is added to the queue. When p3 tries to grab the first lock it is added
 * to the first locks queue. The green LED proceeds to flash two times, then unlocks the second lock, then the first lock. When the second lock
 * is unlocked, p2 grabs the second lock because it is the first in the queue, and tries to grab the first lock but is blocked, and then is
 * added to the blocked queue for the first lock behind p3. Then whenever the first lock is unlocked, p3 which is first in the queue grabs the
 * lock and then flashes the red LED, and once it releases the lock then p2 can operate. Correct functionality is shown when p3 executes the red
 * LED flash before p2 does a green flash. */

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
	l_unlock(&l2);
	l_unlock(&l1);
}


void p2(void){
	l_lock(&l2);
	l_lock(&l1);
	delay();
	delay();
	LEDGreen_Toggle();
	delay();
	LEDGreen_Toggle();
	delay();
	l_unlock(&l2);
	l_unlock(&l1);

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
	LED_Initialize();

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
