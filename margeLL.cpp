// problem link -> https://leetcode.com/problems/merge-two-sorted-lists/submissions/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // ListNode* d  = new ListNode(),*dd;
        // dd = d;
        // while(l1&&l2){
        //     dd->next = new ListNode();
        //     dd = dd->next;
        //     if(l1->val>l2->val) dd->val = l2->val,l2 = l2->next;
        //     else dd->val = l1->val,l1 = l1->next;
        // }
        // while(l1){
        //     dd->next = new ListNode();
        //     dd = dd->next;
        //     dd->val = l1->val,l1 = l1->next;
        // }
        // while(l2){
        //     dd->next = new ListNode();
        //     dd = dd->next;
        //     dd->val = l2->val,l2 = l2->next;
        // }
        // return d->next;
        

        // optimized in space
        ListNode *h1=l1,*h2=l2,*prev=NULL;
        while(h1&&h2){
            if(h1->val>h2->val){
                 while(h2&&h1->val>h2->val){
                     prev = h2;
                     h2 = h2->next;
                 }
                prev->next = h1;
            }
            else{
                while(h1&&h1->val<=h2->val){
                     prev = h1;
                     h1 = h1->next;
                 }
                prev->next = h2;
            }
        }
        if(!l2) return l1;
        if(!l1) return l2;
        if(l1->val>l2->val) swap(l1,l2);
        return l1;
    }
};

// time O(n)
// space O(1)