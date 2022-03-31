
/**
 * Initializes the lock structure
 *
 * @param l pointer to lock to be initialized
 */
#include "lock.h"

//Helper function to pop the front process off of the lock queue
process_t * l_pop_front_process(lock_t *l) {
	if (!l->lockQueue) return NULL;	//If no queue exists, return null
	process_t *proc = l->lockQueue;	//Gets the front process in the queue
	l->lockQueue = proc->next;		//Moves first element to the next element
	proc->next = NULL;				//Removes proc from the queue
	return proc;
}

void l_enqueue(process_t* newProc, lock_t* l){
	if (l->lockQueue == NULL) {	//If there is no queue, make the process the first element in the queue
		l->lockQueue = newProc;
	}
	else{
		process_t *temp = l->lockQueue; //Sets temp to the first element
		while (temp->next != NULL) {
			temp = temp->next; 			// while there are more elements in the list, iterates to the last element
		}
		temp->next = newProc; 			//add process to the end of the list
		newProc->next = NULL;
	}
}

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
	//if lock is not locked, then grab the lock
	if (!l->isLocked){
		l->isLocked = 1;
	}
	else{
		//set current process to be blocked.
		current_process->process_blocked = 1;
		//add process to lock queue and call process_blocked
		l_enqueue(current_process, l);
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
	if(l->lockQueue == NULL)
		l->isLocked = 0;
	else{
		//remove the first process from the queue
		process_t* removed = l_pop_front_process(l);
		//set the process as not blocked, and add to end of the process queue
		removed->process_blocked = 0;
		//push_tail_process(removed);
		push_tail_process(removed);
	}
	//re-enable interrupts
	PIT->CHANNEL[0].TCTRL = 3;

}

