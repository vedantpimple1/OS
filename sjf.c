/*
Sample Input:

When prompted "Enter number of processes: ", type:
4

Then, for the next prompts, type the AT and BT values:
Enter Arrival Time and Burst Time for P1: 0 8
Enter Arrival Time and Burst Time for P2: 1 4
Enter Arrival Time and Burst Time for P3: 2 9
Enter Arrival Time and Burst Time for P4: 3 5
*/

#include <stdio.h>

int main() {
    int n;
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

    while (completed < n) {
        int idx = -1;
        int min_rem = 1000000000;

        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && rem[i] > 0 && rem[i] < min_rem) {
                min_rem = rem[i];
                idx = i;
            }
        }

        if (idx != -1) {
            rem[idx]--;
            time++;

            if (rem[idx] == 0) {
                completed++;
                tat[idx] = time - arrival[idx];
                waiting[idx] = tat[idx] - burst[idx];
            }
        } else {
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
    
    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}
