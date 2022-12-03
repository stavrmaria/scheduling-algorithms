#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;

	int waiting_time;
	int turnaround_time;
	int remaining_time;
} process;

void calculate_times(process *processes, int n) {
	processes[0].waiting_time = 0;
	processes[0].turnaround_time = processes[0].burst_time;
	processes[0].remaining_time = processes[0].burst_time;

	for (int i = 1; i < n; i++) {
		processes[i].waiting_time = processes[i - 1].burst_time + processes[i - 1].waiting_time;
		processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
		processes[i].remaining_time = processes[i].burst_time;
	}
}

void execute_fcfs(process *processes, int n, int quantum) {
	int index = 0;
	int next_index = 1;
	int time;
	int finished_processes = 0;
	int current_time = processes[0].arrival_time;
	char pending_process;

	calculate_times(processes, n);
	while (finished_processes < n) {
		pending_process = 1;

		if (processes[index].remaining_time > quantum) {
			processes[index].remaining_time -= quantum;
			current_time += quantum;
			time = quantum;
			next_index = index;
			next_index = (index + 1) % n;
		} else {
			current_time += processes[index].remaining_time;
			time = processes[index].remaining_time;
			processes[index].remaining_time = 0;
			finished_processes++;
			next_index = 0;
			while (processes[next_index].remaining_time == 0 && next_index < n) {
				next_index++;
			}
		}
		
		for (int i = 0; i < time; i++)
			printf("%d\n", processes[index].pid);

		index = next_index;
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
	
	execute_fcfs(arr, n, quantum);
	free(arr);

	return 0; /* DO NOT EDIT THIS LINE */
}
