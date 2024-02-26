#include <iostream>
#include<cstring>
using namespace std;

void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++)
    {
        int wstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (wstIdx == -1 || blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }
        if (wstIdx != -1)
        {
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
        }
    }

    int totalFragmentation = 0;
    cout << "\nProcess No.\tProcess Size\tBlock no.\tFragmented Block Size\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t\t" << processSize[i] << "\t\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1 << "\t\t" << blockSize[allocation[i]];
            totalFragmentation += blockSize[allocation[i]];
        }
        else
            cout << "Not Allocated\t0";
        cout << endl;
    }

    //cout << "\nTotal Fragmentation: " << totalFragmentation << endl;
}

int main()
{
    int m, n;
    cout << "Enter the number of blocks: ";
    cin >> m;
    int blockSize[m];
    cout << "Enter the block sizes:" << endl;
    for (int i = 0; i < m; i++)
        cin >> blockSize[i];

    cout << "Enter the number of processes: ";
    cin >> n;
    int processSize[n];
    cout << "Enter the process sizes:" << endl;
    for (int i = 0; i < n; i++)
        cin >> processSize[i];

    worstFit(blockSize, m, processSize, n);

    return 0;
}
