#include <iostream>
#include <algorithm>

using namespace std;
int N,M;
char board[54][54];
char chess_board_W[8][8];
char chess_board_B[8][8];

void print_chess_board(char c);
int calc_to_fill(int x, int y);

int calc_to_fill(int x, int y)
{
    int cnt_B =0; int cnt_W = 0;
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if(board[x+i][y+j] != chess_board_B[i][j])
            {
                cnt_B++;
            }
        }
    }

    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if(board[x+i][y+j] != chess_board_W[i][j])
            {
                cnt_W++;
            }
        }
    }
    return min(cnt_B, cnt_W);
}

void print_chess_board(char c)
{
    if(c == 'B')
    {
        for(int i = 0; i<8; i++)
        {
            for(int j = 0; j<8; j++)
            {
                cout << chess_board_B[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    else
    {
        for(int i = 0; i<8; i++)
        {
            for(int j = 0; j<8; j++)
            {
                cout << chess_board_W[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    chess_board_B[0][0] = 'B';
    char prev = 'B';
    
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if( i== 0 && j==0) continue;
            if(prev == 'B')
            {
                chess_board_B[i][j] = 'W';
                prev = 'W';
            }
            else
            {
                chess_board_B[i][j] = 'B';
                prev = 'B';
            }
        }
        if(prev == 'B')
        {
            prev = 'W';
        }
        else
        {
            prev = 'B';
        }
    }
    //print_chess_board('B');
    chess_board_W[0][0] = 'W';
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if( i== 0 && j==0) continue;
            if(prev == 'B')
            {
                chess_board_W[i][j] = 'W';
                prev = 'W';
            }
            else
            {
                chess_board_W[i][j] = 'B';
                prev = 'B';
            }
        }
        if(prev == 'B')
        {
            prev = 'W';
        }
        else
        {
            prev = 'B';
        }
    }
    //print_chess_board('W');

    cin >> N >> M;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin >> board[i][j];
        }
    }

    int dx = N - 7;
    int dy = M - 7;
    int min_to_fill = 987654321;
    for(int i = 0; i<dx; i++)
    {
        for(int j = 0; j<dy; j++)
        {
            int to_fill = calc_to_fill(i, j);
            min_to_fill = min(min_to_fill, to_fill);
        }
    }

    cout << min_to_fill << "\n";
    return 0;
}