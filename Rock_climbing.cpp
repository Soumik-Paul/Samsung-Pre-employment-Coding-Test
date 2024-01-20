/*
Raka wants to climb a rock from a starting point to the destination point. Given a map of the rock mountain which N = height, M = width. In the map, character '-' is the possible foot place spot (where he can climb). He can freely move up/down at vertical spots which '-' exists sequentially. It's impossible to move horizontally in case '-' is not consecutive in the same height level. The maximum height of moving from the starting point to the destination point is the level of difficulty of rock climbing . The total distance of movement is not important.
There is more than one path from the starting point to the destination point. 
Output: The minimum level of difficulty of all rock climbing paths level.
Constraints

1 <= N,M <= 10

Output Format

Single interger "level"

Sample Input 0

5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1

Sample Output 0

2

*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int vis[20][20]; 
int mat[11][11];
int n,m,mini;
void climb(int x,int y,int cost)
{
	if(mat[x][y]==3)
	{
		mini= min(mini,cost);
		return;
	}

	vector<pair <int,int> > v;
	//4 different ways explore

	if(mat[x][y-1]!=0 && y-1>=1) v.pb({x,y-1});
	if(mat[x][y+1]!=0 && y+1<=m) v.pb({x,y+1});
	int row =x-1;
	while(row>=1) // climbing up
	{
		if(mat[row][y]!=0) v.pb({row,y});
		row--;
	}
	row= x+1 ; // climbing down
	while(row<=n) // climbing up
	{
		if(mat[row][y]!=0) v.pb({row,y});
		row++;
	}


	for(auto i : v)
	{
		int r,c;
		r= i.first;
		c= i.second;
		if(!vis[r][c])
		{
			vis[r][c]++;
			int temp= abs(x-r);
			climb(r,c,max(cost,temp));
			vis[r][c]--;
		}
	}

}
int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif
	mini= INT_MAX;

	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>mat[i][j];
	climb(n,1,0);
	cout<<mini<<endl;
	






	return 0;
}