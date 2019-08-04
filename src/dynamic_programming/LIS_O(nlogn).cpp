const int N = 1e5+5;

int n,a[N];

int getLIS()
{
    if(n<1) return 0;

    int len = 0;
    vector<int> LIS(n,oo);

    for(int i=0;i<n;i++)
    {
        int idx = lower_bound(LIS.begin(),LIS.end(),a[i]) - LIS.begin();
        LIS[idx] = a[i];
        len = max(len,idx);
    }

    return len+1;
}