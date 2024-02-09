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
int n;
int dp[1<<20][20];
int mat[20][20];
int ans;

int tsp(int mask, int pos)
{
   //cout<<"Tsp "<<mask<<endl;
   if(mask == ((1<<n)-1)) // if n = 4 then 1<<4 gives 10000 . so 10000-1=1111
      return mat[pos][0];
   if(dp[mask][pos]!=-1) 
      return dp[mask][pos];
   int ans= INT_MAX;
   for(int city=0;city<n;city++)
   {
      if((mask&(1<<city))==0)
      {
         
         int local = mat[pos][city] + tsp(mask|(1<<city),city);
         ans= min(ans,local);
      }
   }
   return dp[mask][pos]= ans;
  
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
     
      int res=10000000;
      cin>>n;
     // cout<<n<<endl;
      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            cin>>mat[i][j];
         for(int i=0;i<(1<<n);i++)
            for(int j=0;j<n;j++)
               dp[i][j]=-1;
            
             
          
    res = tsp(1,0);
    cout<<res<<endl;
        
         
    }

   
}
