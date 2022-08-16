#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed;
    cout.precision(3);
    int C;
    cin >> C;
    for(int i = 0; i<C; i++)
    {
        int N;
        cin >> N;
        vector<int> v(N,0);
        int sum = 0;
        
        for(int j = 0; j<N; j++)
        {
            cin >> v[j];
            sum += v[j];
        }
        double mean = sum*(1.0) / N;
        double percentage = 0.0;
        int cnt = 0;
        for(int j = 0; j<N; j++)
        {
            if(v[j] > mean)
            {
                cnt++;
            }
        }
        percentage = cnt * (100.0) / N;
        cout << percentage << "%\n";
    }
    return 0;
}
