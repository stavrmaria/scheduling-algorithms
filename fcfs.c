#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;

	int waiting_time;
	int turnaround_time;
} process;

void calculate_times(process *processes, int n) {
	processes[0].waiting_time = 0;
	processes[0].turnaround_time = processes[0].burst_time;

	for (int i = 1; i < n; i++) {
		processes[i].waiting_time = processes[i - 1].burst_time + processes[i - 1].waiting_time;
		processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
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

	int process_index = 0;
	int current_time = arr[0].arrival_time;

	calculate_times(arr, n);
	while (process_index < n) {
		printf("%d\n", arr[process_index].pid);

		if (current_time >= arr[process_index].turnaround_time - 1)
			process_index++;

		current_time++;
	}
	

	free(arr);

	return 0; /* DO NOT EDIT THIS LINE */
}
