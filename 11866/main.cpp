#include <iostream>
#include <vector>


using namespace std;


int N, K;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    if(N == 1)
    {
        cout << "<1>\n";
        return 0;
    }
    vector<int> arr(N, 0);
    vector<int> answer;
    
    for(int i = 1; i<=N; i++)
    {
        arr[i-1] = i;
    }

    int current = 0;
    int left = N;
    cout << "<";
    do
    {
        for(int i = 0; i<K-1; i++)
        {
            current = (current + 1) % N;
            while(arr[current] == -1)
            {
                current = (current + 1) % N;
            }
        }
        //cout << "current: " << current<<"\n";
        cout << arr[current] << ", ";
        arr[current] = - 1;
        current = (current + 1) % N;
        while(arr[current] == -1)
        {
            current = (current + 1) % N;
        }
        left--;

    }while(left > 1);

    for(int i = 0; i<N; i++)
    {
        if(arr[i] != -1)
        {
            cout << arr[i] << ">\n";
            break;
        }
    }

    return 0;
}