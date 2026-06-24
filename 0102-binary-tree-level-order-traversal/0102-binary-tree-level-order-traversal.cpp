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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<vector<TreeNode*> > nodesq;
        TreeNode *curr = root;
        if ( curr ){
            vector<TreeNode*> temp;
            temp.push_back(curr);
            nodesq.push(temp);
        }
        vector<vector<int> > res;
        while ( nodesq.size() > 0 ){
            vector<TreeNode*> temp = nodesq.front();
            nodesq.pop();
            vector<TreeNode*> test ;
            for ( int i = 0; i < temp.size(); i++ ){
                if ( temp[i]->left != NULL ) test.push_back(temp[i]->left);
                if ( temp[i]->right != NULL ) test.push_back(temp[i]->right);
            }
            if ( test.size() > 0) nodesq.push(test);
            vector<int> val ;
            for ( int j = 0; j < temp.size(); j++ ){
                val.push_back(temp[j]->val);
                
            }
            res.push_back(val);
        }
        return res;
    }
};