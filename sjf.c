#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pid;
	int arrival_time;
	int burst_time;
} process;

void swap(process *a, process *b) {
	if (a == NULL || b == NULL)
		return;
	
	process *temp = malloc(sizeof(process));
	temp->pid = a->pid;
	temp->arrival_time = a->arrival_time;
	temp->burst_time= a->burst_time;

	a->pid = b->pid;
	a->arrival_time = b->arrival_time;
	a->burst_time = b->burst_time;

	b->pid = temp->pid;
	b->arrival_time = temp->arrival_time;
	b->burst_time = temp->burst_time;

	free(temp);
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


	free(arr);

	return 0; /* DO NOT EDIT THIS LINE */
}
