#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

bool oneChange(string a, string b)
{
    int diff = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
        {
            ++diff;
            if(diff > 1)
                return false;
        }
    }
    if(diff == 1)
        return true;
    else
        return false;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {  
    int len = wordList.size();
    vector<bool> isVisited(len, false);
    queue<int> que;
    int res = 2;
    int i = 0;
    while(i < len)
    {
        if(oneChange(beginWord, wordList[i]))
        {
            if(endWord == wordList[i])
                return res;
            que.push(i);
            isVisited[i] = true;
        }
        i++;
    }
    que.push(-1);
    while(!que.empty())
    {
        int p = que.front();
        que.pop();
        if(p == -1)
        {
            if(!que.empty())
            {
                res++;
                que.push(-1);
            }  
            else
                res = 0;
        } 
        else
        {
            i = 0;
            while(i < len)
            {
                if(!isVisited[i] && oneChange(wordList[p], wordList[i]))
                {
                    if(wordList[i] == endWord)
                        return res + 1;
                    que.push(i);
                    isVisited[i] = true;
                }
                i++;
            }
        }
    }
    return res;
}

int main()
{
    vector<string> vec{"hot","dog"};
    string b = "hot";
    string e = "dog";
    cout << ladderLength(b, e, vec) << endl;
    return 0;
}
