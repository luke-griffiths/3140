#ifndef __SHARED_STRUCTS_H__
#define __SHARED_STRUCTS_H__

/** Implement your structs here */

/**
 * This structure holds the process structure information
 */

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
