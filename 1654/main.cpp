#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;
int K, N;

bool cmp(long long a, long long b)
{
    return a > b;
}

void printV(vector<long long>& v);
int get_lan_num(vector<long long>& length_arr, long long target_lan_length);

void printV(vector<long long>& v)
{
    int n = v.size();
    for(int i = 0; i<n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

int get_lan_num(vector<long long>& length_arr, long long target_lan_length)
{
    int k= length_arr.size();
    int ret = 0;
    for(int i = 0; i<k; i++)
    {
        ret += length_arr[i] / target_lan_length;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> K >> N;
    vector<long long> length_arr(K, 0);
    for(int i =0; i<K; i++)
    {
        cin >> length_arr[i];
    }
    
    sort(length_arr.begin(), length_arr.end(), cmp);
    //printV(length_arr);
    
    long long a = 0; 
    long long b = length_arr[0];
    long long target_lan_length = 0;
    if(K == 1)
    {
        cout << b / N << "\n";
        return 0;
    }
    if(b == 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    while(true)
    {
        target_lan_length = (a+b)/2;
        //cout <<"[@@@@ target_lan_length: " << target_lan_length << " @@@@]";
        int lan_num = get_lan_num(length_arr, target_lan_length);
        //cout << " [@@@@ lan_num: " << lan_num << " @@@@]\n";
        if(lan_num < N)
        {
            b = target_lan_length;
        }
        else
        {
            a = target_lan_length;
            if(b == (a+1))
            {
                break;
            }
        }
    }
    if(get_lan_num(length_arr, target_lan_length + 1) >= N)
    {
        cout << target_lan_length + 1 << "\n";
    }
    else
    {
        cout << target_lan_length << "\n";
    }
    

    //assert(get_lan_num(length_arr, target_lan_length + 1) < N);


    return 0;
}