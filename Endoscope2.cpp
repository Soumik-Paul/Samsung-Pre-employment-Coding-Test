
#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
int mat[60][60];
int n,m;
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

void endo(int x, int y,int len, int vis[60][60])
{
	if(len==0 || mat[x][y] ==0) return;
	vis[x][y]=1;
	vector<pair <int,int> > v;
	if(mat[x][y]==1)
	{
		if((x-1)>=1 && upor(x-1,y) ) v.pb({x-1,y});
		if(x+1 <= n && nich(x+1,y)) v.pb({x+1,y});
		if(y-1 >=1 && bam(x,y-1)) v.pb({x,y-1});
		if(y+1<=m && dan(x,y+1)) v.pb({x,y+1});
	}
	if(mat[x][y]==2)
	{
		if((x-1)>=1 && upor(x-1,y) ) v.pb({x-1,y});
		if(x+1 <= n && nich(x+1,y)) v.pb({x+1,y});
	}
	if(mat[x][y]==3)
	{
		if(y-1 >=1 && bam(x,y-1)) v.pb({x,y-1});
		if(y+1<=m && dan(x,y+1)) v.pb({x,y+1});
	}
	if(mat[x][y]==4)
	{
		if((x-1)>=1 && upor(x-1,y) ) v.pb({x-1,y});
		if(y+1<=m && dan(x,y+1)) v.pb({x,y+1});
	}
	if(mat[x][y]==5)
	{
		if(x+1 <= n && nich(x+1,y)) v.pb({x+1,y});
		if(y+1<=m && dan(x,y+1)) v.pb({x,y+1});
	}
	if(mat[x][y]==6)
	{
		if(x+1 <= n && nich(x+1,y)) v.pb({x+1,y});
		if(y-1 >=1 && bam(x,y-1)) v.pb({x,y-1});
	}
	if(mat[x][y]==7)
	{
		if((x-1)>=1 && upor(x-1,y) ) v.pb({x-1,y});
		if(y-1 >=1 && bam(x,y-1)) v.pb({x,y-1});

	}


	for(auto i: v)
	{
		int xx = i.first;
		int yy= i.second;
		endo(xx,yy,len-1,vis);
	}

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
    	int a,b,i,j,len;
    	int vis[60][60];
    	cin>>n>>m>>a>>b>>len;
    	for(i=1;i<=n;i++)
    		for(j=1;j<=m;j++)
    		{
    			cin>>mat[i][j];
    			vis[i][j]=0;
    		}
    		endo(a+1,b+1,len,vis);
    		int count=0;
    		for(i=1;i<=n;i++)
    			for(j=1;j<=m;j++)
    					if(vis[i][j]) count++;
    		cout<<count<<endl;
    }


	return 0;

}