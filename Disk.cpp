#include <iostream>
using namespace std;


class Disk{

public:

    int choice;
     char again;
    void algorithm(){



         do{
        cout << "--------------------------------------------------------"<<endl;
        cout << "You selected DISK SCHEDULING ALGORITHM"<<endl;
        cout << "--------------------------------------------------------"<<endl;
        cout << "Please select one of the following methods";
            cout << "\n\n1. FCFS  \n2. SCAN \n3. C-SCAN\n\nChoice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    FCFS();

                    break;

                case 2:
                    SCAN();

                    break;

                case 3:
                    CSCAN();

                    break;

                default:
                    cout << "\nWrong Input Re-run the program and try again!!!";
                    break;
            }

            cout << "\n\nAnother Test???: ";
            cin >> again;
        }

         while(again == 'y');



    }






    void FCFS() {

        int t[20], n, i, I, j, tohm[20], tot=0;
        float avhm;

        cout<<"\nEnter the no.of tracks: ";
        cin >> n;

        cout<<"Enter the tracks to be traversed: ";
        for(i=2;i<n+2;i++)
        cin >> t[i];

        for(i=1;i<n+1;i++)
        {
            tohm[i]=t[i+1]-t[i];

            if(tohm[i]<0){
                tohm[i]=tohm[i]*(-1);
            }

        }

        for(i=1;i<n+1;i++){
            tot+=tohm[i];
        }

        avhm=(float)tot/n;

        cout<<"\nTracks traversed\tDifference between tracks\n";
        for(i=1;i<n+1;i++)
        {
            cout << t[i] << "\t\t\t" << tohm[i] << endl;
        }

        cout<<"\nAverage header movements: "<< avhm;

    }



    void SCAN() {

        int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum=0;

        cout << "\nEnter the no of tracks to be traveresed: ";
        cin >> n;

        cout << "Enter the position of head: ";
        cin >> h;

        t[0]=0;t[1]=h;

        cout << "Enter the tracks: ";

        for(i=2;i<n+2;i++)
            cin >> t[i];

        for(i=0;i<n+2;i++)
        {
            for(j=0;j<(n+2)-i-1;j++)
            {
                if(t[j]>t[j+1])
                {
                   temp=t[j];
                   t[j]=t[j+1];
                   t[j+1]=temp;
                }
            }
        }


        for(i=0;i<n+2;i++)
            if(t[i]==h)
                j=i;k=i;

        p=0;
        while(t[j]!=0) {
            atr[p]=t[j];
            j--;
            p++;
        }

        atr[p]=t[j];

        for(p=k+1;p<n+2;p++,k++)
            atr[p]=t[k+1];

        for(j=0;j<n+1;j++)
        {
            if(atr[j]>atr[j+1])
                d[j]=atr[j]-atr[j+1];
            else
                d[j]=atr[j+1]-atr[j];
            sum+=d[j];
        }

        cout << "\nAverage header movements: " << (float)sum/n;

    }



    void CSCAN(){

        int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum=0;

        cout << "Enter the no of tracks to be traveresed: ";
        cin >> n;

        cout << "Enter the position of head: ";
        cin >> h;

        t[0]=0;t[1]=h;

        cout << "Enter total tracks: ";
        cin >> tot;

        t[2]=tot-1;

        cout << "Enter the tracks: ";
        for(i=3;i<=n+2;i++)
            cin >> t[i];

        for(i=0;i<=n+2;i++)
            for(j=0;j<=(n+2)-i-1;j++)
                if(t[j]>t[j+1])
                {
                    temp=t[j];
                    t[j]=t[j+1]; t[j+1]=temp;
                }

        for(i=0;i<=n+2;i++)
            if(t[i]==h)
                j=i;

        p=0;

        while(t[j]!=tot-1)
        {
            atr[p]=t[j];
            j++;
            p++;
        }

        atr[p]=t[j];
        p++;
        i=0;

        while(p!=(n+3) && t[i]!=t[h])
        {
            atr[p]=t[i];
            i++;
            p++;
        }

        for(j=0;j<n+2;j++)
        {
            if(atr[j]>atr[j+1])
                d[j]=atr[j]-atr[j+1];
            else
                d[j]=atr[j+1]-atr[j];
            sum+=d[j];

        }

        cout << "\n\nTotal header movements: " << sum;
        cout << "\nAvg is: " << (float)sum/n;

    }

};
