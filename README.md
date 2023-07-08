# Scheduling algorithms
Implementation of scheduling algorithms in operating systems in C.

## Preemptive Scheduling
Preemptive Scheduling involves assigning tasks with their respective priorities. In certain cases, it becomes crucial to execute a task of higher priority before a lower priority task, even if the lower priority task is currently in progress. The lower priority task temporarily pauses its execution and resumes once the higher priority task completes.
Non-Preemptive Scheduling

## Non-Preemptive Scheduling
In Non-Preemptive Scheduling, the CPU is dedicated to a specific process. The process that occupies the CPU will release it either by switching contexts or terminating. This scheduling method is versatile and can be used on various hardware platforms without requiring special hardware, such as a timer, as is the case with preemptive scheduling.

## Scheduling Terminologies
- Burst Time/Execution Time: It is a time required by the process to complete execution. It is also called running time.
- Arrival Time: when a process enters in a ready state
- Finish Time: when process complete and exit from a system
- Process: It is the reference that is used for both job and user.
- CPU/IO burst cycle: Characterizes process execution, which alternates between CPU and I/O activity.

## Execution
To complile each .c file run
```console
make [file]
```
To complile all .c files just run
```console
make
```
To execute an algorithm for a specific test case run
```console
./[algorithm] | tests/INPUT[index]
```
To test the algorithms for all the available tests (/tests subfolder)
```console
make tests
```
Input format
```
number-of-processes(N)
quantum
process-index0 arrival-time0 burst-time0
process-index1 arrival-time1 burst-time1
...
process-indexN-1 arrival-timeN-1 burst-timeN-1
```