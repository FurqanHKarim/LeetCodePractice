#include <../inc/libraries.hpp>
#include <../inc/dataStructures.hpp>
#include <../inc/classSolution.hpp>


TreeNode* constructTree(const std::vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[0]);
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    int i = 1;
    while (!nodeQueue.empty() && i < arr.size()) {
        TreeNode* currNode = nodeQueue.front();
        nodeQueue.pop();

        if (arr[i] != INT_MIN) {
            currNode->left = new TreeNode(arr[i]);
            nodeQueue.push(currNode->left);
        }
        i++;

        if (i < arr.size() && arr[i] != INT_MIN) {
            currNode->right = new TreeNode(arr[i]);
            nodeQueue.push(currNode->right);
        }
        i++;
    }

    return root;
}


ListNode* arrayToLinkedList(vector<int>arr) {
  // Create a dummy node to simplify head handling
  ListNode dummy(0);
  ListNode* curr = &dummy;

  // Iterate through the array and create nodes
  for (int i = 0; i < arr.size(); ++i) {
    curr->next = new ListNode(arr[i]);
    curr = curr->next;
  }

  // Return the actual list (skip the dummy node)
  return dummy.next;
}