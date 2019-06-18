#include<iostream>
#include<vector>
#include<deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i >= k)
            {
                res.push_back(nums[que.front()]);
                if(i - que.front() >= k)
                    que.pop_front();
            }
            while(!que.empty() && nums[i] > que.back())
                que.pop_back();
            que.push_back(i);  
            
        }
        return res;
    }

int main()
{
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    maxSlidingWindow(a, 3);
    return 0;
}