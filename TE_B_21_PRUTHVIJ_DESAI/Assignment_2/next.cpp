#include<iostream>
using namespace std;

void nextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];  // Array to store block allocation for each process

    // Initialize allocation array with -1, indicating no block is allocated initially
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Count the number of processes that fit in each block
    int processesFitInBlock[m] = {0};

    int lastAllocatedBlock = 0;  // Keep track of the last allocated block index

    // Iterate through each process and find a suitable block for allocation
    for (int i = 0; i < n; i++) {
        // Start searching from the last allocated block
        int startIndex = lastAllocatedBlock;
        int currentIndex = startIndex;  // Keep track of the current index being considered

        bool blockAllocated = false;

        // Iterate through the blocks in a circular manner
        do {
            if (blockSize[currentIndex] >= processSize[i]) {
                // Allocate block currentIndex to process i
                allocation[i] = currentIndex;
                processesFitInBlock[currentIndex]++;

                // Calculate fragment size and update the block size
                int fragmentSize = blockSize[currentIndex] - processSize[i];
                blockSize[currentIndex] = fragmentSize;

                // Update last allocated block
                lastAllocatedBlock = currentIndex;
                blockAllocated = true;
                break;  // Move to the next process
            }

            currentIndex = (currentIndex + 1) % m;  // Move to the next block in a circular manner

        } while (currentIndex != startIndex);

        // If no suitable block was found in the current cycle, restart from the beginning
        if (!blockAllocated) {
            for (int j = 0; j < m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    // Allocate block j to process i
                    allocation[i] = j;
                    processesFitInBlock[j]++;

                    // Calculate fragment size and update the block size
                    int fragmentSize = blockSize[j] - processSize[i];
                    blockSize[j] = fragmentSize;

                    // Update last allocated block
                    lastAllocatedBlock = j;
                    break;
                }
            }
        }
    }

    // Print the allocation details along with fragment size
    cout << "\nProcess No.\tProcess Size\tBlock no.\tFragment Size\n";
    int totalFragmentation = 0;
    int processesNotAllocated = 0;
    for (int i = 0; i < n; i++) {
        cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << allocation[i] + 1;  // +1 to make block numbers 1-indexed
            int fragmentSize = blockSize[allocation[i]];
            totalFragmentation += fragmentSize;
            cout << "\t\t" << fragmentSize;  // Fragment size
        } else {
            cout << "Not Allocated\tN/A";
            processesNotAllocated++;
        }
        cout << endl;
    }

    cout << "\nTotal Fragmentation: " << totalFragmentation << endl;

    cout << "\nNumber of processes fit in each block:" << endl;
    for (int j = 0; j < m; j++) {
        cout << "Block " << j + 1 << ": " << processesFitInBlock[j] << " processes" << endl;
    }

    cout << "\nNumber of processes allocated: " << n - processesNotAllocated << endl;
    cout << "Number of processes not allocated: " << processesNotAllocated << endl;
}

int main() {
    int numBlocks, numProcesses;
    cout << "Enter the number of blocks: ";
    cin >> numBlocks;

    int blockSize[numBlocks];
    cout << "Enter the block sizes:" << endl;
    for (int i = 0; i < numBlocks; i++) {
        cout << "For Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    int processSize[numProcesses];
    cout << "Enter the process sizes:" << endl;
    for (int i = 0; i < numProcesses; i++) {
        cout << "For Process " << i + 1 << ": ";
        cin >> processSize[i];
    }

    nextFit(blockSize, numBlocks, processSize, numProcesses);

    return 0;
}
