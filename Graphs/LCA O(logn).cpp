const int N = 1e5+10;
const int logN = 20;
int ST[logN][N],depth[N];
 
void dfs(int cur, int par)
{
	ST[0][cur] = par;
 
	for(int i=1;i<logN;++i)
		ST[i][cur] = ST[i-1][ST[i-1][cur]];
 
	for (auto x:adj[cur])
		if(x != par)
			depth[x]=depth[cur]+1,dfs(x, cur);
}

int KthAncestor(int u, int k)
{
	if(!k) return u;
	int d = depth[u] - k;	// Get the depth of the wanted node.
	for (int j = logN-1; j >= 0; --j)
	{
		int nu = ST[j][u];
		if (!nu) continue;
		if (depth[nu] == d) return nu;
		else if (depth[nu] > d && u) u = nu;
	}
 
	return 0;
}

int LCA(int a, int b)
{
	if (depth[a] > depth[b]) a = KthAncestor(a, depth[a] - depth[b]);	// make them at the same depth.
	else if(depth[b] > depth[a]) b = KthAncestor(b, depth[b] - depth[a]);
 
	if (a == b) return a;
 
	for (int j = logN-1; j >= 0; --j)
		if (ST[j][b] != ST[j][a]) 
			a = ST[j][a], b = ST[j][b];
 
	return ST[0][a];
}