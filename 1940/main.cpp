#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> v(N, 0);
    for(int i = 0; i< N; i++)
    {
        cin >> v[i];
    }
    int cnt =0;
    for(int i = 0; i<N; i++)
    {
        for(int j = i+1; j<N; j++)
        {
            if(M == v[i] + v[j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}