# Scheduling algorithms
Implementation of scheduling algorithms in operating systems in C.

## Preemptive Scheduling
In Preemptive Scheduling, the tasks are mostly assigned with their priorities. Sometimes it is important to run a task with a higher priority before another lower priority task, even if the lower priority task is still running. The lower priority task holds for some time and resumes when the higher priority task finishes its execution.

## Non-Preemptive Scheduling
In this type of scheduling method, the CPU has been allocated to a specific process. The process that keeps the CPU busy will release the CPU either by switching context or terminating. It is the only method that can be used for various hardware platforms. That’s because it doesn’t need special hardware (for example, a timer) like preemptive scheduling.

## Scheduling Terminologies
- Burst Time/Execution Time: It is a time required by the process to complete execution. It is also called running time.
- Arrival Time: when a process enters in a ready state
- Finish Time: when process complete and exit from a system
- Multiprogramming: A number of programs which can be present in memory at the same time.
- Jobs: It is a type of program without any kind of user interaction.
- User: It is a kind of program having user interaction.
- Process: It is the reference that is used for both job and user.
- CPU/IO burst cycle: Characterizes process execution, which alternates between CPU and I/O activity. CPU times are usually shorter than the time of I/O.

```mermaid
graph TD;
    CPU-Sheduling-->Preemitive;
    CPU-Sheduling-->Non-Preemitive;
    Preemitive-->Shortest-Remaining-Time-First;
    Preemitive-->Round-Robin;
    Non-Preemitive-->First-Come-First-Serve;
    Non-Preemitive-->Shortest-Job-First;
```

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

## Algorithms
### FCFS (First-Count-First-Serve)
FCFS is the simplest scheduling algorithm. FIFO simply queues processes in the order that they arrive in the ready queue. 
In this, the process that comes first will be executed first and next process starts only after the previous gets fully executed.

[Line endings in Makefile](https://stackoverflow.com/questions/5834014/lf-will-be-replaced-by-crlf-in-git-what-is-that-and-is-it-important)
