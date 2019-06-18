#include<iostream>
#include<vector>
#include<unordered_multiset>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_multiset<int> mp;
        for(auto e : nums2)
            mp.insert(e);
        for(auto e : nums1)
        {
            if(mp.count(e) > 0)
            {
                ans.push_back(e);
                mp.erase(e);
            }  
        }
        return ans;
}