/*
Raka wants to climb a rock from a starting point to the destination point. Given a map of the rock mountain which N = height, M = width. In the map, character '-' is the possible foot place spot (where he can climb). He can freely move up/down at vertical spots which '-' exists sequentially. It's impossible to move horizontally in case '-' is not consecutive in the same height level. The maximum height of moving from the starting point to the destination point is the level of difficulty of rock climbing . The total distance of movement is not important.
There is more than one path from the starting point to the destination point. 
Output: The minimum level of difficulty of all rock climbing paths level.
Constraints

1 <= N,M <= 10

Output Format

Single interger "level"

Sample Input 0
1
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
int n,m,dx,dy,check;
int vis[60][60];
int mat[60][60];

void dfs(int i, int j)
{
    vis[i][j]=1;
    int k;
    for(k=1;k<=check;k++)
    {
        if(i-k>=1 && !vis[i-k][j] && mat[i-k][j])
            dfs(i-k,j);
        if(i+k<=n && !vis[i+k][j] && mat[i+k][j])
            dfs(i+k,j);

    }
    if(j-1>=1 && !vis[i][j-1] && mat[i][j-1])
            dfs(i,j-1);
        if(j+1<=m && !vis[i][j+1] && mat[i][j+1])
            dfs(i,j+1);
}

int go(int mid)
{
    check= mid;
    for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                vis[i][j]=0;
    dfs(n,1);
    return vis[dx][dy];
}

int main()
{
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

    #endif
    int tt,i,j;
    cin>>tt;
    while(tt--)
    {
        int ans=-1;
        cin>>n>>m;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                {
                    cin>>mat[i][j];
                    if(mat[i][j]==3)
                    {
                        dx=i;
                        dy=j;
                    }
                }
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid = r-(r-l)/2;
            if(go(mid))
            {
               
                ans=mid;
                r= mid-1;
            }
            else
            {
                    l= mid+1;
            }
        }
        cout<<ans<<endl;
    }
}