#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<unordered_map>
#include <utility>
#include <functional>

using namespace std;
// Only for pairs of std::hash-able types for simplicity.
// You can of course template this struct to allow other hash functions
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};


int N, M;
int grid[51][51] ={0,};
int chicken_num = 0;
int to_remove;
int total_chicken_distance = 0;


void combi(int n, int k, int start, vector<int>&b, vector<vector<int>>& dst);


void combi(int n, int k, int start, vector<int>&b, vector<vector<int>>& dst)
{
    if(k == b.size())
    {
        dst.push_back(b);
        return;
    }

    for(int i = start+1; i<n; i++)
    {
        b.push_back(i);
        combi(n,k,start+1, b, dst);
        b.pop_back();
    }
    return;
}

void printV(vector<int>& v)
{
    for(int i = 0; i<v.size(); i++)
    {
        cout << v[i] <<" ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=N; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 2)
            {
                chicken_num++;
            }
        }
    }

    to_remove = chicken_num - M;


    cout << "chicken_num: " << chicken_num << "\n";
    cout << "to_remove: " << to_remove << "\n";

    vector<int> b;
    vector<vector<int>> dst;
    combi(chicken_num, to_remove, -1, b, dst);
    for(int i = 0; i<dst.size(); i++)
    {
        printV(dst[i]);
        //TODO: calculate sum of chicken distances.
        unordered_map<pair<int,int>, int, pair_hash> house_chicken_distance_table;


    }



    return 0;
}