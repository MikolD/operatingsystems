  #include <iostream>
 using namespace std;

    class Roundrobin{

        public:

    void roundRobin(){
          // Declaring variables
  int i,numpro,time,remain,temps=0,time_quantum;

  int wTime=0,taTime=0;


  cout << "/////////////////////////////////////////////////////"<<endl;
  cout << " You selected - Memory Management Scheme | Round Robin"<<endl;
  cout << "/////////////////////////////////////////////////////"<<endl;
  cout<<"Enter the total number of process: ";
  cin>>numpro;
  while(numpro<1){
        cout<<"Enter a positive number"<<endl;
        cout<<"Enter Number of Processes: ";
        cin>>numpro;
    }

  remain=numpro;
  // assigning the number of process to remain variable

  int arrivTime[numpro];
  int bTime[numpro];
  int rt[numpro];


  cout<<"Enter the Arrival time, Burst time for All the processes"<<endl;

  for(i=0;i<numpro;i++)
  {
    cout<<"Arrival time for process "<<i+1<<": ";
    cin>>arrivTime[i];
    cout<<"Burst time for process "<<i+1<<": ";
    cin>>bTime[i];
    rt[i]=bTime[i];
  }

  cout<<"Enter the value of time QUANTUM: ";
  cin>>time_quantum;

  cout<<"\n\nProcess\t:Turnaround Time:Waiting Time\n\n";
  for(time=0,i=0;remain!=0;)
  {
    if(rt[i]<=time_quantum && rt[i]>0)
    {
      time += rt[i];

      rt[i]=0;
      temps=1;
    }

    else if(rt[i]>0)
    {
      rt[i] -= time_quantum;

      time += time_quantum;

    }

    if(rt[i]==0 && temps==1)
    {
      remain--;
    //Displaying the result of waiting, turn around time:
      printf("Process{%d}\t:\t%d\t:\t%d\n",i+1,time-arrivTime[i],time-arrivTime[i]-bTime[i]);
      cout<<endl;

      wTime += time-arrivTime[i]-bTime[i];
      taTime += time-arrivTime[i];
      temps=0;
    }

    if(i == numpro-1){
      i=0;
    }
    else if(arrivTime[i+1] <= time){
      i++;
    }
    else{
      i=0;
    }
  }
// Displaying the waiting time, turnaround Time
  cout<<"Average waiting time "<<wTime*1.0/numpro<<endl;
  cout<<"Average turn around time "<<taTime*1.0/numpro<<endl;;

}
    };
