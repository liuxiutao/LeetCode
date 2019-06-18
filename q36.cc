#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++)
    {
        set<char> s{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] != '.')
            {
                if(s.find(board[i][j]) != s.end())
                    s.erase(board[i][j]);
                else
                    return false;
            }
        }
    }
        
    for(int j = 0; j < 9; j++)
    {
        set<char> s{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int i = 0; i < 9; i++)
        { 
            if(board[i][j] != '.')
            {
                if(s.find(board[i][j]) != s.end())
                    s.erase(board[i][j]);
                else
                    return false;
            }
        }
    }
        
    for(int r = 0; r < 9; r+=3)
        for(int c = 0; c < 9; c += 3)
        {
            set<char> s{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {

                    if(board[r+i][c+j] != '.')
                    {
                        if(s.find(board[r+i][c+j]) != s.end())
                            s.erase(board[r+i][c+j]);
                        else
                            return false;
                    }
                }
            }
        }
    return true;
}

int main()
{
    vector<vector<char>> b;
    b.push_back(vector<char>{'.','.','4','.','.','.','6','3','.'});
    b.push_back(vector<char>{'.','.','.','.','.','.','.','.','.'});
    b.push_back(vector<char>{'5','.','.','.','.','.','.','9','.'});
    b.push_back(vector<char>{'.','.','.','5','6','.','.','.','.'});
    b.push_back(vector<char>{'4','.','3','.','.','.','.','.','1'});
    b.push_back(vector<char>{'.','.','.','7','.','.','.','.','.'});
    b.push_back(vector<char>{'.','.','.','5','.','.','.','.','.'});
    b.push_back(vector<char>{'.','.','.','.','.','.','.','.','.'});
    b.push_back(vector<char>{'.','.','.','.','.','.','.','.','.'});

    cout << isValidSudoku(b) << endl;

    return 0;
}