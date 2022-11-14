#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CalculateNum(int start[2], int end[2], vector<vector<int>> board)
{
    int row = 1;
    int col = 1;

    if (start[0] == end[0] && start[1] == end[1])
    {
        return 1;
    }

    int TmpX = 0;
    for (int i = start[0] + 1; i <= end[0]; i++)
    {
        if (board[i][start[1]] != 0 || i == end[0])
        {
            row++;
            TmpX = i;
        }
    }
    for (int i = start[0] - 1; i >= end[0]; i--)
    {
        if (board[i][start[1]] != 0 || i == end[0])
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
    for (int i = start[1] - 1; i >= end[1]; i--)
    {
        if (board[TmpX][i] != 0)
        {
            row++;
        }
    }

    int TmpY = 0;
    for (int i = start[1] + 1; i <= end[1]; i++)
    {
        if (board[start[0]][i] != 0 || i == end[1])
        {
            col++;
            TmpY = i;
        }
    }
    for (int i = start[1] - 1; i >= end[1]; i--)
    {
        if (board[start[0]][i] != 0 || i == end[1])
        {
            col++;
            TmpY = i;
        }
    }

    for (int i = start[0] + 1; i <= end[0]; i++)
    {
        if (board[i][TmpY] != 0 || i == 0)
        {
            col++;
        }
    }
    for (int i = start[0] - 1; i >= end[0]; i--)
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
    int end1[2];
    int answer = 0;
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
    score[0] = 0;

    while (1)
    {
        int MaxScore = 0;
        int num = 0;
        int MinDistance = 10;
        for (int i = 0; i < 6; i++)
        {
            if (score[i] >= MaxScore)
            {
                int d = CalculateNum(position,)
                MaxScore = score[i];
                num = i;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << answer << endl;
        cout << endl;

        if (MaxScore == 0)
        {
            break;
        }

        distance.clear();
        P.clear();
        int OnOff = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == num && OnOff == 0)
                {
                    end[0] = i;
                    end[1] = j;
                    distance.push_back(CalculateNum(position, end, board));
                    P.push_back(end);
                    OnOff = 1;
                }
                else if (board[i][j] == num && OnOff == 1)
                {
                    end1[0] = i;
                    end1[1] = j;
                    distance.push_back(CalculateNum(position, end1, board));
                    P.push_back(end1);
                }
            }
        }

        if (distance[0] >= distance[1])
        {
            answer += distance[1];
            board[P[1][0]][P[1][1]] = 0;
            position[0] = P[1][0];
            position[1] = P[1][1];
            answer += CalculateNum(position, P[0], board);
            board[P[0][0]][P[0][1]] = 0;
            position[0] = P[0][0];
            position[1] = P[0][1];
        }
        else if (distance[0] < distance[1])
        {
            answer += distance[0];
            board[P[0][0]][P[0][1]] = 0;
            position[0] = P[0][0];
            position[1] = P[0][1];
            cout << answer << endl;
            answer += CalculateNum(position, P[1], board);
            cout << answer << endl;
            cout << endl;
            board[P[1][0]][P[1][1]] = 0;
            position[0] = P[1][0];
            position[1] = P[1][1];
        }
        score[num] = 0;
    }

    return answer;
}

int main()
{
    vector<vector<int>> board = { {1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0} };
    //int s[2] = { 1,0 };
    //int e[2] = { 2,3 };
    //int result = CalculateNum(s, e, board);
    int result = solution(board, 1, 0);
    cout << result;
    int j;
    cin >> j;
}