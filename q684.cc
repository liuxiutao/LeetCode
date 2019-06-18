#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class UFSet {
    vector<int> s;
    int count;
public:
    UFSet(int n) : s(n, -1), count(n){}

    int find(int x)
    {
        if(s[x] < 0)
            return x;
        else
            return s[x] = find(s[x]);
    }

    void unionSet(int root1, int root2)
    {
        if(find(root1) == find(root2))
            return;
        else
        {
            s[root2] = root1;
            count -= 1;
        }
    }
};


vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UFSet us(n+1);
    vector<int> ans;
    for(auto & e: edges)
    {
        if(us.find(e[0]) == us.find(e[1]))
        {
            ans.push_back(min(e[0], e[1]));
            ans.push_back(max(e[0], e[1]));
        }
        else
            us.unionSet(e[0], e[1]);
    }
    return ans;
}


int main()
{
    
}