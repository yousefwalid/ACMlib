const int N = 1e5+5;
vector<int> adj[N];
int color[N];

bool isBipartiteGraph(int u=0, int c=0)
{
    memset(color,-1,sizeof color);
	for(auto v:adj[u]){
		if(color[v] == -1)
			dfs(v, !c);
		else if(color[v] == c)
			return false;
	}
    return true;
}