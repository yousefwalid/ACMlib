// Dijkstra SP for weighted graph + path build, No negative edges
const int N = 1e5+5;
vector< pair<int,int> > adj[N]; // adj[u] = {v,cost}
vector<int> path;
int sp[N]; int par[N]; 

void build(int u) {
	while (u != -1) {
		path.pb(u);
		u = par[u];
	}

	reverse(path.begin(),path.end()); 	//The path is reversed, fix it
}

int Dijkstra(int source, int destination)
{
    int u,v,c;
    for (int i = 0; i < n; ++i) // initialization
    	sp[i] = oo, par[i] = -1;
 
    priority_queue< pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
    
    pq.push( { 0, source });
    sp[source] = 0;
    
    while (!pq.empty()) {
        u = pq.top().second;
        c = pq.top().first;
        pq.pop();
    
        if (sp[u] < c)
            continue;
    
        for (auto edge : adj[u]) {
            int to = edge.first;
            int cost = edge.second;
    
            if (c + cost < sp[to]) {
    
                sp[to] = c + cost;
                pq.push( { sp[to], to });
    
                //assign (u) as parent of (to) to rebuild the path
                par[to] = u;
            }
        }
    }
    
    build(destination); // Path is stored in path
    return sp[destination];
}