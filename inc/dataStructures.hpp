
#ifndef STRUCTURES
#define STRUCTURES


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MinStack {
    private:
    stack<pair<int,int>> node;

    
public:
    MinStack() { 

    }
    
    void push(int val) {
        if(node.empty()){
            node.push({val,val});
        }
        else
            node.push({val,min(val,node.top().second)});
        
    }
    
    void pop() {
        node.pop();
    }
    
    int top() {
        return node.top().first;
    }
    
    int getMin() {
       return node.top().second;
    }
};

#endif // !STRUCTURES