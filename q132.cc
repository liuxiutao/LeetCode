#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

int minCut(string s) {
    int n = s.size();
    if(n <= 1)
        return 0;
    vector< vector<bool> > sdp(n, vector<bool>(n, false));
    for(int j = 0; j < n; j++)
        for(int i = j; i >= 0; i--)
        {
            if(i == j)
                sdp[i][j] = true;
            else if(i + 1 == j)
                sdp[i][j] = (s[i] == s[j]);
            else
                sdp[i][j] = (s[i] == s[j] && sdp[i + 1][j - 1]);
        }
    vector< vector<int> > dp(n, vector<int>(n, INT_MAX));
    for(int j = 0; j < n; j++)
        for(int i = j; i >= 0; i--)
        {
            if(sdp[i][j])
                dp[i][j] = 0;
            else
            {
                for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
            }
        }
    return dp[0][n-1];
}

int main(int argc, char const *argv[])
{
    cout << minCut("aab") << endl;
    return 0;
}
