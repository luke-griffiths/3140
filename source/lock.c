/*
 * lock.c
 *
 *  Created on: Mar 28, 2022
 *      Author: lukegriffiths
 */


/**
 * Initialises the lock structure
 *
 * @param l pointer to lock to be initialised
 */
#include "lock.h"

void l_init(lock_t* l){
	//code here
}

/**
 * Grab the lock or block the process until lock is available
 *
 * @param l pointer to lock to be grabbed
 */
void l_lock(lock_t* l){
	//code here
}

/**
 * Release the lock along with the first process that may be waiting on
 * the lock. This ensures fairness wrt lock acquisition.
 *
 * @param l pointer to lock to be unlocked
 */
void l_unlock(lock_t* l){
	//code here
}
