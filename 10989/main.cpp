#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    int num;
    cin >> N;
    vector<int> counter(10001, 0);
    int max_num = SHRT_MIN;
    
    for(int i = 0; i<N; i++)
    {
        cin >> num;
        max_num = max(num , max_num);
        counter[num]++;
    }
    
    for(int i = 0; i<=max_num; i++)
    {
        while(counter[i] > 0)
        {
            cout << i << "\n";
            counter[i]--;
        }
    }

    


   
    return 0;
}