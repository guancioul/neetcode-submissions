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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* result = lists[0];
        for(int i=1; i<lists.size(); i++) {
            result = mergeLists(result, lists[i]);
        }
        return result;
    }
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* newNode = new ListNode();
        ListNode* newCurr = newNode;
        while(curr1 && curr2) {
            if(curr1->val <= curr2->val) {
                newCurr -> next = curr1;
                newCurr = newCurr -> next;
                curr1 = curr1 -> next;
            } else {
                newCurr -> next = curr2;
                newCurr = newCurr -> next;
                curr2 = curr2 -> next;
            } 
        }
        if(curr1) newCurr -> next = curr1;
        if(curr2) newCurr -> next = curr2;
        return newNode -> next;
    }
};
