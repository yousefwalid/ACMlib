const int N = 1e5+10;
int dp[N];
vector<int> a,path;

int LIS()
{
    for(int i=0;i<N;i++) dp[i] = 1;
    for(int i=1;i<a.size();i++)
        for(int j=0;j<i;j++)
            if(a[i] > a[j] && dp[i] < dp[j]+1)
                dp[i] = dp[j] + 1;

    int ans = 0, mx = 0, idx = 0;

    for(int i=0;i<N;i++)
        if(dp[i] > mx)
            mx = dp[i],idx=i;

    ans = mx;

    for(int i=idx;i>=0;i--)
        if(dp[i] == mx)
            path.pb(a[i]),mx--;

    reverse(path.begin(),path.end());

    return ans;
}