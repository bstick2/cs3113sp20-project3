#include<stdio.h>
#define MAX = 8; //CPU scheduler can run up to 8 execution elements.

#define TRUE = 1;
#define FALSE = 0;


typedef struct LinkedList {
	char* pid;
	int size;
	int beg;
	struct LinkedList *pointer;
}
	

typdef struct process {
	int pid;				//process id
	int priority;			
	int arrTime;			//arrival time
	int compTime;			//completion time
	int cpuBurst;			//burst time
	int waitTime;			//waiting time
	int respTime;			//response time
	int taTime;				//turnaround time
	int cpuBurstLeft;
}process;

int firstFit(struct LinkedList** list, char* pid, int process_size, int total_size, int flag)
{
	struct LinkedList* emptylink = (struct LinkedList*) malloc(sizeof(struct LinkedList)) ;
	struct LinkedList * end = *list;

	emptylink->size = process_size;
	emptylink->beg = 0;
	emptylink->pid = pid;
	emptylink->pointer = NULL;

	if (*list == NULL){ 
		*list = emptylink;
		struct LinkedList* na = (struct LinkedList*) malloc(sizeof(struct LinkedList));
		
		emptylink->pointer = na;
		na->pid = "na";
		na->size = total_size - process_size;
		na->beg = process_size;

		printf("ALLOCATED %s %d\n", pid, end->size);
		return flag;
	}
	else {
		while(end->pointer != NULL){
			if (strcmp(end->pid, "na") == 0) {
				if(process_size < end->size){
					end->pid = pid;
					emptylink->size = end->size - process_size;
					end->size = process_size;
					emptylink->pid = "na";
					emptylink->beg = end->size + end->beg; 
					end->pointer = emptylink;

					printf("ALLOCATED %s %d\n", pid, end->beg);
					return flag;
				}
			}
			end = end->pointer;
		}
	}
}

void buddy(){

}

void roundRobin(int timeQuantum){
	
}


int main(int argc, char** argv){
	process myProcesses[MAX];
	int q; 						//quantum
	int p;						//number of concurrent pocesses
	int N;						//the total possible space
	char algo[9];				//a string to represent the allocation algorithm
	char line[256];
	char* instruction;
	int size;
	char* pid;
	int flag;

	FILE* in = fopen(file, "r"); 
	while(fgets(line, 256 * sizeof(char), in) != NULL){
		if (strncmp(line, "#", 1) != 0){
			instruction = (char*) malloc(12*sizeof(char));
			pid = (char*) malloc(12*sizeof(char));
			if (strncmp(line, "REQUEST", 7) == 0){
				sscanf(line,"%s %s %d\n", instruction, pid, &size);
				flag = firstFit(&linkedList, pid, size, N, flag);
			}
			else
			{
				sscanf(line, "%s %s\n", instruction, pid);
				if (strncmp(instruction, "RELEASE", 7) == 0){
					//call release
				}
				else if(strncmp(instruction, "LIST", 7) == 0){
					//call list
				}
				else if(str)
			}
		}
		
	}


}