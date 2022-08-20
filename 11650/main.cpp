#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Pos
{
    int x;
    int y;

} Pos;

bool cmp(Pos& a, Pos& b)
{
    if(a.x < b.x)
    {
        return true;
    }
    else if(a.x == b.x)
    {
        return a.y < b.y;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<Pos> pos_v;
    for(int i = 0; i<N; i++)
    {
        int x, y;
        cin >> x >> y;
        Pos pos;
        pos.x = x;
        pos.y = y;
        pos_v.push_back(pos);
    }

    sort(pos_v.begin(), pos_v.end(), cmp);

    for(int i=0; i<N; i++)
    {
        auto pos = pos_v[i];
        cout << pos.x << " " << pos.y << "\n";
    }
    return 0;
}