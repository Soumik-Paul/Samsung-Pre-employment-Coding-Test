#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> adj[20];
int vis[20];
int stack[20],mini=INT_MAX,top=-1;
vector<int> ans;
void detect(int node)
{
	if(vis[node])
	{
		vector<int> temp;
		int sum=0;
		for(int i=top-1;i>=0;i--)
		{
			temp.push_back(stack[i]);
			sum+= stack[i];
			if(stack[i]== node)
				break;
		}
		if(sum<mini)
		{
			mini= sum;
			ans= temp;
		}
		return;
	}
	if(!vis[node])
	{
		vis[node]=1;
		for(auto i:adj[node])
		{
			stack[++top]=i;
			detect(i);
			top--;
		}
		vis[node]=0;
	}

}
int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif

    int n,m,i,j,x,y;
	
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
			stack[++top]=i;
			detect(i);
		}


	}
	sort(ans.begin(),ans.end());
	for(auto it: ans)
	{
		cout<<it<<" ";
	}


	return 0;
}