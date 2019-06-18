#include<iostream>
#include<vector>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    int m = 0;
    if(matrix.size() == 0)
        return m;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int ** a = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        a[i] = new int[cols];
        for(int j = 0; j < cols; j++)
            a[i][j] = 0;
    }
    
    if(matrix[0][0] == '1')//第一个数
    {
        a[0][0] = 1;
        m = 1;
    } 
    for(int i = 1; i < rows; i++)//第一列
    {
        if(matrix[i][0] == '1')
            a[i][0] = a[i-1][0] + 1;
        if(m < a[i][0])
            m = a[i][0];
    }
    for(int j = 1; j < rows; j++)//第一行
    {
        if(matrix[0][j] == '1')
            a[0][j] = a[0][j-1] + 1;
        if(m < a[0][j])
            m = a[0][j];
    }
    
    for(int i = 1; i < rows; i++)
    {
        for(int j = 1; j < cols; j++)
        {
            if(matrix[i][j] == '0')
                a[i][j] = 0;
            else
            {
                if(matrix[i-1][j] == '0' && matrix[i][j-1] == '0')
                    a[i][j] = 1;
                else if(matrix[i-1][j] == '1' && matrix[i][j-1] == '1' && matrix[i-1][j-1] == '1')    
                    a[i][j] = a[i-1][j] * a[i][j-1] / a[i-1][j-1];
                else
                    a[i][j] = max(a[i-1][j], a[i][j-1]) + 1;
            }
            
            if(m < a[i][j])
                m = a[i][j];
            
        }
    }
    return m;
}

int main()
{
    vector<vector<char>> m;
    vector<char> vec0{'1','0','1','0','0'};
    m.push_back(vec0);
    vector<char> vec1{'1','0','1','1','1'};
    m.push_back(vec1);
    vector<char> vec2{'1','1','1','1','1'};
    m.push_back(vec2);
    vector<char> vec3{'1','0','0','1','0'};
    m.push_back(vec3);
    cout << maximalRectangle(m) <<endl;
    return 0;
}