#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
        int minlen = INT_MAX;
        int l = 0, r = 0;
        int sum = nums[0];
        while(l <= r)
        {
            while(sum < s && r + 1 < nums.size())
            {
                r += 1;
                sum += nums[r];
            }
            if(sum < s)
            {
                break;
            }
            while(sum >= s && l <= r)
            {
                minlen = min(minlen, r - l + 1);
                sum -= nums[l];
                l += 1;
            }
        }
        if(minlen == INT_MAX)
            return 0;
        else
            return minlen;
    }

int main()
{
    vector<int> a = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, a) << endl;
    return 0;
}