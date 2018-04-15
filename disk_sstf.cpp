#include<iostream>
#include<cmath>
#include<limits.h>
#define max 20
using namespace std;

int cymax,i,j,req,ttl_tracks=0,cp,np,cposn,nposn,cyposn[max],ind[max];

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

void search_sort()
{
  int npl,npr,tmpr,tmpl;
  if(cp==0){
    np=cp;
    while(ind[np]==1 && np<req)
      np++;
  }
  else if(cp==req){
    np=cp;
    while(ind[np]==1 && np>0)
      np--;
  }
  else{
    npl=cp;
    while(ind[npl]==1 && npl>0)
      npl--;
    if(npl==0 && ind[npl]==1)
      tmpl=INT_MAX;
    else
      tmpl=cyposn[npl];
    npr=cp;
    while(ind[npr]==1 && npr<req)
      npr++;
    if(npl==req && ind[npr]==1)
      tmpr=INT_MAX;
    else
      tmpr=cyposn[npr];
    if(abs(cyposn[cp]-tmpl)<abs(cyposn[cp]-tmpr))
      np=npl;
    else  np=npr;
  }
  ind[np]=1;
}
void SSTF()
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
  do{
    search_sort();
    cout<<(i+1)<<"\t\t"<<cyposn[cp]<<"\t\t"<<cyposn[np]<<"\t\t"<<abs(cyposn[cp]-cyposn[np])<<"\n";
    ttl_tracks+=(abs(cyposn[cp]-cyposn[np]));
    cp=np;
    i++;
  }while(i!=req+1);
  cout<<"-------------------------------------------------------------\n";
  cout<<"Total tracks displaced: "<<ttl_tracks<<"\n";
}

int main()
{
  do{
    cout<<"\nEnter the no. of requests: ";
    cin>>req;
  }while(req>max || req<=0);
  input();
  SSTF();
  return 0;
}