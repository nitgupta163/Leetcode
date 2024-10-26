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
    int height(TreeNode* root, unordered_map<int,int> &hDiff)
    {
        if(!root)
            return -1;
        int lh = height(root->left,hDiff);
        int rh = height(root->right,hDiff);
        if(lh==rh && lh==-1) // leaf
            return 0;
        if(lh==-1)        
            hDiff.insert({root->right->val,rh+1});        
        else if(rh==-1)
            hDiff.insert({root->left->val,lh+1});
        else if(lh==rh)
        {
            hDiff.insert({root->left->val,0});
            hDiff.insert({root->right->val,0});
        }
        else if(lh>rh)
        {
            hDiff.insert({root->left->val,lh-rh});
            hDiff.insert({root->right->val,0});            
        }
        else // if(rh>lh)
        {
            hDiff.insert({root->left->val,0});
            hDiff.insert({root->right->val,rh-lh}); 
        }
        return max(lh,rh)+1;
    }
    void preProcess(TreeNode* root, unordered_map<int,int> &hDiff)
    {
        if(!root)
            return;
        if(root->left)
            hDiff[root->left->val] = min(hDiff[root->val],hDiff[root->left->val]); //todo min(root,left)
        if(root->right)
            hDiff[root->right->val] = min(hDiff[root->val],hDiff[root->right->val]); //todo min(root,left)
        preProcess(root->left,hDiff);
        preProcess(root->right,hDiff);
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries)
    {
        unordered_map<int,int> hDiff;
        int orgH = height(root,hDiff);
        preProcess(root->left,hDiff);
        preProcess(root->right,hDiff);
        vector<int> ans;
        for(int q : queries)
            ans.push_back(orgH-hDiff[q]);
        // for(auto p : hDiff)
        //     cout << p.first << " " << p.second << "\n";
        return ans;    
    }
};