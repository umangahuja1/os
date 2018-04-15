#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    vector < pair < int, int> >process;
    vector <int> wait, turnaround;
    int total_process;

    cout<<"Enter total number of process : ";
    cin>>total_process;
    cout<<"Enter process burst time : \n";
    for(int i=0;i<total_process;i++)
    {
        int j;
        cout<<"Process "<<i+1<<" : ";
        cin>>j;
        process.push_back(make_pair(i,j));

    }

    for(int i=0;i<total_process;i++)
    {
        for(int j=i+1;j<total_process;j++)
        {
            if(process[j].second<process[i].second)
            {
                pair<int,int> temp = process[j];
                process[j]=process[i];
                process[i]=temp;
            }
        }
    }

    wait.push_back(0);
    turnaround.push_back(process[0].second);
    
    for(int i=1;i<total_process;i++)
    {
        wait.push_back(wait[i-1]+process[i-1].second);
        turnaround.push_back(wait[i]+process[i].second);
    }

    int awt=0, atat=0;

    cout<<"\nProcess\t Burst time\t Waiting time\t Turnaround time\n";
    for(int i=0;i<total_process;i++)
    {
        cout<<process[i].first+1<<"\t "<<process[i].second<<"\t\t "<<wait[i]<<"\t\t "<<turnaround[i]<<endl;
        awt+=wait[i];
        atat+=turnaround[i];
    }

    cout<<"\nAverage waiting time : "<<awt/(float)total_process<<endl;
    cout<<"Average turnaround time : "<<atat/(float)total_process<<endl;


}