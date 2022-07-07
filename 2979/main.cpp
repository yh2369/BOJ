#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int A, B, C;
    cin >> A >> B >> C;
    
    int from1, to1, from2, to2, from3, to3;
    cin >> from1 >> to1;
    cin >> from2 >> to2;
    cin >> from3 >> to3;

    int min_time = min(min(from1, from2), from3);
    int max_time = max(max(to1, to2), to3);


    vector<int> duration_arr(max_time, 0);

    for(int i = min_time; i <max_time; i++)
    {
        if( from1 <= i && i < to1)
        {
            duration_arr[i]++;
        }
        if(from2<=i && i <to2)
        {
            duration_arr[i]++;
        }
        if(from3 <=i && i <to3)
        {
            duration_arr[i]++;
        }
    }

    int cost = 0;
    for(int i = min_time; i<max_time; i++)
    {
        switch(duration_arr[i])
        {
            case 1:
                cost += A;
                break;
            case 2:
                cost += B * 2;
                break;
            case 3:
                cost += C * 3;
                break;
            default:
                break;
        }
    }
    cout << cost << endl;
    return 0;
}