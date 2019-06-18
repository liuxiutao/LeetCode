#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    void oper(vector<vector<int>>& cb, int m, int n, int op) // op = 1 放置，op = 2 拿走
    {
        int len = cb.size();
        for(int i = 0; i < len; i ++)
            cb[i][n] += op;
        
        for(int j = 0; j < len; j ++)
            cb[m][j] += op;
        
        cb[m][n] -= op;
        
        for(int s = 1;;s++)
        {
            if(check(cb, m + s, n + s) == false)
                break;
            cb[m+s][n+s] += op;
        }
        for(int s = 1;;s++)
        {
            if(check(cb, m - s, n + s) == false)
                break;
            cb[m-s][n+s] += op;
        }
        for(int s = 1;;s++)
        {
            if(check(cb, m + s, n - s) == false)
                break;
            cb[m+s][n-s] += op;
        }
        for(int s = 1;;s++)
        {
            if(check(cb, m - s, n - s) == false)
                break;
            cb[m-s][n-s] += op;
        }
    }
    
    bool check(vector<vector<int>>& cb, int m, int n)
    {
        int len = cb.size();
        if(m < 0 || m >= len)
            return false;
        if(n < 0 || n >= len)
            return false;
        
        return true;
    }
    
    void put(vector<vector<int>>& ccb, int m, int n)
    {
        oper(ccb, m, n, 1);
    }
    
    void take(vector<vector<int>>& ccb, int m, int n)
    {
        oper(ccb, m, n, -1);
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cb(n, string(n, '.'));
        vector<vector<int>> ccb(n, vector<int>(n, 0));
        func(cb, ccb, 0, res);
        return res;
    }
    
    void func(vector<string> & cb, vector<vector<int>> & ccb, int row, vector<vector<string>> & res)
    {
        if(row >= cb.size())
        {
            res.push_back(cb);
            return;
        }
        for(int j = 0; j < cb.size(); j++)
        {
            if(ccb[row][j] == 0)
            {
                cb[row][j] = 'Q';
                put(ccb, row, j);
                func(cb, ccb, row+1, res);
                take(ccb, row, j);
                cb[row][j] = '.';
            }
        }
        
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ss = s.solveNQueens(4);
    for(auto v: ss)
    {
        for(auto sss: v)
            cout << sss << endl;
        cout << endl;
    }
    return 0;
}