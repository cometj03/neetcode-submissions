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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        int length = 0;
        while (curr) curr = curr->next, length++;
        length /= 2;
        curr = head;
        while (length--) curr = curr->next;

        ListNode* second = curr->next;
        ListNode* prev = curr->next = nullptr;
        while (second) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        ListNode *first = head;
        second = prev;

        while (second) {
            ListNode *tmp1 = first->next, *tmp2 = second->next;
            second->next = first->next;
            first->next = second;
            first = tmp1;
            second = tmp2;
        }
    }
};
