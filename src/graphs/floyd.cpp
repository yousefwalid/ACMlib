// Shortest path between all pairs of nodes, negative edges allowed, no negative cycles

int n; // Number of nodes
int adj[n][n]; // adj[u][v] = cost of edge from u to v

void init()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j] = (i==j? 0 : oo); // Sets adj[u][u] = 0, adj[u][v] = oo if no edge exists
}

void floyd()
{
    init();
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
}

bool checkNegativeCycle()
{
    bool ret = false;
    for(int i=0;i<n;i++)
        ret = ret || (adj[i][i] < 0);
    return ret;
}
