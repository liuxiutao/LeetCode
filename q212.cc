#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool func(vector<vector<char>>& b, vector<vector<bool>>& f, int i, int j, string & s, int p)
    {
        if(p == s.length())
            return true;
        bool res = false;

        if(i < 0 || i >= b.size() || j < 0 || j >= b[0].size())
            return false;
        if(b[i][j] == s[p] && f[i][j] == false)
        {
            f[i][j] = true;
            res = func(b, f, i - 1, j, s, p + 1)||
                func(b, f, i + 1, j, s, p + 1) ||
                func(b, f, i, j - 1, s, p + 1) ||
                func(b, f, i, j + 1, s, p + 1);
            f[i][j] = false;
            return res;
        }
        else
            return false;
        
    }

    bool check(vector<vector<char>>& b, string s)
    {
        int m = b.size();
        int n = b[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                vector<vector<bool>> f(m, vector<bool>(n, false));
                if(func(b, f, i, j, s, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        vector<string> res;
        int m = board.size();
        if(m == 0)
            return res;
        int n = board[0].size();
        if(n == 0)
            return res;
        
        sort(words.begin(), words.end());
        auto it = unique(words.begin(), words.end());
        words.erase(it, words.end());
        
        for(auto s : words)
        {
            if(check(board, s))
                res.push_back(s);
        }
        return res;
    }

int main()
{
    vector<vector<char>> board;
    board.push_back(vector<char>{'b', 'a', 'a', 'b', 'a', 'b'});
    board.push_back(vector<char>{'a', 'b', 'a', 'a', 'a', 'a'});
    board.push_back(vector<char>{'a', 'b', 'a', 'a', 'a', 'b'});
    board.push_back(vector<char>{'a', 'b', 'a', 'b', 'b', 'a'});
    board.push_back(vector<char>{'a', 'a', 'b', 'b', 'a', 'b'});
    board.push_back(vector<char>{'a', 'a', 'b', 'b', 'b', 'a'});
    board.push_back(vector<char>{'a', 'a', 'b', 'a', 'a', 'b'});
    cout << check(board, "aabbbbabbaababaaaabababbaaba");
    return 0;
}

//["aabbbbabbaababaaaabababbaaba","abaabbbaaaaababbbaaaaabbbaab","ababaababaaabbabbaabbaabbaba"]


