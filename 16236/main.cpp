#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int N;
int M;

int space[20][20];
int fish_counter[7] = {0,0,0,0,0,0,0};
int current_shark_size = 2;
int exp = 0;
int total_time = 0;
pair<int,int> current_shark_position;
void print_fish_counter();
void print_visited(vector<vector<int>>& visited);


void print_fish_counter()
{
    for(int i = 0; i<7;i++)
    {
        cout << "[" << i <<"]: " << fish_counter[i] << "\n"; 
    }
}
void print_visited(vector<vector<int>>& visited)
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    
    
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cin >> space[i][j];
            if(space[i][j] == 9)
            {
                current_shark_position = make_pair(i,j);
                space[i][j] = 0;
            }
            else if(space[i][j] == 0)
            {
                
            }
            else
            {
                fish_counter[space[i][j]]++;
            }
        }
    }

    //print_fish_counter();

    
    while(true)
    {
        set<tuple<int,int,int>> eatable_fish_info_set; // (distance, x, y)
        int x = current_shark_position.first;
        int y = current_shark_position.second;
        int shark_x = current_shark_position.first;
        int shark_y = current_shark_position.second;
        vector<vector<int>> visited(N, vector<int>(N,0));
        queue<pair<int,int>> q;
        visited[shark_x][shark_y] = 1;
        q.push(make_pair(shark_x,shark_y));
        while(q.size())
        {
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;

            for(int i = 0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= N || ny < 0 || ny >=N) continue;
                
                if(space[nx][ny] > current_shark_size) continue;

                if(visited[nx][ny] > 0) continue;

                visited[nx][ny] = visited[x][y] + 1; 
                q.push(make_pair(nx, ny));

            }
        }

        //print_visited(visited);

        
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if((space[i][j] > 0) && (space[i][j] < current_shark_size) && (visited[i][j] > 0))
                {
                    int distance = visited[i][j] - 1;
                    tuple<int,int,int> info = make_tuple(distance, i, j);
                    eatable_fish_info_set.insert(info);
                }
            }
        }
        if(!eatable_fish_info_set.empty())
        {
            auto it = eatable_fish_info_set.begin();
            auto distance = get<0>(*it);
            auto nx = get<1>(*it);
            auto ny = get<2>(*it);
            //cout << "(distance: " << distance << ", nx: "<< nx << ", ny: "<<ny << ")\n";
            exp++;
            fish_counter[space[nx][ny]]--;
            space[nx][ny] = 0;
            total_time += distance;
            current_shark_position = make_pair(nx, ny);
            if(exp == current_shark_size)
            {
                // size up
                current_shark_size++;
                exp = 0;
            }
        }
        else
        {
            break;
        }

    }
        


    cout << total_time << "\n";

    return 0;
}