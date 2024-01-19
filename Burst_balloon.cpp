/*
There are N Balloons marked with value Bi (where B(i…N)). 
User will be given Gun with N Bullets and user must shot N times. 
When any balloon explodes then its adjacent balloons becomes next to each other. 
User has to score highest points to get the prize and score starts at 0. 
Below is the condition to calculate the score. 
When Balloon Bi Explodes then score will be a product of Bi-1 & Bi+1 (score = Bi-1 * Bi+1). When Balloon Bi Explodes and there is only left Balloon present then score will be Bi-1. When Balloon Bi Explodes and there is only right Balloon present then score will be Bi+1. When Balloon Bi explodes and there is no left and right Balloon present then score will be Bi. Write a program to score maximum points.

Input 4 1 2 3 4

Output

20
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int ans,n;
vector<int> v;
vector<vector<int>> dp;
int burst(int i, int j)
{
	
	if(i>j) return 0 ;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans= INT_MIN;
	for(int index=i; index<=j;index++)
	{
		int cost=0;
		if(i==1 && j==n)
          cost=v[index]+burst(i,index-1)+burst(index+1,j);

		else cost= v[i-1]*v[j+1] + burst(i,index-1) + burst(index+1,j);

		dp[i][j]= max(dp[i][j],cost);
	}
	return dp[i][j];
}
int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif

	
	v.pb(1);
	int i,x;
	cin>>n;
	ans= INT_MIN;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		v.pb(x);

	}
	v.pb(1);
	dp.assign(n+1,vector<int>(n+1,-1));
	
	cout<<burst(1,n)<<endl;
}