#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct Element
{
    int num;
    int cnt;
    int fisrt_pos;
} Element;

bool cmp_element(Element e1, Element e2)
{
    if (e1.cnt > e2.cnt)
    {
        return true;
    }
    else
    {
        if(e1.cnt == e2.cnt)
        {
            return e1.fisrt_pos < e2.fisrt_pos;
        }
        else
        {
            return false;
        }
        
    }
}

int find_first_pos(vector<int>& v, int target)
{
    if(v.size() == 0)
    {
        return -1;
    }

    for(int i =0; i<v.size(); i++)
    {
        if(v[i] == target)
        {
            return i;
        }
    }

}

int main()
{
    int N, C;
    cin >> N >> C;

    unordered_map<int, int> um;
    vector<int> seq(N, 0);
    for(int i=0; i<N; i++)
    {
        cin >> seq[i];
    }

    for(int i=0; i<N; i++)
    {
        auto it = um.find(seq[i]);
        if(it != um.end())
        {
            it->second++;
        }
        else
        {
            um.insert({seq[i], 1});
        }
    }

    vector<Element> ev;
    for(auto it = um.begin(); it != um.end(); it++)
    {
        Element e;
        e.num = it->first;
        e.cnt = it->second;
        e.fisrt_pos = find_first_pos(seq, e.num);
        ev.push_back(e);
    }
    
    sort(ev.begin(), ev.end(), cmp_element);
    
    for(auto it : ev)
    {
        for(int i = 0; i<it.cnt ; i++){
            cout << it.num << " ";
        }
    }
    cout << endl;


    return 0;
}