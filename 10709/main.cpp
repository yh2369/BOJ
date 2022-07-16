#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void print2DV(vector<vector<int>>& v, int H, int W)
{
    for(int i =0; i<H; i++)
    {
        for(int j = 0; j<W; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char>> cloud_map(H, vector<char>(W, '.'));
    vector<vector<int>> time_map(H, vector<int>(W, -1));
    for(int i = 0; i<H; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j<W; j++)
        {
            cloud_map[i][j] = s[j];
        }
    }

    //print2DV(cloud_map, H, W);

    for(int i =0; i<H; i++)
    {
        for(int j = 0; j<W; j++)
        {
            if(cloud_map[i][j] == 'c')
            {
                time_map[i][j] = 0;
            }
        }
    }

    for(int i = 0; i<H; i++)
    {
        for(int j =0 ; j<W; j++)
        {
            if(cloud_map[i][j] == '.')
            {
                for(int k = j-1; k>=0; k--)
                {
                    if(cloud_map[i][k] == 'c')
                    {
                        time_map[i][j] = (j-k);
                        break;
                    }
                }
            }
        }
    }
    print2DV(time_map, H, W);

    return 0;
}