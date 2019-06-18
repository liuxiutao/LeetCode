#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        if(n == 0)
            return false;
        for(int i = m - 1, j = 0; i >= 0 && j < n;)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                i -= 1;
            else
                j += 1;
        }
        return false;
    }

int main()
{
    vector<vector<int>> a(1, vector<int>{-1, 3});
    cout << searchMatrix(a, 3);
    return 0;
}