#include <string>
#include <vector>

using namespace std;

int CalculateNum(int start[2], int end[2], vector<vector<int>> board)
{
    int row = 0;
    int col = 0;

    int TmpX = 0;
    for (int i = start[0] + 1; i <= end[0]; i++)
    {
        if (board[i][start[1]] != 0)
        {
            row++;
            TmpX = i;
        }
    }
    for (int i = start[1] + 1; i <= end[1]; i++)
    {
        if (board[TmpX][i] != 0)
        {
            row++;
        }
    }

    int TmpY = 0;
    for (int i = start[1] + 1; i <= end[1]; i++)
    {
        if (board[start[0]][i] != 0)
        {
            col++;
            TmpY = i;
        }
    }
    for (int i = start[0] + 1; i <= end[0]; i++)
    {
        if (board[i][TmpY] != 0)
        {
            col++;
        }
    }
    if (row >= col)
    {
        return col;
    }
    else if (row < col)
    {
        return row;
    }
}

int solution(vector<vector<int>> board, int r, int c) 
{
    int score[6] = {0,};
    int position[2] = { r,c };
    int end[2];
    vector<int> distance;
    vector<int*> P;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != 0 && i != 3 && j != 0 && j != 3)
            {
                score[board[i][j]] += 100;
            }
            else if (i == 0 && j == 0)
            {
                score[board[i][j]] += 1;
            }
            else if (i == 0 && j == 3)
            {
                score[board[i][j]] += 1;
            }
            else if (i == 3 && j == 0)
            {
                score[board[i][j]] += 1;
            }
            else if (i == 3 && j == 3)
            {
                score[board[i][j]] += 1;
            }
            else
            {
                score[board[i][j]] += 10;
            }
        }
    }

    while (1)
    {
        int MaxNum = 0;
        int num = 0;
        for (int i = 0; i < 6; i++)
        {
            if (score[i] > MaxNum)
            {
                MaxNum = score[i];
                num = i;
            }
        }

        distance.clear();
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == num)
                {
                    end[0] = i;
                    end[1] = j;
                    distance.push_back(CalculateNum(position, end, board));
                    P.push_back(end);
                }
            }
        }
    }
    int answer = 0;
    return answer;
}