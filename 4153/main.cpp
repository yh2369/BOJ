#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    long long a, b, c;
    while(true)
    {
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0)
        {
            break;
        }
        vector<long long> arr(3,0);
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        sort(arr.begin(), arr.end());
        if(arr[0] * arr[0] + arr[1]* arr[1] == arr[2] * arr[2])
        {
            cout << "right\n";
        }
        else
        {
            cout << "wrong\n";
        }
    }
    return 0;
}