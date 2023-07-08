#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
} process;

void execute_sjf(process *processes, int n) {
	int finished_processes = 0;
	int current_time = 0;
	int minimum_index;		// index of the process with the minimum burst time
	int counter = 0;

	while (finished_processes < n) {
		// find the index of the first unfinished process
		minimum_index = 0;
		counter = 0;
		while (processes[minimum_index].burst_time == 0 && counter++ < n) minimum_index++;
		
		// find the unfinished process that has arrived until the current time
		// with the smallest burst time
		for (int i = 0; i < n; i++) {
			if (processes[i].arrival_time <= current_time && processes[i].burst_time < processes[minimum_index].burst_time
				&& processes[i].burst_time > 0) {
				minimum_index = i;
			}
		}

		// execute the process
		while (processes[minimum_index].burst_time != 0) {
			current_time++;
			printf("%d\n", processes[minimum_index].pid);
			processes[minimum_index].burst_time--;
		}
		
		finished_processes++;
	}
}


int main() {
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

	execute_sjf(arr, n);
	free(arr);
	return 0;
}
