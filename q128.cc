#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n < 2)
        return n;
    set<int> st(nums.begin(), nums.end());
    int res = 1;
    int c = 1;
    auto it = st.begin();
    auto next_it = ++(st.begin());
    cout << st.size() << endl;
    for(; next_it != st.end(); ++next_it)
    {
        cout << *it << " " << *next_it << endl;
        if((*next_it - *it) == 1)
            ++c;
        else
        {
            res = max(res, c);
            c = 1;
        }
        it = next_it;
    }
    res = max(res, c);
    return res;
}

int main()
{
    vector<int> nums{0, -1};
    cout << longestConsecutive(nums) << endl;
    return 0;
}