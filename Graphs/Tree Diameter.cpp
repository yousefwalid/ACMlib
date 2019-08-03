const int N = 1e5+5;
int sp[N];


int bfs(int u)
{
    queue<int> q;
    q.push(u);
    memset(dis,-1,sizeof(dis));
    sp[u] = 0;

    while(!q.empty())
    {
        u = q.front();
        q.pop;

        for(auto v : edges[u])
        {
            if(sp[v] == -1)
                sp[v] = sp[u] + 1;
                q.push(v);
        }
    }

    return u;
}

int calcTreeDiameter(int root)
{
    int u = bfs(root);
    int v = bfs(u);
    return sp[v];
}