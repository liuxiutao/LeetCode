#include<iostream>
#include<string>

using namespace std;

bool isMatch(string& s, int sl, string& p, int pl)
{
    if(pl == p.size())
    {
        if(sl == s.size())
            return true;
        else
            return false;
    }
    else
    {
        if(sl < s.size() && (p[pl] == '?' || s[sl] == p[pl]))
            return isMatch(s, sl + 1, p, pl + 1);
        else if(p[pl] == '*')
            return isMatch(s, sl, p, pl + 1) ||(sl < s.size() && (isMatch(s, sl + 1, p, pl) || isMatch(s, sl+1, p, pl + 1)));
        else
            return false;
    }
}

int main()
{
    string s = "abbbaaabababbaaabbaaaaa";
    string p = "a***a**ba";
    cout << isMatch(s, 0, p, 0) << endl;
    return 0;
}