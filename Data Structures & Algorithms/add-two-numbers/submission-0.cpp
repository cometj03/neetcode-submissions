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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        int carry = 0;
        while (1) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            l1->val = sum;
            if (!l1->next) {
                l1->next = l2->next;
                break;
            }
            if (!l2->next) {
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (carry) {
            while (l1->next) {
                l1 = l1->next;
                l1->val += carry;
                carry = l1->val / 10;
                l1->val %= 10;
            }
            if (carry) {
                l1->next = new ListNode(carry);
            }
        }
        return head;
    }
};
