#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int N , M;
    cin >> N >> M;
    int J;
    cin >> J;
    vector<int> pos_v(J, 0);
    for(int i = 0; i<J; i++)
    {  
        cin >> pos_v[i];
    }

    int answer = 0;
    int left_pos = 1;
    for(int i =0; i<J; i++)
    {
        //cout << "left_pos: " << left_pos << ", pos_v[i]: " << pos_v[i] << endl;
        if(left_pos <= pos_v[i] &&  pos_v[i] <= (left_pos + M - 1))
        {
            continue;
        }
        else if (pos_v[i] > (left_pos + M - 1))
        {
            int delta =pos_v[i] - (left_pos + M - 1); 
            answer += delta;
            left_pos += delta;
        }
        else if(left_pos > pos_v[i])
        {
            int delta = left_pos - pos_v[i];
            answer += delta;
            left_pos -= delta;
        }
    }
    cout << answer << endl;
    return 0;
}