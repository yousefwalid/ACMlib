const int N = 1e5+5;
vector<int> adj[N];


int visited[N];
 
void dfs(int u){
	visited[u] = 1;
	for(int i=0;i<adj[u].size();i++){
		int v = adj[u][i];
		if(!visited[v])
			dfs(v);
	}
}