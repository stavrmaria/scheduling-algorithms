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
	int minimum_index;

	while (finished_processes < n) {
		minimum_index = 0;
		while (processes[minimum_index].burst_time == 0) minimum_index++;
		
		for (int i = 0; i < n; i++) {
			if (processes[i].arrival_time <= current_time && processes[i].burst_time < processes[minimum_index].burst_time
				&& processes[i].burst_time > 0) {
				minimum_index = i;
			}
		}


		while (processes[minimum_index].burst_time != 0) {
			current_time++;
			printf("%d\n", processes[minimum_index].pid);
			processes[minimum_index].burst_time--;
		}
		
		finished_processes++;
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

	execute_sjf(arr, n);

	free(arr);

	return 0; /* DO NOT EDIT THIS LINE */
}
