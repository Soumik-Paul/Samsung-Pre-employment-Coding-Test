

#include<iostream>
#include<queue>
using namespace std;
#define inf 1e9

int dijkstra(int graph[][101], int n){
    int dist[2*n+2];
    for(int i = 0; i < 2 *n + 2;i++){
        dist[i] = inf;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
   // queue<pair<int,int> > q;
    q.push({0,0});
    
    while(!q.empty()){
        auto curr = q.top(); q.pop();
        int node = curr.first;
        int wt = curr.second;
        for(int i = 0; i < 2 * n + 2; i++){
            int nextNode = i;
            int adjWt = graph[i][node];
            if(wt + adjWt < dist[nextNode]){
                dist[nextNode] = wt + adjWt;
                q.push({nextNode,dist[nextNode]});
            }
        }
    }
    return dist[1];
}

int main(){
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif

    int t;
    cin>>t;
    while(t--){
        int graph[101][101];
        int n;
        cin>>n;
        int x[2*n + 2], y[2*n + 2];

        cin>>x[0]>>y[0]>>x[1]>>y[1];


        for(int i = 0; i < 2*n+2; i++){
            for(int j = 0; j < 2*n+2; j++){
                graph[i][j] = -1;
            }
        }

        for(int i = 2; i < 2*n+2; i+=2){
            int cost;
            cin>>x[i]>>y[i]>>x[i+1]>>y[i+1]>>cost;
            graph[i][i+1] = cost;
            graph[i+1][i] = cost;
        }
        
        for(int i = 0; i < 2*n+2; i++){
            for(int j = 0; j < 2*n+2; j++){
                if(graph[i][j] != -1){
                    continue;
                }
                graph[i][j] = abs(x[i]-x[j]) + abs(y[i] - y[j]);
            }
        }
        cout<<dijkstra(graph, n)<<endl;
    }
    return 0;
} 