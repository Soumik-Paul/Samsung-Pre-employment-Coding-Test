/*
2 
5 6 2 1 3 
0 0 5 3 6 0 
0 0 2 0 2 0 
3 3 1 3 7 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
5 6 2 2 6 
3 0 0 0 0 3 
2 0 0 0 0 6 
1 3 1 1 3 1 
2 0 2 0 0 2 
0 0 4 3 1 1

*/

#include<iostream>
#include<vector>
#include <queue>
using namespace std;
#define pb push_back
int mat[60][60];
int n,m,len;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool upor(int x,int y)
{
	if (mat[x][y]==1||mat[x][y]==2||mat[x][y]==5||mat[x][y]==6) return true;
	else return false;
}
bool nich(int x,int y)
{
	if (mat[x][y]==1||mat[x][y]==2||mat[x][y]==4||mat[x][y]==7) return true;
	else return false;
}
bool dan(int x,int y)
{
	if (mat[x][y]==1||mat[x][y]==3||mat[x][y]==6||mat[x][y]==7) return true;
	else return false;
}
bool bam(int x,int y)
{
	if (mat[x][y]==1||mat[x][y]==3||mat[x][y]==4||mat[x][y]==5) return true;
	else return false;
}
bool valid(int i, int j)
{
	return (i>=1 && i<=n && j>=1&& j<=m ) ;
}
int bfs(int si, int sj, int len, int vis[60][60])
{
	if(mat[si][sj]==0) return 0;
	queue< pair <pair <int,int> , int > > q;
	q.push({{si,sj},1});
	vis[si][sj]=1;
	int ans=0;
	while(!q.empty()){

		auto p= q.front();
		q.pop();
		int i = p.first.first;
		int j= p.first.second;
		int c= p.second;
		if(c>len) continue;
		ans++;
		for(int d=0;d<4;d++)
		{
			
			int xi,yi;
			xi= i+dx[d];
			yi= j+dy[d];
			//cout<<i<<" "<<j<<" "<<vis[xi][yi]<<" "<<mat[xi][yi]<<" mat "<<endl;
			if(xi>=1 && xi<=n && yi>=1 && yi<=m && vis[xi][yi]==0 && mat[xi][yi]!=0)
			{
				//cout<<dan(i,j)<<endl;
				if(d==1 && dan(i,j) && bam(xi,yi)) 
				{
					vis[xi][yi]= 1;
					q.push({{xi,yi},c+1});
				}

				else if(d==0 && bam(i,j) && dan(xi,yi)) 
				{
					vis[xi][yi]= 1;
					q.push({{xi,yi},c+1});
				}

				else if(d==3 && nich(i,j) && upor(xi,yi)) 
				{
					vis[xi][yi]= 1;
					q.push({{xi,yi},c+1});
				}
				else if(d==2 && upor(i,j) && nich(xi,yi)) 
				{
					vis[xi][yi]= 1;
					q.push({{xi,yi},c+1});
				}


			}

		}
	}
	return ans;
}

void solve()
{
	int a,b,i,j;
	cin>>n>>m>>a>>b>>len;
	
	int vis[60][60];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>mat[i][j];
			vis[i][j]=0;
		}
	int cnt =bfs(a+1,b+1,len,vis);
	
	
	cout<<cnt<<endl;


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
		solve();

}