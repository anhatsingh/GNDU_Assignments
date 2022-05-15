/*
Name        -> Round Robin Algorithm with Arrival time
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
void schedule(Process [], int, int, int);
void print_array(Process [], int);

int main(){
    clrscr();
    cout << "Robin Round" << endl;

    /* declare array that will hold the processes */
    Process arr[MAX];
    int total_burst_time = 0;
    int time_quanta = 0;

    /* get the number of processes to schedule */
    int size;
    cout << "Enter Number of Processes to Schedule: ";
    cin >> size;

    /* get time quantum */
    cout << "Enter Time Quantum (in sec): ";
    cin >> time_quanta;

    /* get the Processes' information */
    for(int i = 0; i < size; i++){
        cout << "Enter Process ID, Arrival Time, Burst Time (space-separated): ";
        cin >> arr[i].p_name >> arr[i].arrival_time >> arr[i].burst_time;
        total_burst_time += arr[i].burst_time;
        arr[i].time_remaining = arr[i].burst_time;
        arr[i].exit_time = 0;
    }

    /* schedule the processes */
    schedule(arr, size, total_burst_time, time_quanta);
    /* print the array */
    print_array(arr, size);
    getch();
    return 0;
}

void schedule(Process arr [], int size, int total_burst_time, int time_quanta){
    /* sort based on arrival_time (bubble_sort) */
    for(int i=0; i<size; i++){
        for(int j=i+1;j<size;j++){
            if (arr[i].arrival_time > arr[j].arrival_time){
                Process temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }


    /* Robin Round starts here
    Algorithm ->
        1. Check if there exists a process to be executed.
        2. If there are such processes, execute process i in round-robin manner.
        3. decrease time remaining of process i by the time it has executed.
        4. Repeat    
    */

    int time_elapsed = arr[0].arrival_time;     // This will store the time that has passed.
    int CPU_processing_time = 0;                // This will store the time the CPU is actually doing work and not sitting idle.
    Process* current_process = &arr[0];         // This will store the current process being executed in the CPU.
    int index = -1;                             // This will store the index in the array of the current process being executed in the CPU.
    int is_CPU_idle = 1;                // This will store whether the CPU is sitting idle or processing something.

    /* Iterate until all the processes are executed */
    while(CPU_processing_time<total_burst_time){

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
        /* select the process to be executed */
        index = (index + 1)%size;
        current_process = &arr[index];

        /* check whether the process has arrived, and whether it has time remaining to be executed */
        if(current_process->arrival_time > time_elapsed || current_process->time_remaining <= 0){
            continue;
        }


        /* If the process has time remaining less than the time quanta, increment time by the time remaining of the process */
        if (current_process->time_remaining < time_quanta){
            time_elapsed += current_process->time_remaining;        // Increment time_elapsed by time remaining
            CPU_processing_time += current_process->time_remaining; // Increment CPU process time by time remaining
            current_process->time_remaining = 0;                    // Process has completed execution, set its time remaining to 0
        } 
        else /* If the process has time remaining greater than the time quanta, increment time by the time quanta */
        { 
            time_elapsed += time_quanta;                            // Increment time_elapsed by time quanta
            CPU_processing_time += time_quanta;                     // Increment CPU process time by time quanta
            current_process->time_remaining -= time_quanta;         // Decrease the time remaining of the process by the time quanta
        }


        /* check if the current process has time remaining 0, and exit time 0 */
        if(current_process->time_remaining <= 0 && current_process->exit_time == 0){
            current_process->exit_time = time_elapsed;              // The process has finished execution, note down its time.
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