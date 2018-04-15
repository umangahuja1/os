#include<iostream>
#include<vector>
using namespace std;

bool need(int needed[][100],int numProcess,int totalTypes)
{
        for(int i=0;i<numProcess;i++)
                for(int j=0;j<totalTypes;j++)
                        if(needed[i][j]>0)
                                return true;
        return false;
}

int main()
{
        int total[100];
        int totalTypes;
        int numProcess;
        int allocated[100][100],needed[100][100],maxRequired[100][100];
        cout<<"Enter total number of types of resources: ";
        cin>>totalTypes;
        cout<<"Enter total number of instances for: \n";
        for(int i=0;i<totalTypes;i++)
        {
                cout<<"Resource "<<i+1<<": ";
                cin>>total[i];
        }
        cout<<"Enter number of process: ";
        cin>>numProcess;
        cout<<"Enter Allocated and Maximum Required Resorces for: \n";
        for(int i=0;i<numProcess;i++)
        {
                for(int j=0;j<totalTypes;j++)
                {
                        cout<<"Resource "<<j+1<<": \n";
                        cout<<"Process "<<i+1<<": ";
                        cin>>allocated[i][j]>>maxRequired[i][j];
                        needed[i][j]=maxRequired[i][j]-allocated[i][j];
                        total[j]-=allocated[i][j];
                }
        }
        for(int i=0;i<totalTypes;i++)
        {
                if(total[i]<0)
                {
                        cout<<"Allocation Not Possible";
                        return -1;
                }
        }
        bool flag=true;
        vector<int> safeSequence;
        while(need(needed,numProcess,totalTypes)&&flag)
        {
                flag=false;
                bool thisProcess,allZero;
                for(int i=0;i<numProcess;i++)
                {
                        thisProcess=true;
                        allZero=true;
                        for( int j=0;j<totalTypes;j++)
                        {
                                if(needed[i][j]>0)
                                        allZero=false;
                                if(needed[i][j]>total[j])
                                {
                                        thisProcess=false;
                                        break;
                                }
                        }
                        if(thisProcess && !allZero)
                        {
                                safeSequence.push_back(i+1);
                                flag=true;
                                for(int j=0;j<totalTypes;j++)
                                {
                                        total[j]+=allocated[i][j];
                                        needed[i][j]=0;
                                }
                        }
                }
        }
        if(flag==false)
                cout<<"\nAllocation Not possible";
        else
        {
                cout<<"\nSafe Sequence: ";
                for(int i=0;i<safeSequence.size();i++)
                        cout<<safeSequence[i]<<" ";
        }
        return 0;
}