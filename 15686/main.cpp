#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<unordered_map>
#include <utility>
#include <functional>

using namespace std;

#define INF 987654321

// Only for pairs of std::hash-able types for simplicity.
// You can of course template this struct to allow other hash functions
struct pair_hash
{
    std::size_t operator () (const pair<int,int>& p) const {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

struct pair_equal
{
    bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs) const
    {
        return (std::get<0>(lhs) == std::get<0>(rhs) && std::get<1>(lhs) == std::get<1>(rhs));
    }
};


int N, M;
int grid[51][51] ={0,};
int chicken_house_num = 0;
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

    // vector of (x,y) position of chicken house
    vector<pair<int,int>> chicken_house_v;

    // key: (x,y) position of house, value: chicken distance.
    unordered_map<pair<int,int>, int, pair_hash, pair_equal> chicken_distance_table;
    
    cin >> N >> M;
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=N; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 2)
            {
                chicken_house_num++;
                chicken_house_v.push_back({i,j});
            }
            else if(grid[i][j] ==1)
            {
                auto key = make_pair(i,j);
                chicken_distance_table.insert(make_pair(key, INF));
            }
        }
    }

    to_remove = chicken_house_num - M;


    cout << "chicken_house_num: " << chicken_house_num << "\n";
    cout << "to_remove: " << to_remove << "\n";



    vector<int> b;
    vector<vector<int>> dst;
    combi(chicken_house_num, to_remove, -1, b, dst);
    for(int i = 0; i<dst.size(); i++)
    {
        //printV(dst[i]);
        //TODO: calculate sum of chicken distances
        
        // select #to_remove chicken houses
        // remove chicken houses
        
        for(int j = 0; j<to_remove; j++)
        {
            auto index = dst[i][j];
            auto chicken_house_pos = chicken_house_v[index];
            int x=chicken_house_pos.first;
            int y = chicken_house_pos.second;
            //cout << "(" << x <<"," << y << ")\n";
            
            grid[x][y] = 0;
        }

        // calculate sum of chicken distances.
        for(auto it = chicken_distance_table.begin(); it != chicken_distance_table.end(); it++)
        {
            auto key = it->first;
            auto value = it->second;
            cout << "[@@@ house position: (" << key.first << "," << key.second << ") @@@]\n";
        }
        cout << "===========================================================================\n";


        // rebuild chicken houses
        for(int j = 0; j<to_remove; j++)
        {
            auto index = dst[i][j];
            auto chicken_house_pos = chicken_house_v[index];
            int x=chicken_house_pos.first;
            int y = chicken_house_pos.second;
            //cout << "(" << x <<"," << y << ")\n";
            
            grid[x][y] = 1;
        }



    }



    return 0;
}