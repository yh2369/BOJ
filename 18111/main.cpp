#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


struct Compare {
	bool operator() (const int &a, const int &b) const{
		return a > b;
	}
};

int N, M, B;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> B;
    vector<vector<int>> height_v(N, vector<int>(M, 0));
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin >> height_v[i][j];
        }
    }

    int min_time = 987654321;
    int min_height = 257;
    set<int> ans_set;
    for(int h = 0; h<257; h++)
    {
        //cout << "[@@@@ h: " << h << " @@@@]\n";
        int time = 0;
        int b = B; 
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<M; j++)
            {
                if(height_v[i][j] > h)
                {
                    time += (height_v[i][j] - h) * 2;
                    b += (height_v[i][j] - h);
                }
                else if(height_v[i][j] < h)
                {
                    time += (h - height_v[i][j]);
                    b -= (h - height_v[i][j]);   
                }
                else
                {
                    continue;
                }
            }
        }

        if(b < 0)
        {
            break;
        }

        if(min_time < time)
        {
            break;
        }
        else if(min_time == time)
        {
            min_height = h;
        }
        else
        {
            min_time = time;
            min_height = h;
        }
    }
    
    cout << min_time << " " << min_height <<  "\n";
    return 0;
}