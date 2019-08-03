const int N=1e5+10;
int n, BIT[N];

void UpdateIndex(int idx,int value) // O(logn) - Updates value of a certain index 
{
	for(;idx<=n;idx+=idx&-idx)
		BIT[idx]+=value;
}

int GetAns(int idx) // O(logn) - Gets answer in range [1:idx]
{
	int sum = 0;
	for(;idx;idx-=(idx&-idx))
		sum+=BIT[idx];
	return sum;
}
