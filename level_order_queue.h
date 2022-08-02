/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
problem: determine if two nodes in a tree are cousin.
axiom cousin definition: two nodes are cousin if they have same depth with differant parents.
root depth=0;

solution:
do a traversal of the tree and save depths of both nodes.
compare and return true if they are equal else return false.

SC: O(n). // if we use recursive traversal algorithms.
TC: O(n)

q:  can we use iterative traversal to find depths of the node.
a:

solution: 
Since this problem is about finding  a cousin, and cousins are at same level in a tree. 
We need to check if two gives nodes are in same level, hence we should do a level order
traversal. We do LOT using BFS in a tree.  
LOT: can be done using 2 queue or 1 queue.

. we will push nodes on the q with a saparator nullptr. nullptr saparates cousins from siblings.
.maintain two flags, siblings, and cousins.
.if we pop nullptr from q, siblings is set to  true.
. if we pop any potentials cousins, if it is the first time we encounter  a PC, cousin=sibling=true.
. if we pop second PC, and they are not siblings, then they are cousins.
. if they are siblings,they are not cousins.


*/

#include<iostream>
#include <queue>
#include <vector>
#include "Tree.h"  


class Solution {
public:
    
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q,q1;
        q.push(root);
        bool siblings = false, singleCousinFound=false;
        
        while(q.size() && !singleCousinFound){
                int m = q.size();
                for (int i=0;i<m;i++){
                    auto n = q.front();
                    q.pop();
                    if (!n) siblings = false;
                    else {  
                        if (n->val == x || n->val == y){
                            if (!singleCousinFound) singleCousinFound = siblings = true;
                            else  return !siblings;
                        }
                        q.push(n->left); q.push(n->right); q.push(nullptr);
                    }
                }
        }
       return false;
    }
};























