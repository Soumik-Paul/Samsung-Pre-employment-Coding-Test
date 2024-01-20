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
int gate[3];
int fisherman[20];
int people,n,mini=INT_MAX;
void fish(int index,int count, int cost){
	if(count==people)
	{
		mini= min(mini,cost);
		return ;
	}

	if(index>n) return ;

	for(int i=1;i<=3;i++)
	{
		if(fisherman[i]>0)
		{
			fisherman[i]--;
			fish(index+1,count+1,cost+1+abs(gate[i]-index));
			fisherman[i]++;
		}
	}
	fish(index+1,count,cost);


}

int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif
	cin>>n;
	int i;
	for (int i = 1; i <= 3; i++)
      cin >> gate[i];
  	for (int i = 1; i <= 3; i++)
      cin >> fisherman[i],people += fisherman[i];
   fish(1,0,0);
   cout<<mini<<endl;




	return 0;
}