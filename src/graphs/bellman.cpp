// Shortest path from source to all nodes, negative edges allowed, no negative cycle
const int N = 1e5+5;

vector<pair<int,int> > adj[N];
int n,par[N]; // n is number of nodes

bool bellmanFord(int source)
{
    memset(par,-1,sizeof par);
    memset(dis, 0x3F, sizeof(dis));
    dis[source] = 0;

    bool updated = 1;

    for(int k=0;k<n && updated;k++)
    {
        updated = 0;
        for(int u = 1; u<=n;u++)
        {
            for(auto& e : edges[u])
            {
                int v = e.first; 
                int c = e.second;

                if(dis[v] > dis[u] + c)
                {
                    dis[v] = dis[u] + c;
                    par[v] = u;
                    updated = 1;
                }
            }
        }
    }

    return updated; // Whether a negative cycle exist or not
}