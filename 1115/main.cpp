#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int N;
void printV(vector<int>& v);
void perm(int n ,int r, int depth, vector<int>& v, vector<vector<int>>& dst);
vector<int> get_child_vector(vector<int>& A);
bool is_permutation(vector<int>& v);
int get_diff(vector<int>& P, vector<int>& Q);
void print_adj_list(vector<vector<int>>& adj_list);


void printV(vector<int>& v)
{
    int n = v.size();
    for(int i =0;i<n; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void perm(int n ,int r, int depth, vector<int>& v, vector<vector<int>>& dst)
{
    if(depth == r)
    {
        dst.push_back(v);
        return;
    }

    for(int i = depth; i<n; i++)
    {
        swap(v[depth], v[i]);
        perm(n, r, depth+1, v, dst);
        swap(v[depth], v[i]);        
    }
}

vector<int> get_child_vector(vector<int>& A)
{
    int n = A.size();
    vector<int> B(n, 0);
    for(int i = 1; i<n; i++)
    {
        B[i] = A[B[i-1]];
    }
    return B;
}

bool is_permutation(vector<int>& v)
{
    int n = v.size();
    set<int> s;
    for(int i = 0; i< n; i++)
    {
        int e = v[i];
        if(e < 0 || e >= n)
        {
            return false;
        }

        s.insert(e);
    }
    return s.size() == n;
}

int get_diff(vector<int>& P, vector<int>& Q)
{
    int p_size =P.size();
    int q_size = Q.size();
    if(p_size != q_size)
    {
        return -1;
    }
    int cnt = 0;
    for(int i = 0; i<p_size; i++)
    {
        if(P[i] != Q[i])
        {
            cnt++;
        }
    }
    return cnt;
}

void print_adj_list(vector<vector<int>>& adj_list)
{
    int n = adj_list.size();
    for(int i = 0; i< n; i++)
    {
        cout << "[" << i << "]: ";
        for(int j = 0; j< adj_list[i].size(); j++)
        {
            cout << adj_list[i][j] <<" ";
        }
        cout << "\n";
    }

}

void dfs(vector<vector<int>>& adj_list, vector<bool>& visited, int start)
{
    visited[start] = true;

    for(int i = 0; i<adj_list[start].size(); i++)
    {
        int next = adj_list[start][i];
        if(!visited[next])
        {
            dfs(adj_list, visited, next);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> P(N, 0);
    for(int i = 0; i<N; i++)
    {
        cin >> P[i];
    }

    vector<vector<int>> adj_list(N, vector<int>());
    for(int i = 0; i<N; i++)
    {
        adj_list[i].push_back(P[i]);
    }

    //print_adj_list(adj_list);

    int cnt = 0;
    vector<bool> visited(N, false);
    for(int i =0; i<N; i++)
    {
        if(!visited[i])
        {
            dfs(adj_list, visited, i);
            cnt++;
        }
    }

    if(cnt == 1)
    {
        cnt = 0;
    }
    cout << cnt << "\n";


    //printV(P);
    /*
    vector<int> v(N, 0);
    for(int i = 0; i<N; i++)
    {
        v[i] = i;
    }
    vector<vector<int>> dst;
    vector<vector<int>> perfect_perm_list;

    perm(N, N, 0, v, dst);
    int min_diff = N+1;
    int dst_size = dst.size();
    for(int i = 0 ; i< dst_size; i++)
    {
        //cout << "original: ";
        //printV(dst[i]);
        // get child vector of dst[i];
        auto child_vector = get_child_vector(dst[i]);
        //cout << "child: ";
        //printV(child_vector);
        // if child vector is permutation, then add dst[i] to perfect_perm_list
        if(is_permutation(child_vector))
        {
            //cout << "child vector is permutation\n\n";
            perfect_perm_list.push_back(dst[i]);
        }
        else
        {
            //cout << "NOT PERMUTATION\n\n";
        }
    }


    int perfect_perm_list_size = perfect_perm_list.size();
    for(int i =0; i<perfect_perm_list_size; i++)
    {
        auto perfect_perm = perfect_perm_list[i];
        int diff = get_diff(perfect_perm, P);
        min_diff = min(diff, min_diff);
    }

    cout << min_diff << "\n";
    */
    
    return 0;
}