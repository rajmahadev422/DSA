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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        ListNode* root = head;

        vector<int> v;
        int idx = 0;
        while (root->next->next) {
            if (root->val > root->next->val and
                root->next->val < root->next->next->val)
                v.push_back(idx);
            else if (root->val < root->next->val and
                     root->next->val > root->next->next->val)
                v.push_back(idx);
            idx++;
            root = root->next;
        }

        vector<int> ans = {-1, -1};

        if (v.size() <= 1)
            return ans;

        sort(v.begin(), v.end());

        ans[1] = v[v.size() - 1] - v[0];
        int mn = INT_MAX;
        for (int i = 0; i < v.size() - 1; i++)
            mn = min(mn, v[i + 1] - v[i]);

        ans[0] = mn;

        return ans;
    }
};