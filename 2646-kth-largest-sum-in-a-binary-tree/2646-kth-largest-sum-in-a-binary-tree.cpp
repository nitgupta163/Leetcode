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
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
        queue<TreeNode*> q;
        q.push(root);   
        while(!q.empty())
        {
            long long int sum = 0;
            int i, n = q.size();
            for(i=0; i<n; i++)
            {
                TreeNode *ptr = q.front();
                q.pop();
                sum += ptr->val;
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
            }
            pq.push(sum);
            if(pq.size()>k)
                pq.pop();
        }
        if(pq.size() < k)   return -1;
        return pq.top();
    }
};