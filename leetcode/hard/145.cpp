#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> st_node;
        stack<int> st_state;
        st_node.push(root);
        st_state.push(0);
        while (!st_node.empty()) {
            if (st_node.top() == NULL) {
                st_node.pop();
                st_state.pop();
                continue;
            }
            if (st_state.top() == 2) {
                vec.push_back(st_node.top() -> val);
                st_node.pop();
                st_state.pop();
                continue;
            }
            if (st_state.top() == 0)
                st_node.push(st_node.top() -> left);
            else if (st_state.top() == 1)
                st_node.push(st_node.top() -> right);
            st_state.top()++;
            st_state.push(0);
        }
        return vec;
    }
};
