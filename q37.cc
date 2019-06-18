#include<iostream>
#include<vector>

using namespace std;

bool func(vector<vector<char>>& b, int i, int j, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& block)
{
    if(j == 9){j = 0; i += 1;}
    if(i > 8){ return true; }
    if(b[i][j] != '.'){ return func(b, i, j+1, row, col, block);}
    
    int bn = (i/3) * 3 + (j / 3);
    for(int k = 1; k < 10; k++)
    {
        if(row[i][k] == false && col[j][k] == false && block[bn][k] == false)
        {
            b[i][j] = '0' + k;
            row[i][k] = col[j][k] = block[bn][k] = true;
            if(func(b, i, j+1, row, col, block))
                return true;
            row[i][k] = col[j][k] = block[bn][k] = false;
            b[i][j] = '.';
        }
    }
    return false;       
}

void solveSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> col(9, vector<bool>(10, false));
    vector<vector<bool>> row(9, vector<bool>(10, false));
    vector<vector<bool>> block(9, vector<bool>(10, false));
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        { 
            if(board[i][j] != '.')
            {
                int n = board[i][j] - '0';
                int bn = (i/3) *3 + (j/3);
                row[i][n] = col[j][n] = block[bn][n] = true;
            }
        }
    }
    func(board, 0, 0, row, col, block);        
}

int main()
{
    vector<vector<char>> b;
    b.push_back(vector<char>{'5','3','.','.','7','.','.','.','.'});
    b.push_back(vector<char>{'6','.','.','1','9','5','.','.','.'});
    b.push_back(vector<char>{'.','9','8','.','.','.','.','6','.'});
    b.push_back(vector<char>{'8','.','.','.','6','.','.','.','3'});
    b.push_back(vector<char>{'4','.','.','8','.','3','.','.','1'});
    b.push_back(vector<char>{'7','.','.','.','2','.','.','.','6'});
    b.push_back(vector<char>{'.','6','.','.','.','.','2','8','.'});
    b.push_back(vector<char>{'.','.','.','4','1','9','.','.','5'});
    b.push_back(vector<char>{'.','.','.','.','8','.','.','7','9'});

    solveSudoku(b);

    for(auto e: b)
    {
        for(auto c: e)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}