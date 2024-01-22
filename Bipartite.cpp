/*
Input 1
7 7
1 2
2 3
2 5
5 6
3 4
4 6
6 7
Not Bipartite

Input 2
7 6
1 2
2 3
2 5
3 4
4 6
6 7
Bipartite

*/

/*
color -1 means no color
color can be of 0 or 1
*/
#include <bits/stdc++.h>
using namespace std;
int  color[15];
vector<int> adj[15];
#define pb push_back


bool dfs(int node,int col)
{
	color[node]=col;
	for(auto it: adj[node])
	{
		if(color[it]==-1)
		{
			bool check= dfs(it,!col);
			if(!check) return false;
		}
		else if(col == color[it])
			return false;
	}

	return true;
}


int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif
	int i,x,y,n,e;
	cin>>n>>e;

	for(i=1;i<=n+1;i++)
		color[i]=-1; // first it is not colored

	for(i=1;i<=e;i++)
	{
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);

	}
	bool check= true;
	for(i=1;i<=n;i++)
	{
		if(color[i]==-1)
		{

			check = dfs(i,0);
			{
				if(!check)
				{
					cout<<"Not bipartite"<<endl;
					break;
				}
			}
		}
	}
	if(check)
		{
			cout<<"Bipartite"<<endl;
			// node with same color 
			for(i=1;i<=n;i++)
				if(color[i]==0)
					cout<<i<<" ";
			cout<<endl;
			for(i=1;i<=n;i++)
				if(color[i]==1)
					cout<<i<<" ";
		}





	return 0;
}