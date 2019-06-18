#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int l = 0, u = rows - 1;
    while(l <= u)
    {
        int m = (l + u)/2;
        if(matrix[m][cols-1] < target)
            l = m + 1;
        else if(matrix[m][0] > target)
            u = m - 1;
        else
            break;
    }
    int s = 0, e = cols - 1;
    while(s <= e)
    {
        int m = (s + e)/2;
        if(matrix[l][m] > target)
            e = m - 1;
        else if(matrix[l][m] < target)
            s = m + 1;
        else
            return true;
    }
    return false;
}

int main(){
    vector<vector<int>> m;
    m.push_back(vector<int>{1, 3, 5, 7});
    m.push_back(vector<int>{10,11,16,20});
    m.push_back(vector<int>{23,30,34,50});
    m.push_back(vector<int>{53,60,64,70});
    cout << searchMatrix(m, 4) << endl;
    return 0;
}