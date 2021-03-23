#include <iostream>
#include <iomanip>


/*
Banker’s Algorithm is a deadlock avoidance algorithm.
It is also used for deadlock detection.
This algorithm tells that if any system can go into a deadlock or not by analyzing the currently
allocated resources and the resources required by it in the future.
There are various data structures which are used to implement this algorithm.
*/



using namespace std
;
class Bankers{

        struct file
    {
        int all[10];
        int maxx[10];
        int need[10];
        int flag;
    };

    public : void main() {
        /*variable declaration*/
        struct file f[10];
        int fl;
        int i, j, k, p, b, numberOfprocsses, numberOfresources, g, cnt=0, id, newr; int avail[10],seq[10];

        cout << "--------------------------------------------------------"<<endl;
        cout << "You selected Bankers Algorithm"<<endl;
        //accepting inputs
        cout << "--------------------------------------------------------"<<endl;
        cout << "\nEnter number of processes -- ";
        cin >> numberOfprocsses;
        cout << "Enter number of resources -- ";
        cin >> numberOfresources;


        //accepting inputs using the for loop
        //allocations for the processes
        for(i=0;i<numberOfprocsses;i++)
        {
            cout << "\nEnter the details for Process " << i;
            cout << "\nEnter the allocation for the Process\t -- \t";

            for(j=0;j<numberOfresources;j++)
            cin >> f[i].all[j];

            cout << "Enter the Max Value\t\t -- \t";

            for(j=0;j<numberOfresources;j++)
            cin >> f[i].maxx[j];
            f[i].flag=0;
        }

        cout << "\nEnter Available Resources\t -- \t";

        for(i=0;i<numberOfresources;i++)
        cin >> avail[i];
        cout << "\nEnter New Request Details -- ";
        cout << "\nEnter the Process ID \t -- \t";

        cin >> id;
        cout << "Enter Request for Resources \t -- \t";

        for(i=0;i<numberOfresources;i++)
        {
            cin >> newr;
            f[id].all[i] += newr;
            avail[i]=avail[i] - newr;
        }

        for(i=0;i<numberOfprocsses;i++) {
            for(j=0;j<numberOfresources;j++) {
                f[i].need[j]=f[i].maxx[j]-f[i].all[j];
                if(f[i].need[j]<0)
                f[i].need[j]=0;
            }
        }

        cnt=0;
        fl=0;
        while(cnt!=numberOfprocsses) {
            g=0;
            for(j=0;j<numberOfprocsses;j++)
            {
                if(f[j].flag==0)
                {
                    b=0;
                    for(p=0;p<numberOfresources;p++)
                    {
                        if(avail[p]>=f[j].need[p])
                            b=b+1;
                        else
                            b=b-1;
                    }

                    if(b==numberOfresources)
                    {

                        cout << "\nP is visited" << j;
                        seq[fl++]=j;
                        f[j].flag=1;
                        for(k=0;k<numberOfresources;k++)
                            avail[k]=avail[k]+f[j].all[k];
                        cnt=cnt+1;
                        cout << "(";
                        for(k=0;k<numberOfresources;k++)
                            cout << avail[k];
                        cout << ")";
                        g=1;
                    }
                }
            }
            if(g==0)
            {
                cout << "\n REQUEST NOT GRANTED -- DEADLOCK OCCURRED" << endl;
                cout << "\n SYSTEM IS IN UNSAFE STATE" << endl;
                goto y;
            }
        }

        cout << "\n\nSYSTEM IS IN SAFE STATE" << endl;
        cout << "\nThe Safe Sequence is -- (";
        for(i=0;i<fl;i++)
            cout << "P" << seq[i] << " ";
            cout << ")";
        y: cout << "\nProcess\t\tAllocation\t\tMax\t\t\tNeed\n";
        for(i=0;i<numberOfprocsses;i++)
        {
            cout << "P" << i <<"\t";
            for(j=0;j<numberOfresources;j++)
                cout << setw(6) << f[i].all[j];
            for(j=0;j<numberOfresources;j++)
                cout << setw(9) << f[i].maxx[j];
            for(j=0;j<numberOfresources;j++)
                cout << setw(6) << f[i].need[j];
            cout << "\n";
        }
    }

};
