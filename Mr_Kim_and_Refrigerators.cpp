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

point cust[20];
point office,home;


void func(int cur,int rem, int *visited,int cost)
{


   if(rem==0){
       cost+=abs(cust[cur].x-home.x)+abs(cust[cur].y-home.y);
       if(cost<ans) ans= cost;
       return;
   }

   for(int i=1;i<=n;i++)
   {
   	
      if(!visited[i])
      {

         visited[i]=1;
         int temp;
         if(cur==0) 
         	temp = cost + abs(office.x - cust[i].x)+abs(office.y - cust[i].y);
         else 
         	temp = cost + abs(cust[cur].x - cust[i].x)+abs(cust[cur].y - cust[i].y);
         func(i,rem-1,visited,temp);
         visited[i]=0;
      }
   }
}
main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif

	int tt=10,id=0;
	while(tt--)
	{
		id++;
		int i;
		ans=10000001;
		int vis[20];
		cin>>n;

		cin>>office.x>>office.y>>home.x>>home.y ;
		for(i=1;i<=n;i++){
			cin>>cust[i].x>>cust[i].y ;
			vis[i]=0;
		}

	func(0,n,vis,0);
	cout << "# " << id<< " " << ans << endl;

	}
}