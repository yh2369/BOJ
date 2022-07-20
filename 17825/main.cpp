#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

enum Status
{
    START,
    END,
    RED,
    BLUE,
    NOEDGE,
};

typedef struct Node
{
    Status status;
    int value;
    bool visited;
    Node* red_next;
    Node* blue_next;
}Node;

Node* create_node(Status status, int value, bool visited, Node* red_next, Node* blue_next);
void delete_node(Node* node);
void dfs(Node* node, stack<Node*> stk);
void init_visited(Node* node);


Node* create_node(Status status, int value, bool visited, Node* red_next, Node* blue_next)
{
    Node* n = new Node;
    n->status = status;
    n->value=value;
    n->visited = visited;
    n->red_next = red_next;
    n->blue_next = blue_next;
    return n;
}

void dfs(Node* node, stack<Node*> stk)
{
    switch (node->status)
    {
        case Status::START:
            cout << "[START]  ";
            break;
        case Status::END:
            cout << "[END]   ";
            break;
        case Status::RED:
            cout << "[RED]   ";
            break;
        case Status::BLUE:
            cout << "[BLUE]  ";
            break;
        case Status::NOEDGE:
            cout << "[NOEDGE]  ";
            break;
    }
    cout << " value: " << node->value << '\n';
    node->visited = true;
    switch (node->status)
    {
        case Status::START:
           
            if(!node->red_next->visited)
                dfs(node->red_next, stk);
            break;
        case Status::END:
           
            break;
        case Status::RED:
            
            if(!node->red_next->visited)
                dfs(node->red_next, stk);
            break;
        case Status::BLUE:
            
            if(!node->blue_next->visited)
                dfs(node->blue_next, stk);
            if(!node->red_next->visited)
                dfs(node->red_next, stk);
            break;
        case Status::NOEDGE:
           
            break;
    }
    
    stk.push(node);

}

void init_visited(Node* node)
{
    node->visited = false;
    switch (node->status)
    {
        case Status::START:
            init_visited(node->red_next);
            break;
        case Status::END:
            break;
        case Status::RED:
            init_visited(node->red_next);
            break;
        case Status::BLUE:
            init_visited(node->blue_next);
            init_visited(node->red_next);
            break;
        case Status::NOEDGE:
            break;
    }   
}


void delete_node(Node* node)
{
    if(node==nullptr)
    {
        return;
    }

    stack<Node*> stk;

    dfs(node, stk);

    while(!stk.empty())
    {
        auto node = stk.top();
        stk.pop();
        delete node;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Node* start = create_node(Status::START, 0, false, nullptr, nullptr);
    Node* n1 = create_node(Status::RED, 2, false, nullptr, nullptr);
    Node* n2 = create_node(Status::RED, 4, false, nullptr, nullptr);
    Node* n3 = create_node(Status::RED, 6, false, nullptr, nullptr);
    Node* n4 = create_node(Status::RED, 8, false, nullptr, nullptr);
    Node* n5 = create_node(Status::BLUE, 10, false, nullptr, nullptr);
    Node* n6 = create_node(Status::RED, 13, false, nullptr, nullptr);
    Node* n7 = create_node(Status::RED, 16, false, nullptr, nullptr);
    Node* n8 = create_node(Status::RED, 19, false, nullptr, nullptr);
    Node* n9 = create_node(Status::RED, 25, false, nullptr, nullptr);
    Node* n10 = create_node(Status::RED, 30, false, nullptr, nullptr);
    Node* n11 = create_node(Status::RED, 35, false, nullptr, nullptr);
    Node* n12 = create_node(Status::RED, 40, false, nullptr, nullptr);
    Node* end = create_node(Status::END, 40, false, nullptr, nullptr);
    Node* n13 = create_node(Status::RED, 12, false, nullptr, nullptr);
    Node* n14 = create_node(Status::RED, 14, false, nullptr, nullptr);
    Node* n15 = create_node(Status::RED, 16, false, nullptr, nullptr);
    Node* n16 = create_node(Status::RED, 18, false, nullptr, nullptr);
    Node* n17 = create_node(Status::BLUE, 20, false, nullptr, nullptr);
    Node* n18 = create_node(Status::RED, 22, false, nullptr, nullptr);
    Node* n19 = create_node(Status::RED, 24, false, nullptr, nullptr);
    Node* n20 = create_node(Status::RED, 22, false, nullptr, nullptr);
    Node* n21 = create_node(Status::RED, 24, false, nullptr, nullptr);
    Node* n22 = create_node(Status::RED, 26, false, nullptr, nullptr);
    Node* n23 = create_node(Status::RED, 28, false, nullptr, nullptr);
    Node* n24 = create_node(Status::BLUE, 30, false, nullptr, nullptr);
    Node* n25 = create_node(Status::RED, 28, false, nullptr, nullptr);
    Node* n26 = create_node(Status::RED, 27, false, nullptr, nullptr);
    Node* n27 = create_node(Status::RED, 26, false, nullptr, nullptr);
    Node* n28 = create_node(Status::RED, 32, false, nullptr, nullptr);
    Node* n29 = create_node(Status::RED, 34, false, nullptr, nullptr);
    Node* n30 = create_node(Status::RED, 36, false, nullptr, nullptr);
    Node* n31 = create_node(Status::RED, 38, false, nullptr, nullptr);
    start->red_next = n1;
    n1->red_next=n2;
    n2->red_next=n3;
    n3->red_next=n4;
    n4->red_next=n5;
    n5->blue_next = n6;
    n5->red_next = n13;
    n6->red_next = n7;
    n7->red_next = n8;
    n8->red_next = n9;
    n9->red_next = n10;
    n10->red_next = n11;
    n11->red_next = n12;
    n12->red_next = end;
    n13->red_next = n14;
    n14->red_next = n15;
    n15->red_next = n16;
    n16->red_next = n17;
    n17->blue_next = n18;
    n18->red_next = n19;
    n19->red_next = n9;
    n17->red_next = n20;
    n20->red_next = n21;
    n21->red_next = n22;
    n22->red_next = n23;
    n23->red_next = n24;
    n24->blue_next = n25;
    n25->red_next = n26;
    n26->red_next = n27;
    n27->red_next = n9;
    n24->red_next = n28;
    n28->red_next = n29;
    n29->red_next = n30;
    n30->red_next = n31;
    n31->red_next = n12;

    n25->visited = true;
    init_visited(start);
    cout << n25->visited << '\n';


    delete_node(start);


    

    return 0;
}