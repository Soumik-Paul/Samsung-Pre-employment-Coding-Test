/*
There are N fishing spots and 3 gates. At each gate there are some fishermen waiting to reach the nearest unoccupied fishing spot. (Total no of fisherman <=N)

Distance between consecutive spots = distance between gate and nearest spot = 1 m

Only 1 gate can be opened(other gates after that gate) at a time and all fishermen of that gate must occupy the spots before the next gate is opened.

Distance is calculated as gate to nearest spot + nearest spot to closest vacant spot. Find the total sum of minimum distances need to walk for all the fishermen.

Input Format

Number of fishing spots, N Position of the gates, Gi, 1 < i < 3 Number of fishermen at each gates, G_n_i

Constraints

1 <= N <= 10 1 <= G_i <= N 1 <= G_n_i <= 15

Output Format

Output single integer

Sample Input 0

10
4 6 10
5 2 2

Sample Output 0

18


*/
#include <bits/stdc++.h>
using namespace std;
int gate[4];
int fm[20];
int people,n,mini=INT_MAX;



int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif
	cin>>n;
	int i,j,k;
	for (int i = 0; i < 3; i++)
      cin >> gate[i];
  	for (int i = 0; i <3; i++)
      cin >> fm[i],people += fm[i];
   mini= INT_MAX;
   for(i=1;i<=n-(fm[0]+fm[1]+fm[2])+1;i++)
   	for(j=i+fm[0];j<=n-(fm[1]+fm[2])+1;j++)
   		for(k=j+fm[i];k<=n-(fm[2])+1;k++)
   		{
   			int p,ans=0;
   			for(p=i;p<i+fm[0];p++)
   				ans+= abs(p-gate[0])+1;
   			for(p=j;p<j+fm[1];p++)
   				ans+= abs(p-gate[1])+1;
   			for(p=k;p<k+fm[2];p++)
   				ans+= abs(p-gate[2])+1;
   			mini= min(ans,mini);
   		}



   cout<<mini<<endl;




	return 0;
}