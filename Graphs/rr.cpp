#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n,tq,current=0,time=0,tat=0,wt=0,ptime=0,arr[100],k=0;
    cout<<"Enter number of processes\n";
    cin>>n;
    int at[n],b[n],rt[n],remain=n,flag=0;
    cout<<"Enter the arrival time and burst time of"<<n<<" processes";
    for(int i=0;i<n;i++)
    {
        cin>>at[i]>>b[i];
    }
    cout<<"Enter the time quantum";
    cin>>tq;
    cout<<" ";
    for(int i=0;i<n;i++)
    {
        rt[i]=b[i];
    }
    for(int i=0;i<n;i++)
    {
        if(at[i]==0)
        current=i;
    }
    queue <int> q;
    while(remain>0)
    {
        if(!q.empty())
        {
            current=q.front();
            q.pop();
        }
        if(rt[current]<=tq&&rt[current]>0)
        {
            time=time+rt[current];
            rt[current]=0;
            flag=1;
            cout<<"P"<<current+1<<"\t"<<"|";
            arr[k++]=time;
        }
        else if(rt[current]>tq)
        {
            flag=0;
            time=time+tq;
            rt[current]-=tq;
            cout<<"P"<<current+1<<"\t"<<"|";
            arr[k++]=time;
        }
        if(rt[current]==0&& flag==1)
        {
            tat+=time-at[current];
            wt+=time-at[current]-b[current];
            remain--;
        }
        for(int i=ptime;i<=time;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(rt[j]<=0||current==j)
                {
                    continue;
                }
                if(at[j]==i)
                q.push(j);
            }
        }
        if(rt[current]>0)
        q.push(current);
        ptime=time;
    }
    cout<<"\n";
    cout<<0<<"\t";
    for(int i=0;i<k;i++)
    cout<<arr[i]<<"\t";
    cout<<"Avg TAT= "<<(float)tat/n<<"\n";
    cout<<"Avg WT= "<<(float)wt/n;
}
