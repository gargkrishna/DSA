// problem link -> https://leetcode.com/problems/linked-list-cycle/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next) return false;
        ListNode *h,*t;
        h = t = head;
       while(h&&h->next){
            t = t->next;
            h = h->next->next;
           if(t==h) return true;
        }
        return false;
    }
};

// time O(n)
// space O(1)