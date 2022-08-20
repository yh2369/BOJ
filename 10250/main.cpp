/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int cards[104];

void combi(int n, int k, int start, vector<int>& b, vector<vector<int>>& dst)
{
    if(b.size() == k)
    {
        dst.push_back(b);
        return;
    }
    
    for(int i = start+1; i < n; i++)
    {
        b.push_back(i);
        combi(n, k, i, b, dst);
        b.pop_back();
    }
}

int T, H, W, N;

void room(int H, int W, int N)
{
    int cnt = 1;
    for(int j = 1; j<= W; j++)
    {
        for(int k = 1; k<= H; k++)
        {
            if(cnt == N)
            {
                cout << k;
                if(j < 10)
                {
                    cout << 0 << j << "\n";
                }
                else
                {
                    cout << j << "\n";
                }
                return;
            }
            cnt++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    for(int i = 0; i< T; i++)
    {
        cin >> H >> W >> N;
        room(H, W, N);
        
    }
    
    return 0;
}
