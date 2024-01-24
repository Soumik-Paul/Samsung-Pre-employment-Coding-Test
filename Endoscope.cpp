#include<iostream>
#include<vector>
using namespace std;
#define pb push_back
int mat[60][60];
int n,m,len;

void go(int x, int y, int len, int vis[60][60])
{
	if(len==0|| mat[x][y]==0)
		return;
	vis[x][y]=1;
	vector<pair <int,int> > v;

	if(mat[x][y]==1)
	{
		if(x-1>=1 && (mat[x-1][y]==1||mat[x-1][y]==2||mat[x-1][y]==5||mat[x-1][y]==6)) 
			v.pb({x-1,y});
		if(x+1<=n && (mat[x+1][y]==1 || mat[x+1][y]==2 || mat[x+1][y]==4 || mat[x+1][y]==7 ))
			v.pb({x+1,y});
		if(y-1>=1 && (mat[x][y-1]==1 || mat[x][y-1]==3 || mat[x][y-1]==4||mat[x][y-1]==5))
			v.pb({x,y-1});
		if(y+1<=m && (mat[x][y+1]==1 || mat[x][y+1]==3 || mat[x][y+1]==6 || mat[x][y+1]==7))
			v.pb({x,y+1});

	}
	if(mat[x][y]==2)
	{
		if(x-1>=1 && (mat[x-1][y]==1||mat[x-1][y]==2||mat[x-1][y]==5||mat[x-1][y]==6)) 
			v.pb({x-1,y});
		if(x+1<=n && (mat[x+1][y]==1 || mat[x+1][y]==2 || mat[x+1][y]==4 || mat[x+1][y]==7 ))
			v.pb({x+1,y});
	}
	if (mat[x][y]==3)
	{
		if(y-1>=1 && (mat[x][y-1]==1 || mat[x][y-1]==3 || mat[x][y-1]==4||mat[x][y-1]==5))
			v.pb({x,y-1});
		if(y+1<=m && (mat[x][y+1]==1 || mat[x][y+1]==3 || mat[x][y+1]==6 ||mat[x][y+1]==7))
			v.pb({x,y+1});
	}
	if(mat[x][y]==4)
	{
		if(x-1>=1 && (mat[x-1][y]==1||mat[x-1][y]==2||mat[x-1][y]==5||mat[x-1][y]==6)) 
			v.pb({x-1,y});
		if(y+1<=m && (mat[x][y+1]==1 || mat[x][y+1]==3 || mat[x][y+1]==6 || mat[x][y+1]==7))
			v.pb({x,y+1});

	}
	if(mat[x][y]==5)
	{
		if(x+1<=n && (mat[x+1][y]==1 || mat[x+1][y]==2 || mat[x+1][y]==4 || mat[x+1][y]==7 ))
			v.pb({x+1,y});
		if(y+1<=m && (mat[x][y+1]==1 || mat[x][y+1]==3 || mat[x][y+1]==6 || mat[x][y+1]==7))
			v.pb({x,y+1});

	}
	if(mat[x][y]==6)
	{
		if(x+1<=n && (mat[x+1][y]==1 || mat[x+1][y]==2 || mat[x+1][y]==4 || mat[x+1][y]==7 ))
			v.pb({x+1,y});

		if(y-1>=1 && (mat[x][y-1]==1 || mat[x][y-1]==3 || mat[x][y-1]==4||mat[x][y-1]==5))
			v.pb({x,y-1});

	}
	if(mat[x][y]==7)
	{
		if(x-1>=1 && (mat[x-1][y]==1||mat[x-1][y]==2||mat[x-1][y]==5||mat[x-1][y]==6)) 
			v.pb({x-1,y});



		if(y-1>=1 && (mat[x][y-1]==1 || mat[x][y-1]==3 || mat[x][y-1]==4 ||mat[x][y-1]==5))
			v.pb({x,y-1});

	}

	for(auto i: v)
   {
     int xx=i.first,yy=i.second;
     go(xx,yy,len-1,vis);
   }
   

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
	go(a+1,b+1,len,vis);
	int cnt=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(vis[i][j])
				cnt++;
		}
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