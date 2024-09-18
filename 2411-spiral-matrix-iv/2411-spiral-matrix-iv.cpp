/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
    {
        int left = 0, right = n-1;
        int top = 0, bottom = m-1;
        int i, j;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        ListNode *ptr = head;
        while(ptr && (left<=right || top<= bottom))
        {
            // left to right
            i = top;
            j = left;
            while(ptr && (j <= right))
            {
                ans[i][j] = ptr->val;
                j++;
                ptr = ptr->next;
            }
            top++;

            // top to bottom
            i = top;
            j = right;
            while(ptr && (i <= bottom))
            {
                ans[i][j] = ptr->val;
                i++;
                ptr = ptr->next;
            }
            right--;

            // right to left
            i = bottom;
            j = right;
            while(ptr && (j >= left))
            {
                ans[i][j] = ptr->val;
                j--;
                ptr = ptr->next;
            }
            bottom--;

            // bottom to top
            i = bottom;
            j = left;
            while(ptr && (i >= top))
            {
                ans[i][j] = ptr->val;
                i--;
                ptr = ptr->next;
            }
            left++;         
        }
        return ans;
    }
};