/*
INPUT :
5
1 2 3 4 6
Output :
8
*/
#include<iostream>
using namespace std;
int n,ans=-1;
int ar[1000],vis[1000];

void go(int first,int second)
{
  
    
    if(first==second)
    {
        ans= max(ans,first);
       // return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            go(ar[i]+first,second);
            go(first,second+ar[i]);
            vis[i]=0;
        }
    }

}
int main()
{
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

    #endif
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    
    go(0,0);

    cout<<ans<<endl;

    return 0;

}