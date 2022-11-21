#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;

	int start_time;	// time when the process starts executing
	int end_time;	// time when the process ends executing
} process;

// implementation of the fcfs algorithm
void execute_fcfs(process *processes, int n) {
	if (n <= 0)
		return;

	processes[0].start_time = 0;
	processes[0].end_time = processes[0].burst_time;
	
	for (int i = 1; i < n; i++) {
		processes[i].start_time = processes[i - 1].end_time;
		processes[i].end_time = processes[i].start_time + processes[i].burst_time;
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

	execute_fcfs(arr, n);
	printf("Process =============== Start time - End time\n");
	for (int i = 0; i < n; i++) {
		printf("P%d								%d - %d\n", i + 1, arr[i].start_time, arr[i].end_time);
	}

	return 0; /* DO NOT EDIT THIS LINE */
}
