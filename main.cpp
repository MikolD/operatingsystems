/*
MFT (Multiprogramming with a Fixed number of Tasks) is one of the old memory management techniques in
which the memory is partitioned into fixed size partitions and each job is assigned to a partition. The memory
assigned to a partition does not change.


MVT (Multiprogramming with a Variable number of Tasks) is the
memory management technique in which each job gets just the amount of memory it needs. That is, the
partitioning of memory is dynamic and changes as jobs enter and leave the system. MVT is a more ``efficient''
user of resources. MFT suffers with the problem of internal fragmentation and MVT suffers with external
fragmentation.


One of the simplest methods for memory allocation is to divide memory into several fixed-sized partitions. Each
partition may contain exactly one process. In this multiple-partition method, when a partition is free, a process is
selected from the input queue and is loaded into the free partition. When the process terminates, the partition
becomes available for another process. The operating system keeps a table indicating which parts of memory
are available and which are occupied. Finally, when a process arrives and needs memory, a memory section
large enough for this process is provided. When it is time to load or swap a process into main memory, and if
there is more than one free block of memory of sufficient size, then the operating system must decide which
free block to allocate. Best-fit strategy chooses the block that is closest in size to the request. First-fit chooses
the first available block that is large enough. Worst-fit chooses the largest available block.

Authors : Gerald Adjeman- Cofie - 219CS01000133
          Michael Damoah -221IT01000659
          Carey Aboagye Osafo -219CS01000060*/

#include <iostream>
#include  "Multiprogrammingmethods.cpp"
#include  "Fittingmethods.cpp"
#include  "Pagingmethod.cpp"
#include  "Shortestjobnext.cpp"
#include  "roundrobin.cpp"
#include  "Disk.cpp"
#include  "Bankers.cpp"


using namespace std;


int main() {
  int choice; // To be used to select method used for memory allocation

    // This is where we created instances of the classes we call in our project "OBJECTS"
    Multiprogrammingmethods multi;
    Fittingmethods fits;
    Pagingmethod pages;
    Roundrobin robs;
    ShortestjobNext shortjn;
    Bankers bank;
    Disk dische;
    char again;

    do {
      cout << "*******************************************************" << endl;
      cout << "Memory Management version 1.3 - By Gerald, Michael and Carey \n";
      cout << "*******************************************************" << endl;
      cout << "Welcome Back, " << endl;
      cout << "+++++++++++++" << endl;
      cout << "\nPlease select the Preferred Method " << endl;
      cout << "To use Multiprogramming Methods Enter 1 " << endl;
      cout << "To use Fitting Methods Enter 2 " << endl;
      cout << "To use Paging Method Enter 3 " << endl;
      cout << "To use Round Robin Method Enter 4 " << endl;
      cout << "To use Shortest Job Next Method Enter 5 " << endl;
      cout << "To use Bankers Method Enter 6 " << endl;
      cout << "To use Disk Scheduling Method Enter 7 " << endl;
      cout << "\nChoice : ";
      cin >> choice;

      if (choice == 1)

      {
        multi.multimenu();
      }
      else if (choice == 2) {
        fits.fittingmethods();
      }
      else if (choice == 3) {
        pages.paging();
      }
      else if (choice == 4){
        robs.roundRobin();
      }
        else if (choice == 5){
            shortjn.sfj();
        }
        else if (choice == 6){
            bank.main();
        }
        else if (choice == 7){
            dische.algorithm();
        }
        else{
                cout << "Wrong Input try again!!!" << endl;
                cin>>choice;
      }
      cout << "\n\nAnother Test???: ";
      cout << "\n\nEnter Y or N"<<endl;
                        cin >> again;
    }

    while (again == 'y');
  return 0;
}
