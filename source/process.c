#include "3140_concur.h"
#include <stdlib.h>
#include <MKL46Z4.h>
#include “shared_structs.h”


process_t *current_process = NULL;
process_t *process_queue = NULL;


void enqueue(process_t* proc){
	if (process_queue == NULL) {	//If no process_queue, start it with proc
		process_queue = proc;
		proc->nextProcess = NULL;
	}
	else {
		process_t *tmp = process_queue;	//Otherwise, go to the end and add it at the end.
		while (tmp->nextProcess != NULL) {
			tmp = tmp->nextProcess;
		}
		tmp->nextProcess = proc;
		proc->nextProcess = NULL;
	}
}

int dequeue(void){
	current_process = process_queue;	//dequeue the front node and return it
	process_queue = process_queue->nextProcess;
	current_process->nextProcess = NULL;
	return current_process->currentSP;
}

void process_free(process_t* proc) {	//Frees the process stacks and the linked list nodes
	process_stack_free(proc->originalSP, proc->size); //Frees process stacks
	free(proc); //Frees linked list nodes
}

int process_create (void (*f)(void), int n){
	unsigned int *sp = process_stack_init(f, n); //Allocates the stack.
	if (sp == NULL){
		return -1;		//return -1 because there is an error
	}
	process_t *proc_state = malloc(sizeof(process_t)); //Allocates memory for a process_t structure
	if (proc_state == NULL) {
		process_stack_free(sp, n);
		return -1;		//return -1 because there is an error
	}
	proc_state->currentSP = sp; //Setting proc_state's fields
	proc_state->originalSP = sp;
	proc_state->size = n;
	enqueue(proc_state);	//Adding proc_state to process_queue
	return 0;
}

void process_start (void){
	SIM->SCGC6 = SIM_SCGC6_PIT_MASK; // Enable clock to PIT module
	PIT->CHANNEL[0].LDVAL = 100000; //0x1000000; // Set load value of zeroth PIT
	PIT-> MCR = 0;// 0x00000; //turn on PIT Timer
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK; //Enable interrupts
	NVIC_EnableIRQ(PIT_IRQn); //Enable interrupt handler
	process_begin(); //Initiates the first process
}


unsigned int* process_select(unsigned int * cursp){
	//Storing the old process / making space for it
	if (process_queue == NULL) {			//If the queue is empty
		if(cursp == NULL){
			process_free(current_process); //Frees the process stacks and the linked list nodes
			return NULL;
		}
		else{
			current_process->currentSP = cursp; //Sets the current stack pointer
			return cursp;
		}
	}
	else{
		if(current_process != NULL){
			if(cursp == NULL){	//Frees memory
				process_free(current_process); //Frees the process stacks and the linked list nodes
			}
			else{	//Process hasn't terminated
				current_process->currentSP = cursp;
				enqueue(current_process);
			}
		}
	}
	dequeue(); //dequeue the front node
}






