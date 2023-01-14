#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
} process;

// search & return the position of a process based on it's PID
int search(process *processes, int n, int pid) {
	for (int i = 0; i < n; i++) {
		if (processes[i].pid == pid)
			return i;
	}
	
	return -1;
}

// rotate the queue by shifting all it's 
// elements by once to the left
process *rotate(process *processes, int n) {
	process temp = processes[0];
	int k = 0;

	for (int i = 0; i < n - 1; i++) {
		processes[i] = processes[i + 1];
	}

	processes[n - 1] = temp;

	return processes;
}

// add a process in the end of array of processes
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

// remove 
process *delete(process *processes, int n, process element) {
	int index = search(processes, n, element.pid);

	// if the array is empty return NULL
	if (n - 1 == 0)
		return NULL;

	// if the is no such element return the original array
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
	int size = 0;			// size of the queue
	int current_pid;
	char hasToRotate = 0;	// checks whether the queue has to rotate or not
	
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
			// the process has a burst time less/equal to the quantum
			// remove the process from the queue

			current_pid = queue[index].pid;
			time = queue[index].burst_time;

			processes = delete(processes, n--, queue[index]);
			queue = delete(queue, size--, queue[index]);
			hasToRotate = 0;
		} else {
			// the process has a burst time greater than the quantum
			// it will be positioned to the end of the queue
			current_pid = queue[index].pid;
			time = quantum;
			queue[index].burst_time -= quantum;
			hasToRotate = 1;
		}

		// execute the process for the given time
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
