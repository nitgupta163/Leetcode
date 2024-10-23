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
    void UpdateValue(vector<pair<TreeNode*,TreeNode*>> &level)
    {
        int i, n = level.size();
        if(n==0)
            return;
        long long int sum = 0;
        for(auto p : level)
        {
            sum += p.first->val; 
            // cout << p.first->val << " ";
        } 
        // cout << "\n";      
        for(i=0; i<n; i++)
        {
            pair<TreeNode*,TreeNode*> p1 = level[i];
            pair<TreeNode*,TreeNode*> *p2 = nullptr;
            if((i+1<n) && p1.second==level[i+1].second)
                p2 = &level[++i];
            int siblingSum = p1.first->val;            
            if(p2)
                siblingSum += p2->first->val;
            // cout << sum << " " << siblingSum << "\n";
            p1.first->val = sum-siblingSum;
            if(p2)
                p2->first->val = sum-siblingSum;
        }
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        while(!q.empty())
        {
            int n = q.size();
            vector<pair<TreeNode*,TreeNode*>> level;
            for(int i=0; i<n; i++)
            {
                TreeNode *ptr = q.front();
                q.pop();
                if(ptr->left)
                {
                    q.push(ptr->left);
                    level.push_back({ptr->left,ptr});
                }
                if(ptr->right)
                {
                    q.push(ptr->right);
                    level.push_back({ptr->right,ptr});
                }                
            }
            UpdateValue(level);
        }    
        return root;
    }
};