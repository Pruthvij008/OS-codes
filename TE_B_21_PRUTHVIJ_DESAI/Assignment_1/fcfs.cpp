#include <iostream>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateWaitingTime(Process processes[], int n) {
    processes[0].waitingTime = 0;
    
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void calculateAverageTimes(Process processes[], int n) {
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    double averageWaitingTime = totalWaitingTime / n;
    double averageTurnaroundTime = totalTurnaroundTime / n;

    std::cout << "Average Waiting Time: " << averageWaitingTime << std::endl;
    std::cout << "Average Turnaround Time: " << averageTurnaroundTime << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    Process processes[n];

    std::cout << "Enter arrival time and burst time for each process:" << std::endl;
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        std::cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrivalTime > processes[j].arrivalTime) {
                // Swap the processes
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);

    std::cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << processes[i].id << "\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t"
                  << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << std::endl;
    }

    calculateAverageTimes(processes, n);

    return 0;
}
