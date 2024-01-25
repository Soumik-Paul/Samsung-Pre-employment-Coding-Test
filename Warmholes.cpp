/*
There is a source (S) and destination (D) and a spacecraft has to go from S to D. There are N number of wormholes in between which has following properties:

Each wormhole has an entry and an exit. Each wormhole is bi-directional i.e. one can enter and exit from any of the ends. The time to cross the wormhole is given and the space craft may or may not use the wormhole to reach D. The cost to travel outside wormhole between two points (x1, y1) and (x2, y2) is given by a formula |x1 - x2| + |y1 - y2|

where, (x1, y1) and (x2, y2) are the co-ordinates of two points. The co-ordinates of S and D are given and we have to find the minimum cost to reach D from S. The main problem here is to minimum cost to reach spaceship from source to destination co-ordinate using any number of warm-hole. It is ok if you wont use any warmhole.

Note: It’s not mandatory to consider all the wormholes

Input Format

First line contains t, number of test cases

There are N number of warmholes each warmhole has 5 values. First 2 values are starting co-ordinate of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th value is represents cost to pass through this warmhole.

Line 1 contains value of N. Line 2 Conatins Source and Destination coordinate. Next N lines contain the warmhole information.

Constraints

1 < t < 10 1 < N < 6 -1 < x < 101 -1 < y < 101 0 < cost < 101

Output Format

Output a single integer (minimum cost)

Sample Input 

1
3
0 0 100 100
1 2 120 120 16
2 5 120 100 21
6 8 150 180 16

Sample Output 

48


*/

#include <bits/stdc++.h>
using namespace std;

struct point{
	int x,y;
};


struct tube{
	int x1,y1,x2,y2,cost;
};

point s,d;
tube holes[15];
int n,ans;

int dis(point a,point b)
{
	return abs(a.x-b.x)+ abs(a.y-b.y);
}

void warmhole(point s, point d, int vis[],int cost)
{
	ans = min(ans,cost+dis(s,d)); //base case, checking from source to destination

	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			point left,right;
			left.x= holes[i].x1;
			left.y= holes[i].y1;
			right.x= holes[i].x2;
			right.y= holes[i].y2;

			warmhole(right,d,vis, cost+ dis(s,left)+ holes[i].cost);
			warmhole(left,d,vis,cost+dis(s,right)+holes[i].cost);
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

	int tt,i;
	cin>>tt;
	while(tt--)
	{
		ans= 1000000;
		int vis[10];
		cin>>n;
		cin>>s.x>>s.y>>d.x>>d.y;

		for(i=1;i<=n;i++)
		{
			cin>>holes[i].x1>>holes[i].y1>>holes[i].x2>>holes[i].y2>>holes[i].cost;
			vis[i]=0;
		}
		warmhole(s,d,vis,0);
		cout<<ans<<endl;
	}
}