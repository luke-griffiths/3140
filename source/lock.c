
/**
 * Initializes the lock structure
 *
 * @param l pointer to lock to be initialised
 */
#include "lock.h"

void l_init(lock_t* l){
	//set lock to unlocked, initialize the lock queue
	l->isLocked = 0;
	l->lockQueue = NULL;
}

/**
 * Grab the lock or block the process until lock is available
 *
 * @param l pointer to lock to be grabbed
 */
void l_lock(lock_t* l){
	//disable interrupts
	PIT->CHANNEL[0].TCTRL = 1;
	//if isLocked false, then grab the lock, else call process_blocked
	if (!l->isLocked){
		l->isLocked = 1;
	}
	else{
		//set current process to be blocked.
		current_process->process_blocked = 1;
		//add process to blocked queue and call process_blocked
		enqueue(current_process, &(l->lockQueue));
		process_blocked();
	}
	//re-enable interrupts
	PIT->CHANNEL[0].TCTRL = 3;

}

/**
 * Release the lock along with the first process that may be waiting on
 * the lock. This ensures fairness wrt lock acquisition.
 *
 * @param l pointer to lock to be unlocked
 */
void l_unlock(lock_t* l){
	//disable interrupts
	PIT->CHANNEL[0].TCTRL = 1;
	//lock is unlocked
	l->isLocked = 0;
	//if there is a queue
	if(l->lockQueue != NULL){
		//remove the first process from the queue
		process_t* removed = dequeue(&(l->lockQueue));
		//set the process as not blocked, and add to end of the process queue
		removed->process_blocked = 0;
		//push_tail_process(removed);
		enqueue(removed, &process_queue);
	}
	//re-enable interrupts
	PIT->CHANNEL[0].TCTRL = 3;

}

