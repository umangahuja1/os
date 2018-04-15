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
  cout<<"Enter "<<req<<" I/O Requests: ";
  cyposn[0]=cposn;
  for(i=1;i<=req;i++)
    cin>>cyposn[i];
}
void FCFS()
{
  cout<<"\nS. No.\tCurrent Position\tNext Position\tDisplacement";
  cout<<"\n---------------------------------------------------------\n";
  for(i=0;i<req;i++)
  {
    cout<<(i+1)<<"\t\t"<<cyposn[i]<<"\t\t"<<cyposn[i+1]<<"\t\t";
    cout << abs(cyposn[i]-cyposn[i+1]) << "\n" ;
    ttl_tracks+=abs(cyposn[i]-cyposn[i+1]);
  }
  cout<<"----------------------------------------------------------\n\n";
  cout<<"Total tracks displaced: "<<ttl_tracks<<"\n";
}

int main()
{
  do{
    cout<<"\nEnter the no of requests: ";
    cin>>req;
  }while(req>max || req<=0);
  input();
  FCFS();
  return 0;
}