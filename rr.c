/*
Sample Input:

When prompted "Enter number of processes: ", type:
4

Then, for the next prompts, type the AT and BT values:
Enter Arrival Time and Burst Time for P1: 0 10
Enter Arrival Time and Burst Time for P2: 1 4
Enter Arrival Time and Burst Time for P3: 2 5
Enter Arrival Time and Burst Time for P4: 3 3

When prompted "Enter Time Quantum: ", type:
3
*/

#include <stdio.h>

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], arrival[n], burst[n], rem[n], waiting[n], tat[n];
    int completed = 0, time = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", pid[i]);
        scanf("%d %d", &arrival[i], &burst[i]);
        
        rem[i] = burst[i];
        waiting[i] = 0;
        tat[i] = 0;
    }
    
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);
    
    while (completed < n) {
        int done = 1;
        
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0 && arrival[i] <= time) {
                done = 0;
                
                if (rem[i] > quantum) {
                    time += quantum;
                    rem[i] -= quantum;
                } else {
                    time += rem[i];
                    waiting[i] = time - burst[i] - arrival[i];
                    tat[i] = waiting[i] + burst[i];
                    rem[i] = 0;
                    completed++;
                }
            }
        }
        
        if (done) {
            time++;
        }
    }
    
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    float avgWT = 0, avgTAT = 0;
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", pid[i], arrival[i], burst[i], waiting[i], tat[i]);
        avgWT += waiting[i];
        avgTAT += tat[i];
    }
    
    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);
    
    return 0;
}
