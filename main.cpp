#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

 
class Solution {
public:
        
     bool isEvenOddTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            int mx = INT_MIN , mn = INT_MAX;
            while(size--)
            {
                TreeNode* front = q.front();  q.pop();
                if(front->left)  q.push(front->left);
                if(front->right)  q.push(front->right);
                if(level % 2 == 0)
                {
                    if(!(front->val % 2))  return false;
                    if(front->val > mx)  mx = front->val;
                    else return false;
                }
                else
                {
                    if(front->val % 2)  return false;
                    if(front->val < mn)  mn = front->val;
                    else return false;
                }
            }
            level++;
        }
        return true;
    }
    int fillQueue(queue<TreeNode*> &in,queue<TreeNode*> &out,bool odd)
    {
        while(out.empty() == 0)
        {
            if(out.front()->left != NULL)
                in.push(out.front()->left);
            if((in.front()!=nullptr)&&(!in.empty()))
                if(in.back()->val%2 != odd)
                    return false;

            if(out.front()->right != NULL)
                in.push(out.front()->right);
            if((in.front()!=nullptr)&&(!in.empty()))
                if(in.back()->val%2 != odd)
                    return false;
            out.pop();
            
        }
        return order(in,odd);
    }
    bool order(queue<TreeNode*> check,bool increasing)
    {
        int i = check.size()-1;
        int temp;
        if(check.empty())
            return true;
        while(i--)
        {
            temp = check.front()->val;
            check.pop();
            if((temp>check.front()->val) == increasing)
                    return false;
            if(temp == check.front()->val)
                    return false;

        }
        return true;
    }
};
TreeNode* constructTree(const std::vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (i < arr.size()) {
        TreeNode* currNode = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != INT_MIN) {
            currNode->left = new TreeNode(arr[i]);
            q.push(currNode->left);
        }

        i++;

        if (i < arr.size() && arr[i] != INT_MIN) {
            currNode->right = new TreeNode(arr[i]);
            q.push(currNode->right);
        }

        i++;
    }

    return root;
}
long long square(long long input)
{
    if(input == 0)
        return 0;

    if(input<0)
        input = -input;
    
    long long result = 0;
    long long n = input;
    while(n!=0)
    {
        if(n&1)
            result += input;
        input<<=1;
        n>>=1;
    }
    return result;
}
int main()
{
    vector<int> ohkay = {-4,-3,-2,5,6,7};

    for (size_t i = 0; i < ohkay.size(); i++)
        ohkay[i] = square(ohkay[i]);

    std::sort(ohkay.begin(),ohkay.end());
    
    return 90;
    
}