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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        
        unordered_set<unsigned int> visited;
        while (head) {
            std::uintptr_t p = reinterpret_cast<std::uintptr_t>(head);
            if (visited.find(p) != visited.end()) return true;
            visited.insert(p);
            head = head->next;
        }
        return false;
    }
};
