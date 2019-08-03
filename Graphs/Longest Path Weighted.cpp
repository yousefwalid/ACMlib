const int N = 1e5+5;
vector<pair<int,int> > adj[N];

ll dfs(int u=0, int par=-1)
{
    ll ret = 0;
    for(int i=0;i<adj[u].size();i++)
        if(adj[u][i].f != par)
            ret = max(ret, dfs(adj[u][i].F,u) + adj[u][i].s);
    return ret;
}