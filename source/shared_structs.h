#ifndef __SHARED_STRUCTS_H__
#define __SHARED_STRUCTS_H__

/** Implement your structs here */

/**
 * This structure holds the process structure information
 */
/*struct process_state {	//Creating Process State Structure
	unsigned int *originalSP;
	unsigned int *currentSP;
	int size;
	struct process_state* nextProcess;
	int process_blocked;
};*/

typedef struct process_state {

	unsigned int *sp;

	unsigned int *orig_sp;

	int n;

	struct process_state *next;

	int process_blocked;


} process_t;

/**
 * This defines the lock structure
 */
typedef struct lock_state {
	int isLocked;
	struct process_state* lockQueue;
} lock_t;

/**
 * This defines the conditional variable structure
 */
typedef struct cond_var {

} cond_t;

#endif
