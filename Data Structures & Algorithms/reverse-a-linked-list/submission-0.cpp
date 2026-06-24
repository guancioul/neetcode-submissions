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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = new ListNode();
        ListNode* pre = nullptr;
        ListNode* curr = head;
        ListNode* next = head;
        while(curr) {
            next = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = next;
        }
        newHead -> next = pre;
        return newHead -> next;
    }
};
