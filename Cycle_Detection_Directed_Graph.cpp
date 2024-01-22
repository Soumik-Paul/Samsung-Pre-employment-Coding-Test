#include <bits/stdc++.h>
using namespace std;
vector<int> adj[20];
int vis[20];
int path[20];
bool dfs(int node)
{
	vis[node]=1;
	path[node]=1;

	for(auto it: adj[node])
	{
		//for non visited node
		if(!vis[it])
		{
			bool check = dfs(it);
			if(check)
				return true;
		}
		//if node is visited but it is in same path
		else if(path[it])
			return true;
	}




	path[node]=0;
	return false;
}
int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif

	int n,m,i,j,x,y;
	bool check= false;
	
	cin>>n>>m;
	
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
	}
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			 check = dfs(i);
			if(check)
				cout<<"Cycle detected";

		}
	}

	if(!check)
	cout<<"No cycle detected"<<endl;




	return 0;
}