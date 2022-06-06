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
        ListNode* cur1=headA;
        ListNode* cur2=headB;
        int len1=0,len2=0;
        while(cur1!=NULL){
            len1++;
            cur1=cur1->next;
        }
        while(cur2!=NULL){
            len2++;
            cur2=cur2->next;
        }
        if(len2>len1){
            swap(headA,headB);
            swap(len2,len1);
        }
        int diff=len1-len2;
        cur1=headA,cur2=headB;
        while(diff--){
            cur1=cur1->next;
        }
        while(cur1!=cur2){
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return cur1;
    }
};