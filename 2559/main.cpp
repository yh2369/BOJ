#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> T(N, 0);
    for(int i=0; i< N; i++)
    {
        cin >> T[i];
    }

    int sum = 0;
    for(int i=0; i<K ; i++)
    {
        sum += T[i];
    }
    //cout << sum << endl;
    int max_sum = sum;
    for(int i = K; i<N; i++)
    {
        int new_sum = sum + T[i] - T[i-K];
        //cout << new_sum << endl;
        sum = new_sum;
        if(max_sum < new_sum){
            max_sum = new_sum;
        }
    }
    cout << max_sum << endl;

    return 0;
}