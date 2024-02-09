/*
https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/kim-and-refrigerators

Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home. 
Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) . 
The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value 
of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the customers are all distinct. You should plan an optimal way 
to visit all the N customers and return to his among all the possibilities.
You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10. 
Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. 
Your program only have to report the distance of a (the) shortest path.

Constraints

5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.

Input

You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers, and the 
following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence. Each location consists of 
the coordinates (x,y), which is reprensented by ‘x y’.
Output

Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path. Each line looks like ‘#x answer’ 
where x is the index of a test case. ‘#x’ and ‘answer’ are separated by a space.

I/O Example

Input (20 lines in total. In the first test case, the locations of the office and the home are (0, 0) and (100, 100) respectively, 
and the locations of the customers are (70, 40), (30, 10), (10, 5), (90, 70), (50, 20).)

5 ← Starting test case #1

0 0 100 100 70 40 30 10 10 5 90 70 50 20

6 ← Starting test case #2

88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14


Output (10 lines in total)

#1 200

#2 304

*/
#include <bits/stdc++.h>
using namespace std;
int ans,n;

struct point{
	int x,y;
};

int dis(point a, point b)
{
	return abs(a.x-b.x) + abs(a.y-b.y);
}

int dp[(1<<20)][20];

point cust[20];
point office,home;


int func(int mask, int pos)
{
	//cout<<n<<endl;

	if(mask == ((1 << n) - 1))
		{
			//cout<<dis(cust[pos],cust[n+1])<<endl;
			return dis(cust[pos],cust[n+1]);
		}

	if(dp[mask][pos]!=-1) return dp[mask][pos];

	int mini= INT_MAX;

	for(int i=0;i<n;i++)
	{

		if((mask&(1<<i))) continue;
		else
		{
			//cout<<i<<endl;
			int x=dis(cust[i+1],cust[pos]) + func((mask|(1<<i)),i+1);
			
			mini= min(mini,x);

		}
	}
	return dp[mask][pos]= mini;

  
}
main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif

	int tt,id=0;
	cin>>tt;
	while(tt--)
	{
		id++;
		int i,j;
		//ans=10000001;
		int vis[20];
		cin>>n;

		cin>>cust[0].x>>cust[0].y>>cust[n+1].x>>cust[n+1].y ;
		for(i=1;i<=n;i++){
			cin>>cust[i].x>>cust[i].y ;
			vis[i]=0;
		}
		 for(int i=0;i<(1<<n+1);i++)
            for(int j=0;j<n+1;j++)
               dp[i][j]=-1;

           // memset(dp,-1,sizeof dp);

	int ans1 = func(0,0);
	cout << "# " << id<< " " << ans1 << endl;

	}
}