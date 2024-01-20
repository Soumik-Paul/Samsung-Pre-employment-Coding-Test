/*
Given a 2 D matrix where 1 represent the places where the frog can jump and 0 represent the empty spaces,
the frog can move freely in horizontal direction (on 1’s only) without incurring any cost (jump).
A vertical jump from a given point of the matrix to other point on the matrix can be taken (on 1’s only)
with cost as the number of jumps taken.
Given a source and destination, the frog has to reach the destination minimizing the cost (jump).

Input
5
0 1 1 0 1
1 0 0 1 0
1 0 0 0 1
0 1 0 1 1
1 0 1 1 1
4 2 1 3

Output
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

	cin>>n;
	m=n;
	int i,j,s1,s2,d1,d2;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>mat[i][j];
	cin>>s1>>s2>>d1>>d2;
	mat[d1+1][d2+1]=3;

	climb(s1+1,s2+1,0);
	cout<<mini<<endl;
	






	return 0;
}