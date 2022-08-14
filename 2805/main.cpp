#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long N; // 나무의 수
long long M; // 가져가려는 나무의 길이

void printV(vector<long long>& v);
long long cut_tree(vector<long long>& height_arr, long long height);

void printV(vector<long long>& v)
{
    for(int i = 0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

long long cut_tree(vector<long long>& height_arr, long long height)
{
    int n= height_arr.size();
    long long ret = 0;
    for(int i =0; i<n; i++)
    {
        long long delta = height_arr[i] - height;
        if(delta > 0)
        {
            ret += delta;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    
    vector<long long> height_arr(N,0);
    long long max_height = 0;
    for(int i = 0; i< N; i++)
    {
        cin >> height_arr[i];
        max_height = max(max_height, height_arr[i]);
        
    }
    
    if( N == 1)
    {
        cout << height_arr[0] - M << "\n";
        return 0;
    }
    sort(height_arr.begin(), height_arr.end());

    long long a = 0; long long b = max_height;
    long long height = 0;
    while(true)
    {
        height = (a+b)/2LL;
        long long cut_tree_length = cut_tree(height_arr, height);
        if(cut_tree_length < M)
        {
            b = height;
        }
        else if(cut_tree_length >M)
        {
            a = height;
        }
        else
        {
            break;
        }
    }


    cout << height << "\n";
    return 0;
}