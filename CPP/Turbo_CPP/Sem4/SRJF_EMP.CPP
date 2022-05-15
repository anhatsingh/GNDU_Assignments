/*
Name        -> Shortest Remaining Job First (Pre-emptive) Algorithm
Author      -> Anhat Singh
Tested on   -> Turbo C++
Date        -> 13th May, 2022
Assumptions -> User inputs Process Name, Arrival Time and Burst Time
*/
#include <iostream.h>
#include <conio.h>
#define MAX 10

/* declare the struct that will hold the data of a process */
struct Process{
    char p_name;                    // This will store process name
    int arrival_time;               // This will store the arrival time of the process
    int burst_time;                 // This will store the burst time of the process

    int wait_time;                  // This will store the wait_time of a process
    int turn_around_time;           // This will store the turn_around_time of a process
    int time_remaining;             // This will store the time remaining for which the process is to be executed
    int exit_time;                  // This will store the time the process completed execution.
};

/* declare function prototypes used within this code */
void schedule(Process [], int, int);
void print_array(Process [], int);

int main(){
    clrscr();
    cout << "Shortest Remaining Job First (Pre-emptive)" << endl;
    /* declare array that will hold the processes */
    Process arr[MAX];
    int total_burst_time = 0;

    /* get the number of processes to schedule */
    int size;
    cout << "Enter Number of Processes to Schedule: ";
    cin >> size;

    /* get the Processes' information */
    for(int i = 0; i < size; i++){
        cout << "Enter Process ID, Arrival Time, Burst Time (space-separated): ";
        cin >> arr[i].p_name >> arr[i].arrival_time >> arr[i].burst_time;
        total_burst_time += arr[i].burst_time;

        arr[i].time_remaining = arr[i].burst_time;
        arr[i].exit_time = 0;
    }

    /* schedule the processes */
    schedule(arr, size, total_burst_time);
    /* print the array */
    print_array(arr, size);
    getch();
    return 0;
}

void schedule(Process arr [], int size, int total_burst_time){
    /* sort based on arrival time */
    for(int i = 0; i<size; i++){
        for(int j = i+1; j<size; j++){
            // apply bubble sort
            if (arr[i].arrival_time > arr[j].arrival_time || (arr[i].arrival_time == arr[j].arrival_time && arr[i].burst_time > arr[j].burst_time)){
		Process temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	    }
	}
    }

    int time_elapsed = 0;               // This will store the time that has passed.
    int CPU_processing_time = 0;        // This will store the time the CPU is actually doing work and not sitting idle.
    int is_CPU_idle = 1;                // This will store whether the CPU is sitting idle or processing something.
    Process* current_process = &arr[0]; // This will store the current process being executed in the CPU.

    /* Iterate until all the processes are executed */
    while(CPU_processing_time < total_burst_time){

	/* check if there is no process to execute, and CPU is sitting idle */
	is_CPU_idle = 1;
	for(int b=0; b<size;b++){
	    if (arr[b].arrival_time <= time_elapsed && arr[b].time_remaining > 0){
		// There exists a process that has arrived and has time remaining to be processed
		is_CPU_idle = 0;
		break;
	    }
	}
	if (is_CPU_idle){
	    /* If cpu is idle, increment time and continue to next iteration */
	    time_elapsed++;
	    continue;
	}


        /* If CPU is not idle, execute the process */
        /* check if there is any process having time remaining less than current process */
	for(int i = 0; i<size; i++){
	    if (arr[i].arrival_time <= time_elapsed){ // This ensures process who are not yet arrived are not executed.
		if(current_process->p_name != arr[i].p_name){   // This ensures we are not comparing the process with itself.
                    if(arr[i].time_remaining > 0){    // This ensures that we do not pre-empt to a process that has finished executing.
                        if(arr[i].time_remaining < current_process->time_remaining || current_process->time_remaining <=0){ // compare remaining time of both the processes.
                            // If current process has time remaining 0 or less than the next one, pre-empt it.
                            current_process = &arr[i];
                        }
                    }
                }
            }
        }
        /* Decrease the time remaining of current process by 1. */
        if (current_process->arrival_time <= time_elapsed) current_process->time_remaining -= 1;
        /* Increase time elapsed by 1 */
        time_elapsed++;
        CPU_processing_time++;

        /* If the process has finished execution, note down its time. */
        if (current_process->time_remaining <= 0 && current_process->exit_time == 0){
            current_process->exit_time = time_elapsed;
        }
    }
}


void print_array(Process arr [], int size){
    int total_wait = 0;
    int total_tat = 0;
        
    /* calculate turn around time */
    for(int j = 0; j<size; j++){        
        arr[j].turn_around_time = arr[j].exit_time - arr[j].arrival_time;
        total_tat += arr[j].turn_around_time;        
    }

    /* calculate wait time */
    for(int i = 0; i<size; i++){        
        arr[i].wait_time = arr[i].turn_around_time - arr[i].burst_time;
        total_wait += arr[i].wait_time;        
    }
    
    /* print finl information */
    cout << "Process ID \t Arrival Time \t Burst Time \t Wait Time \t Turnaround_Time" << endl;
    for(int k=0; k<size;k++){
        cout<< arr[k].p_name << "\t\t"
            << arr[k].arrival_time << "\t\t"
            << arr[k].burst_time << "\t\t"
            << arr[k].wait_time << "\t\t"
            << arr[k].turn_around_time
            << endl;
    }
    cout<< "Average Wait Time = " << (float) total_wait/size << endl
        << "Average Turn Around Time = " << (float) total_tat/size << endl;
}