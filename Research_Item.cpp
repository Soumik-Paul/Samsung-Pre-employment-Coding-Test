Research_Item.cpp
 #include<iostream>
 #include<vector>
 #include<queue>
 #include<climits>
 using namespace std;
 int n,k;
 vector<pair<int,int> > v;
 int matrix[25][25],visited[25][25],dist[25][25];
 int dx[]={1,-1,0,0};
 int dy[]={0,0,1,-1};

void clear()
{
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=n;j++)
    {
        dist[i][j]=INT_MAX;
    }
   }
}
int bfs(int x,int y)
 {
    queue <pair<int,int> > q;
    dist[x][y]=0;
    q.push({x,y});
    while(q.size())
    {
       auto z=q.front();
       q.pop();
       x=z.first, y=z.second;

       for(int i=0;i<4;i++)
       {
          int xx=x+dx[i];
          int yy=y+dy[i];
          if(xx>=1 && xx<=n && yy>=1 && yy<=n && matrix[xx][yy] && dist[xx][yy]> dist[x][y]+1)
          {
            dist[xx][yy]=dist[x][y]+1;
            q.push({xx,yy});
          }
       } 
    }
    int maxi=0;
    for(auto i: v)
    {
        x=i.first,y=i.second;
        maxi=max(maxi,dist[x][y]);
    }

    return maxi;

 }
 void solve()
 {
    v.clear();
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>matrix[i][j];
            dist[i][j]=INT_MAX;
        }
    }
    int mini=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(matrix[i][j])
            {
                int val=bfs(i,j);
                mini=min(mini,val);
                clear();
            }
            
        }
    }
    cout<<mini<<endl;


 }
 int main()
 {
    int tt;
    cin>>tt;
    while(tt--)
    {
        solve();
    }

    return 0;
 }