#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> parent_v(N, 0);

    Node* root = new Node;
    for(int i =0; i<N; i++)
    {
        cin >> parent_v[i];
    }

    int added_nodes = 0;

    for(int i = 0; i<N; i++)
    {
        if(parent_v[i] == -1)
        {
            root->num = i;
            added_nodes++;
            break;
        }
    }

    for(int i = 0; i<N; i++)
    {
        int parent_num = parent_v[i];
        if(parent_num == root->num)
        {
            Node* child = new Node;
            child->num = i;
            root->children.push_back(child);
            added_nodes++;
        }
    }

    
    while(added_nodes < N)
    {
        for(int i = 0; i<N; i++)
        {
            int parent_num = parent_v[i];
            if(parent_num == -1 || parent_num == root->num) continue; 
            auto parent_node = find_node(root, parent_num);
            if(parent_node == nullptr)
            {
                continue;
            }
            Node* child = new Node;
            child->num = i;
            auto children = parent_node->children;
            if(find_child(children, child->num) == -1) 
            { 
                parent_node->children.push_back(child);
                added_nodes++;
            }
        }
    }

    int target;
    cin >> target;

    root = remove_node(root, parent_v,  target);

    cout << count_leaf(root) << '\n';
    
    delete_node(root);
    return 0;
}