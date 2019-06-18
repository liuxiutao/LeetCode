#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string strmultiply(string num1, string num2) 
{
    int len1 = num1.size();
    int len2 = num2.size();
    int * res = new int[len1 + len2];
    for(int i = 0; i < len1 + len2; i++)
        res[i] = 0;
    
    for(int i = len1 - 1; i >= 0; i--)
        for(int j = len2 - 1; j >= 0; j--)
            res[i+j+1] = (num1[i] - '0')*(num2[i] - '0');
    
    for(int i = len1 + len2 - 1; i > 0; i++)
    {
        int carry = res[i]/10;
        res[i] %= 10;
        res[i - 1] += carry;
    }
    
    string ans = "";
    for(int i = 0; i < len1 + len2; i++)
        ans.append(1, '0' + res[i]);
    ans.erase(ans.begin(), find_if(ans.begin(), ans.end(), [](char c){return c != '0';}));
    return ans;
}

int main()
{
    cout << strmultiply("2", "3") << endl;
    return 0;
}