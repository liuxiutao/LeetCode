#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.length();
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for(int j = 0; j < len; j++)
        for(int i = j; i >= 0; i--)
        {
            dp[i][j] = (find(wordDict.begin(), wordDict.end(), s.substr(i, j - i + 1)) != wordDict.end());
            for(int k = i; k < j; k++)
            {
                if(dp[i][j])
                    break;
                dp[i][j] = dp[i][j] || (dp[i][k] && dp[k+1][j]);
            }
        }
    return dp[0][len-1];
}

int main()
{
    string s = "leetcode";
    vector<string> wd{"leet", "code"};
    cout << wordBreak(s, wd) << endl;
    return 0;
}