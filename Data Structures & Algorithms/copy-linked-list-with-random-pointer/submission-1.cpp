/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> M;
        Node *iter = head, *prev = nullptr;

        while (iter) {
            Node *node = new Node(iter->val);
            M[iter] = node;
            if (prev) prev->next = node;
            prev = node;
            iter = iter->next;
        }
        
        Node *newIter = M[head];
        iter = head;
        while (iter) {
            if (iter->random) {
                newIter->random = M[iter->random];
            }
            iter = iter->next;
            newIter = newIter->next;
        }
        return M[head];
    }
};
