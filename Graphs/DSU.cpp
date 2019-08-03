const int N = 1e5+5; 

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