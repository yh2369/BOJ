#include <iostream>

using namespace std;

int main()
{
    int arr[42] = {0,};
    for(int i = 0; i< 10; i++)
    {
        int n;
        cin >> n;
        int r = n % 42;
        arr[r]++;
    }
    int cnt = 0;
    for(int i = 0; i<42; i++)
    {
        if(arr[i] > 0)
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}