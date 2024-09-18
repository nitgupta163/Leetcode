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
    int gcd(int a, int b)
    {
        if(!b)
        return a;
        return gcd(b,a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        if(!head->next)
        return head;
        ListNode* ptr = head;
        while(ptr->next)
        {
            ListNode* sNext = ptr->next;
            ptr->next = new ListNode(gcd(ptr->val,sNext->val));
            ptr = ptr->next;
            ptr->next = sNext;
            ptr = ptr->next;
        }   
        return head;     
    }
};