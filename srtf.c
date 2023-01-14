#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
	int remaining_time;
} process;

void execute_srtf(process *processes, int n) {
	int finished_processes = 0;
	int current_time = 0;
	char check = 0;
	int minimum_index;		// index of the process with the minimum burst time
	int counter = 0;

	for (int i = 0; i < n; i++) {
		processes[i].remaining_time = processes[i].burst_time;
	}

	while (finished_processes < n) {
		minimum_index = 0;
		counter = 0;
		while (processes[minimum_index].remaining_time == 0 && counter++ < n) minimum_index++;
		
		// find the unfinished process that has arrived until the current time
		// with the smallest remaining time
		for (int i = 0; i < n; i++) {
			if (processes[i].arrival_time <= current_time && processes[i].remaining_time < processes[minimum_index].remaining_time 
				&& processes[i].remaining_time > 0) {
				minimum_index = i;
			}
		}

		// execute the process for one time unit
		printf("%d\n", processes[minimum_index].pid);
		processes[minimum_index].remaining_time--;

		if (processes[minimum_index].remaining_time == 0) {
			finished_processes++;
		}

		current_time++;
	}
}


int main() {

	/* read in data - DO NOT EDIT (START) */
	int n;
	int quantum;
	scanf("%d", &n);
	scanf("%d", &quantum);
	process *arr;
	arr = malloc(n * sizeof(process));
	for (int i = 0; i < n ; ++i) {
		scanf("%d", &arr[i].pid);
		scanf("%d", &arr[i].arrival_time);
		scanf("%d", &arr[i].burst_time);
	}
	/* read in data - DO NOT EDIT (END) */

	execute_srtf(arr, n);
	free(arr);

	return 0; /* DO NOT EDIT THIS LINE */
}
