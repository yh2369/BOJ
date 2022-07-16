#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string input, string delimiter);

int time2sec(string& time);

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos;
    string token = "";
    while( (pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, delimiter.length() + pos);
    }
    ret.push_back(input);
    return ret;
}

int time2sec(string& time)
{
    auto v = split(time, ":");
    int sec = 0;
    if(v[1].length() == 1)
    {
        sec = v[1][0] - '0';
    }
    else
    {
        sec = (v[1][0]-'0')* 10 + (v[1][1] - '0');
    }
    return (10*(v[0][0] - '0') + v[0][1] - '0')*60 + sec;
}

string sec2time(int sec)
{
    int q = sec / 60;
    int r = sec % 60;
    string minute_s ="";
    string sec_s = "";
    if(r /10 == 0)
    {
        sec_s = "0" + to_string(r);
    }
    else
    {
        sec_s = to_string(r);
    }
    if(q / 10 == 0)
    {
        minute_s = "0" + to_string(q);
    }
    else
    {
        minute_s = to_string(q);
    }

    return minute_s + ":" + sec_s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string winning_time1;
    string winning_time2;
    int winning_sec1 = 0;
    int winning_sec2 =0;

    int N;
    cin >> N;
    string time = "";
    int team_num;

    int status = 0;
    int prev_status = 0;
    int start_sec = 0;

    
    pair<int, int> score = {0,0};

    while(N--)
    {
        cin >> team_num >> time;
        int sec = time2sec(time);
        //cout  << "sec: " << sec << endl;
        if(team_num == 1)
        {
            score.first++;
        }
        else
        {
            score.second++;
        }

        prev_status = status;
        if(score.first == score.second)
        {
            status = 0;
        }
        else if(score.first > score.second)
        {
            status = 1;
        }
        else if(score.first < score.second)
        {
            status = 2;
        }   

        switch (prev_status)
        {
            case 0:
                break;
            case 1:
                winning_sec1 += sec - start_sec;
                break;
            case 2:
                winning_sec2 += sec - start_sec;
                break;
        }
        start_sec = sec;
    }

    switch (status)
    {
        case 0:
            break;
        case 1:
            winning_sec1 += 2880 - start_sec;
            break;
        case 2:
            winning_sec2 += 2880 - start_sec;
            break;
    }

    //cout << "winning_sec1: " << winning_sec1 << '\n';
    //cout << "winning_sec2: " << winning_sec2 << '\n';

    cout << sec2time(winning_sec1) << '\n';
    cout << sec2time(winning_sec2) << '\n';

    return 0;
}