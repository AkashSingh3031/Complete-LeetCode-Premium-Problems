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
    ListNode* plusOne(ListNode* head) {
        if (!head)
            return new ListNode(1);
        auto plused = plusOne(head->next);
        head->val += plused != head->next;
        if (head->val <= 9)
            return head;
        head->val = 0;
        plused->next = head;
        return plused;
    }
};