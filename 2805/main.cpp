#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long N; // 나무의 수
long long M; // 가져가려는 나무의 길이

void printV(vector<long long>& v);
void printV(vector<long long>& v)
{
    for(int i = 0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    map<long long, long long> height_cnt_table;
    vector<long long> height_arr(N,0);
    long long max_height = 0;
    for(int i = 0; i< N; i++)
    {
        cin >> height_arr[i];
        auto it = height_cnt_table.find(height_arr[i]);
        if( it != height_cnt_table.end())
        {
            height_cnt_table[height_arr[i]]++;
        }
        else
        {
            height_cnt_table.insert(make_pair(height_arr[i], 1));
        }
        max_height = max(max_height, height_arr[i]);
    }
    
    if( N == 1)
    {
        cout << height_arr[0] - M << "\n";
        return 0;
    }
    sort(height_arr.begin(), height_arr.end());

    /*
    for(auto it = height_cnt_table.begin(); it != height_cnt_table.end(); it++)
    {
        auto key = it->first;
        auto value = it->second;
        cout << key <<": " << value << "\n";
    }
    cout << "\n";
    */
    long long h = max_height;
    //cout << "h: " << h << "\n";
    
    while(h >= 0)
    {
        h--;
        long long sum =0;
        for(auto it = height_cnt_table.begin(); it != height_cnt_table.end(); it++)
        {
            auto key = it->first;
            auto value = it->second;
            //cout << key <<": " << value << "\n";
            if(key > h)
            {
                sum += (key - h) * value;
            }
        }
        //cout << "sum: " << sum << "\n";
        if(sum >= M)
        {
            break;
        }
    }
    cout << h << "\n";
    return 0;
}