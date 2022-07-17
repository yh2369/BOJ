#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[54];
typedef struct Node
{
    int num;
    vector<Node*> children;
} Node;

Node* find_node(Node* root, int num)
{
    if(num == root->num)
    {
        return root;
    }

    Node* current = root;
    for(int i =0; i<current->children.size(); i++)
    {
        auto child = current->children[i];
        auto node = find_node(child, num);
        if(node != nullptr)
        {
            return node;
        }
    }
    return nullptr;
}

void print_node(Node* root, int depth)
{
    for(int i =0; i<depth; i++)
    {
        cout << "    ";
    }
    cout << root->num << '\n';
    for(int i =0; i<root->children.size(); i++)
    {
        auto child = root->children[i];
        print_node(child, depth+1);
    }
}

void delete_node(Node* root)
{
    if(root != nullptr)
    {
        for(int i =0; i<root->children.size(); i++)
        {
            delete_node(root->children[i]);
        }
    }
}

int find_child(vector<Node*> children, int num)
{
    for(int i =0; i<children.size(); i++)
    {
        if(children[i]->num == num)
        {
            return i;
        }
    }
    return -1;
}

Node* remove_node(Node* root, vector<int>& parent_v, int target)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    if(root->num == target)
    {
        return nullptr;
    }

    auto target_node = find_node(root, target);
    if(target_node == nullptr)
    {
        // tree does not contain target
        return root;
    }
    int parent_num = parent_v[target];
    auto parent_node = find_node(root, parent_num);
    for(auto it = parent_node->children.begin(); it != parent_node->children.end(); it++)
    {
        auto child = *it;
        if(child->num == target)
        {
            parent_node->children.erase(it);
            break;
        }
    }

    delete_node(target_node);
    return root;
}

int count_leaf(Node* root)
{
    int cnt = 0;
    if(root == nullptr)
    {
        return cnt;
    }

    if(root->children.size() == 0)
    {
        cnt++;
        return cnt;
    }

    for(int i =0; i<root->children.size(); i++)
    {
        auto child = root->children[i];
        cnt += count_leaf(child);
    }
    return cnt;
}

int dfs(int here)
{
    if(adj[here].empty())
    {
        return 1;
    }

    int ret = 0;

    for(int there : adj[here])
    {
        ret += dfs(there);
    }
    return ret;

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> parent_v(N, 0);

    int root;
    for(int i =0; i<54; i++)
    {
        adj[i] = vector<int>();
    }


    for(int i =0; i<N; i++)
    {
        cin >> parent_v[i];
        if(parent_v[i] == -1)
        {
            root = i;
        }        
        else
        {
            adj[parent_v[i]].push_back(i);
        }
    }

    /* print adj list
    for(int i =0; i<N; i++)
    {
        cout << "[" << i <<"]: ";
        for(int j =0; j<adj[i].size(); j++)
        {
            cout << adj[i][j] <<" ";
        }
        cout << endl;
    }
    */

    int target;
    cin >> target;

    if(target == root)
    {
        cout << 0 <<'\n';
    }
    else
    {
        for(int i = 0; i<N; i++)
        {
            if(i == target)
            {
                adj[i].clear();
                continue;
            }

            for(auto it = adj[i].begin(); it != adj[i].end(); it++)
            {
                if(*it == target)
                {
                    adj[i].erase(it);
                    break;
                }
            }
        }

        cout << dfs(root) << '\n';
    }

    return 0;
}