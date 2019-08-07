#include<iostream>
#include<string>
#include<vector>

using namespace std;


vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    bool hasOper = false;
    for (int i = 0; i < input.length(); i++)
    {
        switch (input[i])
        {
            case '+':
            {
                hasOper = true;
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i+1));
                for (auto r1: res1)
                {
                    for(auto r2: res2)
                        res.push_back(r1 + r2);
                }
                break;
            }

            case '-':
            {
                hasOper = true;
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i+1));
                for (auto r1: res1)
                {
                    for(auto r2: res2)
                        res.push_back(r1 - r2);
                }
                break;
            }

            case '*':
            {
                hasOper = true;
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i+1));
                for (auto r1: res1)
                {
                    for(auto r2: res2)
                        res.push_back(r1 * r2);
                }
                break;
            }

            default:
                break;
        }
    }
    if(hasOper == false)
    {
        res.push_back(stoi(input));
    }

    return res;
}

int main()
{
    vector<int> res = diffWaysToCompute("2*3-4*5");
    for(auto r: res)
        cout << r << endl;
    return 0;
}