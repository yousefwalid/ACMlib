int const N = 1e5+10;
int const nN = 2*N;
int id,ID[N],rID[N],First[N],ST[nN][logN],lg[nN];
vector<int>vec;
 
void dfs(int cur,int par)
{
	ID[cur] = id++;		// Creating ur own ID by euler tour.
	rID[ID[cur]] = cur; 	// reverseID to get back to the original node name.
	vec.push_back(ID[cur]);		//Push ur tour.
	for(auto x:adj[cur])
		if(x!=par)
        	dfs(x,cur),vec.push_back(ID[cur]);
}

inline void Build()
{
	int cnt = 0,two = 1;
    while(two<nN) lg[two] = cnt++,two*=2;
    for(int i=3;i<nN;++i) if(!lg[i]) lg[i] = lg[i-1];	//Create an array to get the log of any number [nearest log].
	//the previous part should be done only one time! Put it before the test cases.
 
	int nN = sz(vec);
	memset(First,-1,sizeof First);
 
	for(int i=0;i<nN;++i)		// Fill the "First" array. remeber this array contains the idx of the first appearence of an id.
    	ST[i][0] = vec[i],(First[vec[i]]==-1? First[vec[i]]=i:0);
 
	// Bulding the sparse table.        
	for(int i=1;(1<<i) <= nN;++i)
    	for(int j=0;j+(1<<i)-1<nN;++j)
        	ST[j][i] = min(ST[j][i-1],ST[j+(1<<(i-1))][i-1]);
}

inline int LCA(int a,int b)
{
	int L,R,idx,d,lca;
	a = ID[a]; b = ID[b];		// Go to ur domain.
	L = First[a], R =First[b];
	if(L>R) swap(L,R);
	d = R-L+1;
	d = lg[d];
	idx = R - (1<<d) + 1;
	lca = min(ST[L][d],ST[idx][d]);
	lca = rID[lca];
	a = rID[a]; b = rID[b];			//Back to main domain.
	return lca;
}