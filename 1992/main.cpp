#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print2DV(vector<vector<int>>& v, int N, int M)
{
    for(int i=0; i<N; i++)
    {
        for(int j= 0; j<M; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

string quad_tree(vector<vector<int>>& img, int N)
{
    string answer;
    if(N == 1)
    {
        if(img[0][0])
        {
            answer = "1";
        }
        else
        {
            answer = "0";
        }
        return  answer;
    }

    int n = N/2;
    vector<vector<int>> img1(n, vector<int>(n, 0));
    for(int i = 0; i<n;i++)
    {
        for(int j = 0; j<n; j++)
        {
            img1[i][j] = img[i][j];
        }
    }
    vector<vector<int>> img2(n, vector<int>(n, 0));
    for(int i = 0; i<n;i++)
    {
        for(int j = 0; j<n; j++)
        {
            img2[i][j] = img[i][j+n];
        }
    }

    vector<vector<int>> img3(n, vector<int>(n, 0));
    for(int i = 0; i<n;i++)
    {
        for(int j = 0; j<n; j++)
        {
            img3[i][j] = img[i+n][j];
        }
    }
    vector<vector<int>> img4(n, vector<int>(n, 0));
    for(int i = 0; i<n;i++)
    {
        for(int j = 0; j<n; j++)
        {
            img4[i][j] = img[i+n][j+n];
        }
    }
    string c1 = quad_tree(img1, n);
    string c2 = quad_tree(img2, n);
    string c3 = quad_tree(img3, n);
    string c4 = quad_tree(img4, n);

    if(c1 == "0" && c2 == "0" && c3 == "0" && c4=="0")
    {
        return "0";
    }
    if(c1 =="1" && c2 == "1" && c3 == "1" && c4 == "1")
    {
        return "1";
    }

    answer = "(" + c1 + c2 + c3 + c4 + ")";

    return answer;
    

    


}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> img(N, vector<int>(N, 0));

    for(int i=0; i<N; i++)
    {
        string s;
        cin >> s;
        for(int j=0;j<N; j++)
        {
            img[i][j] = s[j] - '0';
        }
    }
    //print2DV(img, N, N);
    cout << quad_tree(img, N) << endl;

    return 0;
}