#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int sl = s.size();
        int wn = words.size();
        if(sl == 0 || wn == 0)
            return res;
        int wl = words[0].size();
        unordered_map<string, int> counts;
        
        for(auto w: words)
            counts[w] += 1;
        for (int i = 0; i < sl - wn * wl; i++)
        {
            unordered_map<string, int> statistic;
            int j = 0;
            for (; j < wn; j++)
            {
                string ss = s.substr(i + j * wl, wl);
                if(counts.find(ss) != counts.end())
                {
                    statistic[ss] += 1;
                    if(statistic[ss] > counts[ss])
                        break;
                }
                else
                {
                    break;
                }
            }
            if(j == wn)
                cout << i << " ";
                //res.push_back(i);
        }
        return res;
}

int main()
{
    string s = "wordgoodgoodgoodbestword";
    vector<string> vec{"word","good","best","good"};
    findSubstring(s, vec);
    return 0;
}