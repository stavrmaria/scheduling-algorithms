#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;

	int start_time;
	int end_time;
} process;

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

	int current_time = arr[0].arrival_time;
	printf("Process =============== Start time - End time===\n");
	for (int i = 0; i < n; i++) {
		printf("P%d				%d - %d\n", arr[i].pid, current_time, current_time + arr[i].burst_time);
		current_time += arr[i].burst_time;
	}

	free(arr);

	return 0; /* DO NOT EDIT THIS LINE */
}
