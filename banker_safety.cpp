#include <iostream>
#include <vector>

using namespace std;

bool need(int needed[], int numprocess)
{
    for(int i=0;i<numprocess;i++)
        if(needed[i]>0)
            return true;
    
    return false;
}

int main()
{
    int total;
    int numprocess;
    int allocated[100], needed[100], max_required[100];
    cout<<"Enter total number of instances : ";
    cin>>total;
    cout<<"Enter number of processes : ";
    cin>>numprocess;
    cout<<"Enter allocated and maximum required resources for : \n";

    for(int i=0;i<numprocess;i++)
    {
        cout<<"Process "<<i+1<<":";
        cin>>allocated[i]>>max_required[i];
        needed[i] = max_required[i] - allocated[i];
        total -= allocated[i];
    }

    if(total<0)
    {
        cout<<"Allocation not possible";
        return -1;
    }

    bool flag = true;
    vector <int> safe_sequence;

    while(need(needed, numprocess) && flag)
    {
        flag = false;
        for(int i=0;i<numprocess;i++)
        {
            if(needed[i]<=total && needed[i]>0)
            {
                safe_sequence.push_back(i+1);
                flag = true;
                total+=allocated[i];
                needed[i]=0;
            }
        }
    }

    if(flag==false)
    {
        cout<<"\n allocation not possible";
    }

    else
    {
        cout<<"\n safe sequence : ";
        for(int i=0;i<safe_sequence.size();i++)
            cout<<safe_sequence[i]<<" ";
    }

    return 0;
}