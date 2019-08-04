const int N = 1e5+5;

vector< pair< int, pair<int,int> > edges; // {cost, {u,v}}

int par[N];
int num[N];
 
for(int i=0;i<N;i++) // Initialization in main
{  
	par[i] = i;
	num[i] = 1;
}

int FindSet(int n) // Use FindSet instead of par
{
	if(par[n] == n)
		return n;
	return par[n] = find_set(par[n]);
}
 
void Union(int x,int y)
{
	x = find_set(x);
	y = find_set(y);
	if(x==y)
		return;
	par[x]=y;
	num[y] += num[x]; // num holds number of elements in a group
}

int getMST() // Returns summation of edges of Minimum Spanning Tree and builds the tree in DSU
{
    int sum = 0;
    sort(edges.begin(),edges.end());
    //reverse(edges.begin(), edges().end());  // Uncomment for Max. spanning tree
    for(auto e : edges)
    {
        int u = e.s.f; int v = e.s.s;
        if(FindSet(u) == FindSet(v))
            continue;
        Union(u,v);
        sum+=e.f;
    }
    return sum;
}
