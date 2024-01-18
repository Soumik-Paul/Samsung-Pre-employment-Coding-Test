/*
Given a matrix M of size N where M[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.

Example: Input: 2 2 0 111 112 0 3 0 1000 5000 5000 0 1000 1000 5000 0 Output: 223 3000

Input Format

Input: The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the matrix then in the next line are N*N space separated values of the matrix M.

Constraints

Constraints: 1<=T<=15 1<=N<=12 1<=M[][]<=10000

Output Format

Output: For each test case print the required result denoting the min cost of the tour in a new line.

Sample Input 0

2
2
0 111
112 0
3
0 1000 5000
5000 0 1000
1000  5000  0

Sample Output 0

223
3000


*/
#include <bits/stdc++.h>
using namespace std;

int matrix[13][13];
int mini;
int n;

void tsp(int cur,int rem, int *visited,int cost)
{
   if(rem==0){
       cost+=matrix[cur][1];
       mini= min(cost,mini);
       return;
   }

   for(int i=1;i<=n;i++)
   {
      if(!visited[i])
      {
         visited[i]=1;
         int temp=cost+matrix[cur][i];
         tsp(i,rem-1,visited,temp);
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

  int tt;
  tt = 1;
  cin>>tt;
  while (tt--)
  { 
   
   mini=10000000;
  
   
   cin>>n;
   int visited[20];
   
   for(int i=1;i<=n;i++)visited[i]=0;

   for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
         cin>>matrix[i][j];
   
   visited[1]=1;
   tsp(1,n-1,visited,0);
   cout<<mini<<endl;

  }
}