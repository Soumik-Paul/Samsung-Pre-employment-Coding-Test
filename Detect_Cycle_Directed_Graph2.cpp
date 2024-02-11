/*
5 5
2 4 2 3 4 3 1 5 5 1
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>

using namespace std;

#define MAX 100

vector<int>adj[MAX];
vector<int>tmp;
int ans=INT_MAX;
int n,m;

void bfs(int x,vector<int>&vis,vector<int>&par,vector<int>&dis){
    vis[x]=1;
    dis[x]=0;
    queue<int>q;
    q.push(x);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v: adj[u]){
          //  int v=adj[u][i];
            if(!vis[v]){
                par[v]=u;
                vis[v]=1;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    // for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++){
        if(i==x) continue;
        for(auto j : adj[i]){

            if(j==x && ans>dis[i]+1 && vis[i]){
                
                
                    ans=dis[i]+1;
                    tmp.clear();
                    tmp.push_back(x);
                    for(int k=i;k!=x;k=par[k])tmp.push_back(k);

            }
        }
    }


}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    for(int i=1;i<=n;i++){
        vector<int>vis(n+1,0);
        vector<int>par(n+1,-1);
        vector<int>dis(n+1,INT_MAX);
        bfs(i,vis,par,dis);
    }
    // cout<<ans<<endl;
    sort(tmp.begin(),tmp.end());
    for(auto x:tmp)cout<<x<<" ";
    cout<<endl;
  
    return 0;
}
