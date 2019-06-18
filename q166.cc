#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    string res;
    if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
        res.push_back('-');
    long long n = abs(static_cast<long long>(numerator));
    long long d = abs(static_cast<long long>(denominator));
    
    long long remainder = n % d;
    long long quotients = n / d;
    res.append(to_string(quotients));
    if(remainder == 0)
        return res;
    res.push_back('.');
    vector<pair<int, int>> decimal;
    while(remainder != 0)
    {
        if(find_if(decimal.begin(), decimal.end(), [remainder](pair<int, int> a){return a.first == remainder;}) != decimal.end())
        {
            bool flag = false;
            for(auto e : decimal)
            {
                if(e.first == remainder)
                {
                    res.push_back('(');
                    flag = true;                        
                }
                res.push_back('0' + e.second);
            }
            if(flag)
                res.push_back(')');
            return res;
            
        }
        quotients = remainder * 10 / d;
        decimal.push_back(pair<int, int>(remainder, quotients));
        remainder = remainder * 10 % d;
    }
    if(remainder == 0)
    {
        for(auto e : decimal)
            res.push_back('0' + e.second);
    }
    return res;
}

int main()
{
    cout << fractionToDecimal(7, -12) << endl;
    return 0;
}