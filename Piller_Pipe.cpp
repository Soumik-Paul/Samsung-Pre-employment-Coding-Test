#include<iostream>
using namespace std;
int n,ans=0;
int ar[1000];

void go(int id,int first,int second)
{
    // cout<<"i am here"<<" "<<id<<endl;
    if(id>n)
    {
        if(first==second){
            ans=max(ans,first);
        }
        return;
    }
    go(id+1,first+ar[id],second);
    go(id+1,first,second+ar[id]);
    go(id+1,first,second);

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    
    go(1,0,0);

    cout<<ans<<endl;

    return 0;

}