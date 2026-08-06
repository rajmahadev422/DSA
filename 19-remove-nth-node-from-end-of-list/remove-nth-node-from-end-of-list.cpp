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
    pair<int, ListNode*> solve(ListNode* root, int &t) {
        if(!root) return {0, NULL};
        pair<int, ListNode*> p = solve(root->next, t);
        root->next = p.second;
        if(p.first + 1 == t) {
            return {p.first + 1, root->next};
        }
        return {p.first + 1, root};
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p = solve(head, n);
        return p.second;
    }
};