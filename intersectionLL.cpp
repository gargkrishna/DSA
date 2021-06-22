// problem link -> https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA,*b=headB;
        int n,m;
        n=m=0;
        while(a)
            n++,a = a->next;
        while(b)
            m++,b = b->next;
        if(n>m){
            n-=m;
            while(n--)
            headA = headA->next;
        }
        else{
            m-=n;
            while(m--)
            headB = headB->next;
        }
        while(headA){
            if(headA == headB) break;
             headA = headA->next;
             headB = headB->next;  
        }  
        return headA;
    }
};

// time O(n)
// space O(1)