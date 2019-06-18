#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
        // if(s1.size() + s2.size() != s3.size())
        //     return false;
        // return isInterleave(s1, 0, s2, 0, s3, 0);
        int len1 = s1.size(), len2 = s2.size();
        vector<vector<bool>> dp(len2+1, vector<bool>(len1 + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= len1; j++)
            dp[0][j] = dp[0][j - 1] && (s1[j - 1] == s3[j - 1]);
        for(int i = 1; i <= len2; i++)
            dp[i][0] = dp[i - 1][0] && (s2[i - 1] == s3[i - 1]);
        
        for(int i = 1; i <= len2; i++)
            for(int j = 1; j <= len1; j++)
            {
                if(dp[i-1][j])
                    dp[i][j] = dp[i][j] || (s2[i-1] == s3[i + j - 1]);
                if(dp[i][j-1])
                    dp[i][j] = dp[i][j] || (s1[j-1] == s3[i + j - 1]);
            }
        return dp[len2][len1];
}

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << isInterleave(s1, s2, s3);
    return 0;
}