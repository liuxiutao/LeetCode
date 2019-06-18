#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct Data {
    int val; 
    int freq;
    Data(int v, int f):val(v), freq(f){}
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for(auto a : nums) 
    {
        mp[a]++;
    }
    
    vector<Data> vc;
    for(auto it : mp)
    {
        vc.push_back(Data(it.first, it.second));
    }
    sort(vc.begin(), vc.end(), [](Data d1, Data d2) { return d1.freq > d2.freq;});
    for (auto e : vc)
    {
        cout << e.val << " " << e.freq << endl;
    }
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(vc[i].val);
    }
    return res;
}

int main()
{
    vector<int> nums = vector<int>{1, 1, 1, 2, 2, 3};
    vector<int> res = topKFrequent(nums, 2);
    return 0;
}