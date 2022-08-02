#ifndef TREE_H
#define TREE_H

#include <iostream>
using   namespace std;


struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x),  left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x),  left(l), right(r){}
};

// 1 2 3 4 
// 0 1 2 3 4 

namespace tree {
class Solution {
public:
    using iter = vector<int>::const_iterator;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        
        return buildBST(nums.begin(), nums.end());
    }
    
    TreeNode* buildBST(iter b, iter e) {
        if (b >= e) return nullptr;
        
        iter m = b + (e - b) / 2;
        
        TreeNode* node = new TreeNode(*m);
        node->left = buildBST(b, m);
        node->right = buildBST(m + 1, e);
        
        return node;
    }
};

}

#endif