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
        
        vector<int> ans = {-1, -1};
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int index = 1;
        int first = -1;
        int last = -1;
        
        int minDist = INT_MAX;
        
        while (curr->next != NULL) {
            
            // Check if curr is a critical point
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                // First critical point
                if (first == -1) {
                    first = index;
                }
                
                // If this is not the first critical point
                if (last != -1) {
                    minDist = min(minDist, index - last);
                }
                
                last = index;
            }
            
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        // Need at least 2 critical points
        if (first == last) {
            return ans;
        }
        
        // Maximum distance = last critical point - first critical point
        int maxDist = last - first;
        
        return {minDist, maxDist};
    }
};