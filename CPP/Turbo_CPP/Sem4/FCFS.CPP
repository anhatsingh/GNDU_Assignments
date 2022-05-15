/*
Name        -> First Come First Serve Scheduling Algorithm
Author      -> Anhat Singh
Tested on   -> Turbo C++
Date        -> 13th May, 2022
Assumptions -> User inputs Process Name, Arrival Time and Burst Time

*/
#include<iostream.h>
#include<conio.h>
#define MAX 10

/* declare the struct that will hold the data of a process */
struct Process{
    char p_name;
    int arrival_time;
    int burst_time;
    int wait_time;
    int turn_around_time;
};

/* declare function prototype used in this program */
void schedule(Process [], int);
void print_array(Process [], int);

int main(){
    clrscr();
    cout << "FCFS" << endl;

    Process arr[MAX];
    int size;

    cout << "Enter Number of processes: ";
    cin >> size;

    for(int a=0;a<size;a++){
        cout << "Enter Process ID, Arrival Time, Burst Time (space-separated): ";
        cin >> arr[a].p_name >> arr[a].arrival_time >> arr[a].burst_time;
    }

    schedule(arr, size);
    print_array(arr, size);

    getch();
    return 0;
}


void schedule(Process arr [], int size){
    /* bubble sort based on arrival time */
    for(int j = 0; j<size; j++){
        for(int f = j+1; f<size; f++){
            if (arr[f].arrival_time < arr[j].arrival_time){
                Process temp = arr[j];
                arr[j] = arr[f];
                arr[f] = temp;
            }
        }
    }
}


void print_array(Process arr[], int size){
    int total_wait = 0;
    int total_tat = 0;

    /* calculate wait time */
    arr[0].wait_time = 0;
    for(int i=1; i<size; i++){
        arr[i].wait_time = arr[i-1].wait_time + arr[i-1].burst_time;
        total_wait += arr[i].wait_time;
    }

    /* calculate turn around time */
    for(int l = 0; l<size; l++){
        arr[l].turn_around_time = arr[l].wait_time + arr[l].burst_time;
        total_tat += arr[l].turn_around_time;
    }


    /* print all information */
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