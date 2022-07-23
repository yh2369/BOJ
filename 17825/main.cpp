#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
#include <unordered_map>

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
    set<int> pieces;

}Node;

Node* create_node(Status status, int value, bool visited, Node* red_next, Node* blue_next);
void delete_node(Node* node);
void dfs(Node* node, stack<Node*> stk);
void init_visited(Node* node);
int calc_score(vector<int>& arr, vector<int>& dice_v, Node* start);
Node* find_next_node(Node* current, int dice_num);
Node* successor_node(Node* current);


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
    if(node == nullptr)
    {
        assert(false);
    }
    /*
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
    */
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
    if(node == nullptr)
    {
        assert(false);
    }
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

void print_node(Node* node)
{
    if(node == nullptr)
    {
        assert(false);
    }
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
    cout << "value: " << node->value << '\n';

}
int calc_score(vector<int>& arr, vector<int>& dice_v, Node* start)
{
    int score = 0;
    cout << "[@@@@ calc_score() @@@@]\n";

    unordered_map<int, Node*> piece_map;
    piece_map.insert({0, start});
    piece_map.insert({1, start});
    piece_map.insert({2, start});
    piece_map.insert({3, start});
    start->pieces.insert(0);
    start->pieces.insert(1);
    start->pieces.insert(2);
    start->pieces.insert(3);

    Node* current = start;
    for(int i =0; i<10; i++)
    {
        cout << "[" << i << "]\n";
        int dice_num = dice_v[i];
        int piece = arr[i];
        auto it = piece_map.find(piece);
        if(it != piece_map.end())
        {
            current = it->second;
            switch (current->status)
            {
                case Status::START:
                    break;
                case Status::END:
                    continue;
                    break;
                case Status::RED:
                    break;
                case Status::BLUE:
                    break;
                case Status::NOEDGE:
                    continue;
                    break;
            }
            auto next_node = find_next_node(current, dice_num);
            cout << "[@@@ current @@@]"; print_node(current);
            cout << "[@@@ next_node @@@]"; print_node(next_node);
            current->pieces.erase(piece);
            current = next_node;
            piece_map[piece] = next_node;

            switch (current->status)
            {
                case Status::START:
                    break;
                case Status::END:                     
                    break;
                case Status::RED:
                    score += current->value;
                    break;
                case Status::BLUE:
                    score += current->value;
                    break;
                case Status::NOEDGE:
                    score += current->value;
                    break;
            }
            current->pieces.insert(piece);
            cout << "======================================================\n";


        }
        else
        {
            //assert(false);
        }
        
    }
    return score;
}

Node* find_next_node(Node* current, int dice_num)
{
    if(current == nullptr)
    {
        assert(false);
    }

    /*
    switch (current->status)
    {
        case Status::START:
            break;
        case Status::END:
            break;
        case Status::RED:
            break;
        case Status::BLUE:
            break;
        case Status::NOEDGE:
            break;
    } 
    */
    Node* ret = current;
    for(int i = 0; i< dice_num; i++)
    {
        ret = successor_node(ret);
    }
    return ret;
}

Node* successor_node(Node* current)
{
    if(current == nullptr)
    {
        assert(false);
    }

    Node* ret = current;
    switch (ret->status)
    {
        case Status::START:
            ret = current->red_next;
            break;
        case Status::END:
            assert(false);
            break;
        case Status::RED:
            ret = current->red_next;
            break;
        case Status::BLUE:
            ret = current->blue_next;
            break;
        case Status::NOEDGE:
            assert(false);
            break;
    }  
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int max_score = 0;
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


    vector<int> dice_v(10, 0);
    for(int i = 0; i<10; i++)
    {
        cin >> dice_v[i];
    }

    for(int i0 = 0; i0< 4; i0++)
    {
        for(int i1 = 0; i1<4; i1++)
        {
            for(int i2 = 0; i2<4; i2++)
            {
                for(int i3 = 0; i3<4; i3++)
                {
                    for(int i4 = 0; i4<4; i4++)
                    {
                        for(int i5 = 0; i5<4; i5++)
                        {
                            for(int i6 = 0; i6<4; i6++)
                            {
                                for(int i7 = 0; i7<4; i7++)
                                {
                                    for(int i8 = 0; i8<4; i8++)
                                    {
                                        for(int i9 = 0; i9<4; i9++)
                                        {
                                            vector<int> arr(10,0);
                                            arr[0] = i0;
                                            arr[1] = i1;
                                            arr[2] = i2;
                                            arr[3] = i3;
                                            arr[4] = i4;
                                            arr[5] = i5;
                                            arr[6] = i6;
                                            arr[7] = i7;
                                            arr[8] = i8;
                                            arr[9] = i9;

                                            /*
                                            for(int i = 0; i< 10; i++)
                                            {
                                                cout << arr[i] << ' ';
                                            }
                                            cout << "\n";
                                            */

                                            int score = calc_score(arr, dice_v, start);
                                            init_visited(start);
                                            max_score = max(score, max_score);
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }    
        }
    }



    
    delete_node(start);


    

    return 0;
}