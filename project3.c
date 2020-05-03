#include<stdio.h>
#define MAX = 8; //CPU scheduler can run up to 8 execution elements.

#define TRUE = 1;
#define FALSE = 0;

typdef struct process {
	int pid;			//process id
	int priority;			//priority level of the process
	int arrTime;			//arrival time
	int compTime;			//completion time
	int cpuBurst;			//burst time
	int waitTime;			//waiting time
	int respTime;			//response time
	int taTime;			//turnaround time
	int cpuBurstLeft;
}process;

int firstFit(int blockSize[], int m, int processSize[], int n)
{
	int allocation[n];

	memset(allocation, -1, sizeof(allocation));

	for(int i = 0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if (blockSize[j] >= processSiize[i])
			{
				allocation[i] = j;

				blockSize[j] -= processSize[i];

				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (allocation[i] != -1) 
		{
			allocation[i]++;
			return 1;
		}
		else return 0;			//returns 0 because the process was not allocated.
	}
}

void buddy()
{

}

void roundRobin(int timeQuantum)
{
	
}


int main()
{
	process myProcesses[MAX];
	int q; 						//quantum
	int p;						//number of concurrent pocesses
	int N;						//the total possible space
	char algo[8];				//a string to represent the allocation algorithm


}
