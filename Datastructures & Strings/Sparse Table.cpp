const int N = 1e5 + 5;
const int logN = 20;
int n, a[N], ST[logN][N], LOG[N];

void Build() // O(nlogn) - Builds the sparse table (min sparse table)
{
    LOG[0] = -1;
    for(int i=0;i<n;i++) // Computes floor(log2(i)) for all values
        ST[0][i] = i, LOG[i+1] = LOG[i] + !(i & (i+1));
    
    for(int j=1; (1<<j) <= n; j++)
        for(int i=0; (i +(1<<j)) <= n; i++)
            {
                int x = ST[j-1][i];
                int y = ST[j-1][i + (1<<(j-1))];

                ST[j][i] = (a[x] <= a[y] ? x : y); // Changes according to the operation
            }
}

int GetAns(int l, int r) // O(1) - Queries for the values from l to r
{
    int g = LOG[r-l+1];
    int x = ST[g][l];
    int y = ST[g][r - (1<<g) + 1];
    return (a[x] <= a[y] ? x : y); // Changes according to the operation
}
