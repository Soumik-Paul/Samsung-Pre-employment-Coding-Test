Mr_Lee.cpp/*
If it is impossible to move between 
two cities, it is given as zero.

Output format
Output the minimum airfare used to depart from his company, visit all offices, and then return his company on the 
first row per each test case.

Example of Input

3
5
0 14 4 10 20
14 0 7 8 7
4 5 0 7 16
11 7 9 0 2
18 7 17 4 0
5
9 9 2 9 5
6 3 5 1 5
1 8 3 3 3
6 0 9 6 8
6 6 9 4 8
3
0 2 24
3 0 2
0 4 0

Example of Output

30
18
CUSTOM - 31 <- 4
*/
#include <iostream>
using namespace std;
int vis[1000];
int mat[1001][1001];
int n,ans=INT_MAX;
void tsp(int cur,int rem, int cost)
{
	if(rem==0)
	{
		//cout<<"HIH"<<endl;
		if(mat[cur][1]!=0)
			ans= min(ans,cost+mat[cur][1]);
		return;
	}
	//cout<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		//cout<<"Hello"<<endl;
		if(!vis[i] && mat[cur][i])
		{
			vis[i]=1;
			tsp(i,rem-1,cost+ mat[cur][i]);
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

	int tt;
	cin>>tt;
	while(tt--)
	{
		int m,i,j;
		ans=INT_MAX;

		cin>>n;
		
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				cin>>mat[i][j];
		for(i=1;i<=n;i++)
			vis[i]=0;
		//cout<<n<<endl;
		vis[1]=1;
		tsp(1,n-1,0);
		cout<<ans<<endl;
	}
}