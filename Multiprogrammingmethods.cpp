#include <iostream>
using namespace std;


class Multiprogrammingmethods{

public:

int choice;

void multimenu(){
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout << "Hi there, you selected Memory Management Scheme | Multiprogramming Methods"<<endl;
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout << "Please select the method you would like to try"<<endl;
  cout << "Enter 1 for Multiprogramming Fixed Tasks Method"<<endl;
  cout << "Enter 2 for Multiprogramming Variable Tasks Method "<<endl;
  cout << "Choice : ";

  cin >> choice;


  switch (choice) {
            case 1:
                mft();

                break;

            case 2:
                mvt();

                break;

                   default:
                cout << ("\nWrong Input Re-run the program and try again!!!");
                break;
        }

  }


void mft() {
  /* initialization of variables where
    ms = Memory Available,
    bs = Block size,
    n = number of processes
    nob = number of blocks
    ef = External Fragementation
    tif = total internal fragmentation
    mp = Array for memory required for processes
    */
  // variable declaration
  int memSize, blockSize, numOfblocks, exterFrag, numOfprocess, memProcess[10], totalInterfrag = 0;
  int i, p = 0;

  cout << "\n\tMemory Management Scheme - Multiprogramming Fixed Tasks";
  cout << "Enter the total memory available (in Bytes) -- ";
  cin >> memSize;
  cout << "Enter the Block Size(in Bytes) --";
  cin >> blockSize;

  // Processing the Number of blocks and external fragmentation
  numOfblocks = memSize / blockSize;
  exterFrag = memSize - numOfblocks * blockSize;

  cout << "\n Enter the number of processes --";
  cin >> numOfprocess;

  for (i = 0; i < numOfprocess; i++) {
    cout << "Enter the memory required for process " << i + 1 << "(in Bytes)-- ";
    cin >> memProcess[i];
  }
  cout << "\n\n No. of Blocks available in memory -- " << numOfblocks;
  // This section displays the Process, Memory required , if allocated and internal fragmentation.
  cout << "\n\nPROCESS \t MEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION";

  for (i = 0; i < numOfprocess && p < numOfblocks; i++) {
    cout << "\n " << i + 1 << "\t\t " << memProcess[i];
    if (memProcess[i] > blockSize) {
      cout << "\t\t\t NO \t\t--";
    } else {
      cout << "\t\t\t YES \t\t " << blockSize - memProcess[i];
      totalInterfrag = totalInterfrag + blockSize - memProcess[i];
      p++;
    }
  }

  cout << "\nMemory is Full, Remaining Processes cannot be accommodated. " << endl;
  cout << "\n Total Internal Fragmentation is " << totalInterfrag;
  cout << "\n Total External Fragmentation is " << exterFrag << endl;


  cout << "Do you want to run another method?"<<endl;
  multimenu();

}

void mvt() {
  // Variable and array declaration and initialization
  int memSize, memProcess[10], i, temp, n = 0;
  char ch = 'y';

  cout << "\n\tMemory Management Scheme - Multiprogramming Variable Tasks";
  cout << "\nEnter the total memory available (in Bytes)-- ";
  cin >> memSize;
  temp = memSize; //assigns the value in ms to temp
  for (i = 0; ch == 'y'; i++, n++) {
    cout << "\nEnter memory required for process " << i + 1 << "(in Bytes) -- ";
    cin >> memProcess[i];
    if (memProcess[i] <= temp) {
      cout << "\nMemory is allocated for Process " << i + 1;
      temp = temp - memProcess[i];
    } else {
      cout << "\nMemory is Full";
      break;
    }
    cout << "\nDo you want to continue?(y/n) -- ";
    cin >> ch;
  }
  cout << "\n\nTotal Memory Available -- " << memSize;

  cout << "\n\n\tPROCESS\t\t MEMORY ALLOCATED ";
  for (i = 0; i < n; i++) {
    cout << "\n \t" << i + 1 << "\t\t " << memProcess[i];
  }
  cout << "\n\nTotal Memory Allocated is " << memSize - temp;
  cout << "\nTotal External Fragmentation is " << temp;
}};
