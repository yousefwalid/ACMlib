vector<int> vec1,vec2;
int dp[5005][5005];

int LCS(int i, int j)
{
    if(i == vec1.size() || j == vec2.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(vec1[i] == vec2[j])
        return dp[i][j] = LCS(i+1,j+1) +1;
    return dp[i][j] = max(LCS(i,j+1) , LCS(i+1,j));
}