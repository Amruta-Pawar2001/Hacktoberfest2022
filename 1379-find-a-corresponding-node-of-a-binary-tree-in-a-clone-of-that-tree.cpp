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
    TreeNode *findtargetval(TreeNode* cloned, int targetval)
    {
        if(cloned==NULL)
           return NULL;
        if(cloned->val==targetval)
        {
            return cloned;
        }
        TreeNode *left = findtargetval(cloned->left,targetval);
        if(left)
            return left;
        else
            return findtargetval(cloned->right,targetval);
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int targetval = target->val;
        return findtargetval(cloned,targetval);
    }
};
