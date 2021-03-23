#include <iostream>
using namespace std;


class ShortestjobNext{

public:

    void sfj(){
         // Declaring Variables
 int numpro, bTime[20], wTime[20], taTime[20], i, j, index[20], itemp, temp;
 float avgwTime=0, avgtaTime=0;

    cout << "/////////////////////////////////////////////////////"<<endl;
  cout << " You selected - Memory Management Scheme | Shortest Job Next"<<endl;
  cout << "/////////////////////////////////////////////////////"<<endl;

    // Accepting inputs from user
    cout<<"Enter Number of Processes:"<<endl;
    cin>>numpro;

    //validating the input
     while(numpro<1){
        cout<<"Enter a positive number"<<endl;
        cout<<"Enter Number of Processes: ";
        cin>>numpro;
    }


    //loops for processes
    for(i=0;i<numpro;i++){
        cout<<"Enter Burst Time for Process["<<i+1<<"]:";
        cin>>bTime[i];
        index[i]=i;
    }

    for(i=0;i<numpro;i++){
        for(j=i;j<numpro;j++){
            if(bTime[j]<bTime[i]){
                swap(bTime[i], bTime[j]);
                swap(index[i], index[j]);
                 }
        }
    }
// display of various processes
    wTime[0]=0;
    cout<<"Process\t\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;
    for(i=0;i<numpro;i++){
        wTime[i+1]= wTime[i]+bTime[i];
        taTime[i]= wTime[i]+bTime[i];
        avgwTime=avgwTime+wTime[i];
        avgtaTime=avgtaTime+taTime[i];
            cout<<"P["<<index[i]+1<<"]\t\t"<<bTime[i]<<"\t\t"<<wTime[i]<<"\t\t"<<taTime[i]<<endl;
    }
    // results for Average waiting and turnaround Time

    cout<<endl<<"Average Waiting Time: "<<avgwTime/i<<endl;
    cout<<"Average Turnaround Time: "<<avgtaTime/numpro<<endl;
}
};
