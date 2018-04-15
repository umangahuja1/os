#include<iostream>
#include<cmath>
#define max 20
using namespace std;

int cymax,i,j,req,ttl_tracks=0,cp,np,cposn,nposn,cyposn[max];
void input()
{
    do{
        cout<<"\nEnter the maximum range of request: ";
        cin>>cymax;
        cout<<"Enter the current header position: ";
        cin>>cposn;
    }while(cposn>cymax || cposn<=0);
    cout<<"Enter "<<req<<" I/O Request: ";
    cyposn[0]=cposn;
    for(i=1;i<=req;i++)
        cin>>cyposn[i];
}
void CLOOK()
{
    for(i=0;i<=req;i++)
        for(j=0;j<req-1;j++)
            if(cyposn[j]>cyposn[j+1])
                swap(cyposn[j],cyposn[j+1]);
    cp=0;
    do{
        if(cyposn[cp]==cposn)
            break;
        cp++;
    }while(cp!=req);
    cout<<"\nS. No.\tCurrent Position\tNext Position\tDisplacement\n";
    cout<<"-------------------------------------------------------------\n";
    i=0;
    j=cp;
    cposn=cyposn[cp];
    do{
        if(cp==req-1){
            nposn=cyposn[0];
            cp=0;
        }
        else
            nposn=cyposn[++cp];

        cout<<++i<<"\t\t"<<cposn<<"\t\t"<<nposn<<"\t\t"<< abs(cposn-nposn)<<"\n";
        ttl_tracks+=(abs(cposn-nposn));
        cposn = nposn;
    }while(nposn!=cyposn[j-1]);
    cout<<"-------------------------------------------------------------\n";
    cout<<"Total tracks displaced: "<<ttl_tracks;
}

int main()
{
    do{
        cout<<"\nEnter the number of requests: ";
        cin>>req;
    }while(req>max||req<=0);
    input();
    CLOOK();
    cout<<endl;
    return 0;
}