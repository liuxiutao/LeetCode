#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isScramble(string s1, string s2) {
    int n = s1.size();
    bool res = false;
    if(s1.compare(s2) == 0)
    {
        res = true;
    }
    else
    {
        
        for(int k = 0; k < n - 1; k++)
        {
            res = res || (isScramble(s1.substr(0, k + 1), s2.substr(n - k - 1)) && isScramble(s1.substr(k+1), s2.substr(0, n - k - 1)));
            if(res == true)
                break;
            res = res || (isScramble(s1.substr(0, k + 1), s2.substr(0, k + 1)) && isScramble(s1.substr(k+1), s2.substr(k + 1)));
            if(res == true)
                break;

        }
    }
    
    return res;
}

bool isScramble1(string s1, string s2) {
    int n = s1.size();
    if(s2.size() !=  n)
        return false;
    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));
    for(int l = 1; l <= n; l++)
    {
        for(int i = 0; i <= n - l; i++)
        {
            for(int j = 0; j <= n - l; j++)
            {
                if(l == 1 && s1[i] == s2[j])
                    dp[l][i][j] = true;
                for(int k = 1; k < l; k++)
                {
                    dp[l][i][j] = dp[l][i][j] || (dp[k][i][j] && dp[l - k][i + k][j + k]);
                    dp[l][i][j] = dp[l][i][j] || (dp[k][i][j+l-k] && dp[l - k][i + k][j]);
                    if(dp[l][i][j] == true)
                        break;
                }
                    
            }
        }
    }
    return dp[n][n-1][n-1];
}

int main()
{
    string s1 = "ab", s2 = "ba";
    cout << isScramble1(s1, s2) << endl;
    return 0;
}