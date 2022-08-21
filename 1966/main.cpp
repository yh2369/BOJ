#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int T;
int N, M;

struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if(a.second < b.second)
        {
            return true;
        }
        else if(a.second == b.second)
        {
            return a.first < b.first;
        }
        else
        {
            return false;
        }
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i = 0; i<T; i++)
    {
        cin >> N >> M;
        vector<int> priority_v(N, 0);
        list<pair<int,int>> printer_queue;
        for(int j = 0; j < N; j++)
        {
            cin >> priority_v[j];
            printer_queue.push_back(make_pair(j, priority_v[j]));
        }
        int has_printed = 0;
        while(true)
        {
            auto front_it = printer_queue.begin();
            auto front_priority = front_it->second;

            //cout << "front_doc_num: " << front_it->first << " front_doc_priority: " << front_priority << "\n";
            bool defer = false;
            for(auto it = printer_queue.begin(); it != printer_queue.end(); it++)
            {
                if(it->second > front_priority)
                {
                    defer = true;
                    break;
                }
            }
            if(defer)
            {
                printer_queue.push_back(make_pair(front_it->first, front_it->second));
                printer_queue.pop_front();
            }
            else
            {
                has_printed++;
                printer_queue.pop_front();
                if(front_it->first == M)
                {
                    cout << has_printed << "\n";
                    break;
                }
            }
        }


    }
    return 0;
}