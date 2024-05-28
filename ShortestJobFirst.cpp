#include <iostream>
using namespace std;

int main() {


    int processID[100];
    int burstTime[100];
    int waitingTime[100];
    int turnaroundTime[100];

    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;

    cout << "Enter number of process: ";
    cin >> n;

    cout << "Enter Burst Time:" << endl;

    for (i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> burstTime[i];
        processID[i] = i + 1;
    }

    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++)
            if (burstTime[j] < burstTime[index])
                index = j;
        temp = burstTime[i];
        burstTime[i] = burstTime[index];
        burstTime[index] = temp;

        temp = processID[i];
        processID[i] = processID[index];
        processID[index] = temp;
    }

    waitingTime[0] = 0;
    for (i = 1; i < n; i++) {
        waitingTime[i] = 0;
        for (j = 0; j < i; j++)
            waitingTime[i] += burstTime[j];
        total += waitingTime[i];
    }

    avg_wt = (float)total / n;
    total = 0;
    cout << "P     BT     WT     TAT" << endl;

    for (i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
        total += turnaroundTime[i];
        cout << "P" << processID[i] << "     " << burstTime[i] << "     " << waitingTime[i] << "      " << turnaroundTime[i] << endl;
    }

    avg_tat = (float)total / n;
    cout << "Average Waiting Time= " << avg_wt << endl;
    cout << "Average Turnaround Time= " << avg_tat << endl;

    return 0;
}
