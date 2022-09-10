#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

tuple<int,int,int> recursive_solution(vector<vector<int>>& matrix), int x, int y);

tuple<int,int,int> recursive_solution(vector<vector<int>>& matrix, int x, int y)
{
    int N = matrix.size();

    if(N == 1)
    {
        if(matrix[x][y] == -1)
        {
            return make_tuple(1, 0 ,0);
        }
        else if(matrix[x][y] == 0)
        {
            return make_tuple(0, 1 ,0);
        }
        else if(matrix[x][y] == 1)
        {
            return make_tuple(0, 0 ,1);
        }
    }

    if(N == 3)
    {
        bool all_eq = true;
        int num = matrix[0][0];
        for(int i = 0; i<N; i++)
        {
            for(int j = 0;j<N; j++)
            {
                if(num != matrix[x+i][y+j])
                {
                    all_eq = false;
                    break;
                }
            }
            if(all_eq == false)
            {
                break;
            }
        }

        if(all_eq)
        {
            if(num == -1)
            {
                return make_tuple(1, 0 ,0);
            }
            else if(num == 0)
            {
                return make_tuple(0, 1 ,0);
            }
            else if(num == 1)
            {
                return make_tuple(0, 0 ,1);
            }
        }
        else
        {
            int cnt0 = 0;
            int cnt1 = 0;
            int cnt2 = 0;
            for(int i = 0;i <N; i++)
            {
                for(int j = 0; j<N; j++)
                {
                    if(matrix[x+i][y+j] == -1)
                    {
                        cnt0++;
                    }
                    else if(matrix[x+i][y+j] == 0)
                    {
                        cnt1++;
                    }
                    else if(matrix[x+i][y+j] == 1)
                    {
                        cnt2++;
                    }
                }
            }
            return make_tuple(cnt0, cnt1, cnt2);
        }
    }

    

    return make_tuple(0,0,0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N, 0));
    for(int i = 0; i<N; i++)
    {
        for(int j =0; j<N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    auto t = recursive_solution (matrix);
    cout << get<0>(t) << "\n";
    cout << get<1>(t) << "\n";
    cout << get<2>(t) << "\n";
    return 0;
}