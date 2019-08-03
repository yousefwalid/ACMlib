// Size = 4*N as there are children to the leaves
// The array a[N] is 1-based so as to correspond to the Build function

const int N=1e5+10;
int n,a[N]; // Don't redefine n
int seg[4*N],lazy[4*N];
 
 
void propagate(int ind, int l, int r) // Propagate contains l,r for summation values
{
	seg[ind*2+1]|=lazy[ind]; 
	seg[ind*2+2]|=lazy[ind];
	lazy[ind*2+1]|=lazy[ind];
	lazy[ind*2+2]|=lazy[ind];
	lazy[ind]=0;
}
 
void Build(int ind=0, int l=1, int r=n) // O(nlogn)
{
	if(l==r)
	{
		seg[ind]=a[l];
		return;
	}
	int mid=l+(r-l)/2;
	Build(ind*2+1,l,mid);
	Build(ind*2+2,mid+1,r);
	seg[ind]=seg[ind*2+1]|seg[ind*2+2];
}
 
void UpdateIndex(int qind,int qv, int ind=0, int l=1, int r=n) // O(logn)
{
	if(qind<l || qind>r)	return;
	if(l==r)
	{
		seg[ind]|=qv;
		return;
	}
	int mid=l+(r-l)/2;
	UpdateIndex(qind,qv,ind*2+1,l,mid);
	UpdateIndex(qind,qv,ind*2+2,mid+1,r);
	seg[ind]=seg[ind*2+1]|seg[ind*2+2];
}
 
void UpdateRange(int qx, int qy, int qv, int ind=0, int l=1, int r=n) // O(logn) with lazy propagation
{
	if(r<qx || l>qy)    return;
	if(l>=qx && r<=qy)
	{
		seg[ind]|=qv;
		lazy[ind]|=qv;
		return;
	}
	int mid=l+(r-l)/2;
	propagate(ind, l, r);
	UpdateRange(qx,qy,qv,ind*2+1,l,mid);
	UpdateRange(qx,qy,qv,ind*2+2,mid+1,r);

	seg[ind]=seg[ind*2+1]|seg[ind*2+2];
}
 
int GetAns(int qx, int qy, int ind=0, int l=1, int r=n, bool isRangeProblem=0) // O(logn)
{
	if(r<qx || l>qy)	return 0;
	if(l>=qx && r<=qy)	return seg[ind];
	int mid=l+(r-l)/2;
	if(isRangeProblem)	propagate(ind, l, r);
	int r1=GetAns(qx,qy,ind*2+1,l,mid,isRangeProblem);
	int r2=GetAns(qx,qy,ind*2+2,mid+1,r,isRangeProblem);
	return r1|r2;
}