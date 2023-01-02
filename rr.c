#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
} process;

int search(process *processes, int n, int pid) {
	for (int i = 0; i < n; i++) {
		if (processes[i].pid == pid)
			return i;
	}
	
	return -1;
}

process *rotate(process *processes, int n) {
	process temp = processes[0];
	int k = 0;

	for (int i = 0; i < n - 1; i++) {
		processes[i] = processes[i + 1];
	}

	processes[n - 1] = temp;

	return processes;
}

process *add(process *processes, int n, process element) {
	process* temp = malloc((n + 1) * sizeof(process));

	for (int i = 0; i < n; i++)
		temp[i] = processes[i];
	
	temp[n] = element;
	processes = realloc(processes, (n + 1) * sizeof(process));

	for (int i = 0; i < n + 1; i++)
		processes[i] = temp[i];
	
	free(temp);
	return processes;
}

process *delete(process *processes, int n, process element) {
	int index = search(processes, n, element.pid);

	if (n - 1 == 0)
		return NULL;

	if (index == -1)
		return processes;

	for (int i = index; i < n - 1; i++)
		processes[i] = processes[i + 1];

	processes = realloc(processes, (n - 1) * sizeof(process));

	return processes;
}

void execute_rr(process *processes, int n, int quantum) {
	int time;
	int finished_processes = 0;
	int m = n;
	int current_time = processes[0].arrival_time;
	process *queue = NULL;
	int index = 0;
	int size = 0;
	int current_pid;
	char hasToRotate = 0;
	
	while (finished_processes < m && n > 0) {
		// find processes than have arrived until the current time
		int counter = 0;
		while (size < n && processes[counter].arrival_time <= current_time && counter < n) {
			if (search(queue, size, processes[counter].pid) == -1 && processes[counter].burst_time > 0) {
				// add new process at the end of the queue
				queue = add(queue, size++, processes[counter]);
			}
			counter++;
		}

		if (hasToRotate)
			rotate(queue, size);

		// select the first process in the queue
		if (queue[index].burst_time <= quantum) {
			current_pid = queue[index].pid;
			time = queue[index].burst_time;

			// remove the process from the queue
			processes = delete(processes, n--, queue[index]);
			queue = delete(queue, size--, queue[index]);
			hasToRotate = 0;
		} else {
			current_pid = queue[index].pid;
			time = quantum;
			queue[index].burst_time -= quantum;
			hasToRotate = 1;
		}

		for (int i = 0; i < time; i++) {
			printf("%d\n", current_pid);
		}

		current_time += time;
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
	
	execute_rr(arr, n, quantum);
	free(arr);

	return 0; /* DO NOT EDIT THIS LINE */
}
