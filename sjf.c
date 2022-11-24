#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;

	char selected;
} process;

void copy_process(process *a, process *b) {
	a->pid = b->pid;
	a->arrival_time = b->arrival_time;
	a->burst_time = b->burst_time;
	a->selected = b->selected;
}

void merge(process *processes, int n, int left, int middle, int right) {
	int left_size = middle + 1 - left;
	int right_size = right - middle;
	process left_subset[left_size];
	process right_subset[right_size];

	for (int i = 0; i < left_size; i++) {
		left_subset[i] = processes[left + i];
	}

	for (int i = 0; i < right_size; i++) {
		right_subset[i] = processes[middle + 1 + i];
	}

	int left_index = 0;
	int right_index = 0;
	int merged_index = left;
	while (left_index < left_size && right_index < right_size) {
		if (left_subset[left_index].arrival_time <= right_subset[right_index].arrival_time)
			copy_process(&processes[merged_index], &left_subset[left_index++]);
		else
			copy_process(&processes[merged_index], &right_subset[right_index++]);
		merged_index++;
	}

	while (left_index < left_size) {
		processes[merged_index++] = left_subset[left_index++];
	}

	while (right_index < right_size) {
		processes[merged_index++] = right_subset[right_index++];
	}
}

void merge_sort(process *processes, int n, int left, int right) {
	if (left >= right)
		return;
	
	int middle = (left + right) / 2;
	merge_sort(processes, n, left, middle);
	merge_sort(processes, n, middle + 1, right);
	merge(processes, n, left, middle, right);
}

void execute_sjf(process *processes, int n) {
	for (int i = 0; i < n - 1; i++) {
		processes[i].selected = 0;
	}

	merge_sort(processes, n, 0, n - 1);
	process *queue = malloc(n * sizeof(process));
	process current_process;
	int next_process_id = 0;
	int current_time = 0;
	int counter = 0;

	processes[0].selected = 1;
	copy_process(&current_process, &processes[0]);
	while (counter < n) {
		copy_process(&queue[counter], &current_process);
		current_time += current_process.burst_time;

		int arrived_processes = 0;
		while (arrived_processes < n && processes[arrived_processes].arrival_time <= current_time) arrived_processes++;

		int i = 0;
		next_process_id = 0;
		for (i; i < arrived_processes; i++) {
			if (processes[i].selected == 0) {
				next_process_id = i;
				break;
			}
		}

		for (i + 1; i < arrived_processes; i++) {
			if (processes[i].burst_time < processes[next_process_id].burst_time && processes[i].selected == 0){
				next_process_id = i;
			}
		}

		processes[next_process_id].selected = 1;
		copy_process(&current_process, &processes[next_process_id]);
		counter++;
	}
	
	for (int i = 0; i < n; i++) {
		process temp_process = processes[i];
		processes[i] = queue[i];
		queue[i] = temp_process;
	}

	free(queue);
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

	printf("Process =============== Start time - End time===\n");
	int current_time = arr[0].arrival_time;
	for (int i = 0; i < n; i++) {
		printf("P%d				%d - %d\n", arr[i].pid, current_time, current_time + arr[i].burst_time);
		current_time += arr[i].burst_time;
	}

	free(arr);

	return 0; /* DO NOT EDIT THIS LINE */
}
