#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int trap(vector<int>& height) {
    int len = height.size();

    stack<int> mstk;
    int res = 0;
    for(int i = len - 1; i > 1; i--)
    {
        if(mstk.empty())
            mstk.push(height[i]);
        else
        {
            int tmp = mstk.top();
            if(height[i] > tmp)
                mstk.push(height[i]);
            else
                mstk.push(tmp);
        }
    }
    int lm = height[0];
    for(int i = 1; i < len - 1; i++)
    {
        int rm = mstk.top();
        int c = lm < rm? lm - height[i]: rm - height[i];
        if(c > 0)
            res += c;
        if(lm < height[i])
            lm = height[i];
        mstk.pop();
    }
    return res;
}

int main()
{
    vector<int> vec{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(vec) << endl;
    return 0;
}