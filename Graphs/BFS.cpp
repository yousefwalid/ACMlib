const int N = 1e5+5;
vector<int> adj[N];


int sp[N];

void bfs()
{
    memset(sp,-1,sizeof sp);
    queue<int> q;

    q.push(s); //pushes start
    sp[s] = 0;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
    
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(sp[v] == -1){
                q.push(v);
                sp[v] = sp[u] + 1;
            }
        }
    }
}
