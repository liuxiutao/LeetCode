#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l <= r)
    {
        int m = (l+r)/2;
        if(nums[m] == target)
            return m;
        if(nums[l] <= nums[m])
        {
            if(nums[l] <= target && target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }
        else
        {
            if(nums[m] < target && target <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec{3, 1};
    cout << search(vec, 1) << endl;
    return 0;
}