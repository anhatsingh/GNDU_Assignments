/*
Name        -> Shortest Remaining Job First (Non pre-emptive) Algorithm
Author      -> Anhat Singh
Tested on   -> Turbo C++
Date        -> 13th May, 2022
Assumptions -> User inputs Process Name and Burst Time
*/
#include <iostream.h>
#include <conio.h>
#define MAX 10

/* declare the struct that will hold the data of a process */
struct Process{
    char p_name;
    int burst_time;

    int wait_time;
    int turn_around_time;
    int time_remaining;
    int exit_time;
};

/* declare function prototypes used within this code */
void schedule(Process [], int, int);
void print_array(Process [], int);

int main(){
    clrscr();
    cout << "Shortest Remaining Job First (Non pre-emptive)" << endl;

    /* declare array that will hold the processes */
    Process arr[MAX];
    int total_burst_time = 0;

    /* get the number of processes to schedule */
    int size;
    cout << "Enter Number of Processes to Schedule: ";
    cin >> size;

    /* get the Processes' information */
    for(int i = 0; i < size; i++){
        cout << "Enter Process ID, Burst Time (space-separated): ";
        cin >> arr[i].p_name >> arr[i].burst_time;
        total_burst_time += arr[i].burst_time;
        arr[i].time_remaining = arr[i].burst_time;
    }

    /* schedule the processes */
    schedule(arr, size, total_burst_time);
    /* print the array */
    print_array(arr, size);
    getch();
    return 0;
}



void schedule(Process arr [], int size, int total_burst_time){    
    int time_elapsed = 0;               // This will store the time that has passed.
    Process* current_process = &arr[0]; // This will store the current process being executed in the CPU.

    /* Iterate until all the processes are executed */
    while(time_elapsed < total_burst_time){
        
        /* check if there is any process having time remaining less than current process */
        for(int i = 0; i<size; i++){            
            if(arr[i].time_remaining > 0){    // This ensures that we do not execute a process that has finished executing.                        
                if(arr[i].burst_time < current_process->burst_time || current_process->time_remaining == 0){ // find the minimum burst time array
                    current_process = &arr[i];
                }
            }            
        }

        /* Increase time elapsed by burst time */
        time_elapsed += current_process->burst_time;
        current_process->time_remaining = 0;
        /* Note the exit time */
        current_process->exit_time = time_elapsed;
    }
}


void print_array(Process arr [], int size){
    int total_wait = 0;
    int total_tat = 0;
    
    /* calculate turn around time */
    for(int j = 0; j<size; j++){        
        arr[j].turn_around_time = arr[j].exit_time;
        total_tat += arr[j].turn_around_time;        
    }

    /* calculate wait time */
    for(int i = 0; i<size; i++){        
        arr[i].wait_time = arr[i].turn_around_time - arr[i].burst_time;
        total_wait += arr[i].wait_time;
    }


    /* print finl information */
    cout << "Process ID \t Burst Time \t Wait Time \t Turnaround_Time" << endl;
    for(int k=0; k<size;k++){
        cout<< arr[k].p_name << "\t\t"
            << arr[k].burst_time << "\t\t"
            << arr[k].wait_time << "\t\t"
            << arr[k].turn_around_time
            << endl;
    }

    cout<< "Average Wait Time = " << (float) total_wait/size << endl
        << "Average Turn Around Time = " << (float) total_tat/size << endl;
}