#include<iostream>
#include<vector>
using namespace std;

bool func(vector<int> & c, int index, int target, vector<int> ans, vector<vector<int>>& res)
{
    if(target < 0)
        return true;
    else if(target == 0)
    {
        res.push_back(ans);
        return true;
    }
    else
    {
        for(int i = index; i < c.size(); i++)
        {
            ans.push_back(c[i]);
            if(func(c, i, target - c[i], ans, res))
                break;
            ans.pop_back();
        }
        return false;
    }   
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> ans;
    func(candidates, 0, target, ans, res);
    return res;
}

int main()
{
    vector<int> vec{2, 3, 6, 7};
    auto res = combinationSum(vec, 7);
    return 0;
}