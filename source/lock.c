
/**
 * Initialises the lock structure
 *
 * @param l pointer to lock to be initialised
 */
#include "lock.h"

void l_init(lock_t* l){
	//code here
	l->isLocked = 0;
}

/**
 * Grab the lock or block the process until lock is available
 *
 * @param l pointer to lock to be grabbed
 */
void l_lock(lock_t* l){
	//code here
	//disable interrupts
	PIT->CHANNEL[0].TCTRL = 1;
	//if isLocked false, then grab it, else call process_blocked
	if (!l->isLocked){
		l->isLocked = 1;
	}
	else{
		process_blocked();
		enqueue(*l);

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

	l->isLocked = 0;
	l->lockQueue.dequeue();

	//re-enable interrupts
	PIT->CHANNEL[0].TCTRL = 3;

}
static process_t * dequeue() {

	if (!process_queue) return NULL;

	process_t *proc = process_queue;

	process_queue = proc->next;

	if (process_tail == proc) {

		process_tail = NULL;

	}

	proc->next = NULL;

	return proc;

}



static void enqueue(process_t *proc) {

	if (!process_queue) {

		process_queue = proc;

	}

	if (process_tail) {

		process_tail->next = proc;

	}

	process_tail = proc;

	proc->next = NULL;

}
