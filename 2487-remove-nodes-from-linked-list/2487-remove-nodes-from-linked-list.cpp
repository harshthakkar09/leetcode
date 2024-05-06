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
    
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* next;
        while(cur != NULL){
            next = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    
    void printLL(ListNode* head){
        while(head != NULL){
            cout << (head -> val) <<"\n";
            head = head -> next;
        }
    }
    
    ListNode* removeNodes(ListNode* head) {
        ListNode* newHead = reverse(head);
        // printLL(newHead);
        int maximum = INT_MIN;
        ListNode* cur = newHead;
        ListNode* pre = NULL;
        while(cur != NULL){
            maximum = max(maximum, cur -> val);
            if(cur -> val < maximum){
                pre -> next = cur -> next;
                ListNode* del = cur;
                cur = cur -> next;
                del -> next = NULL;
            }
            else{
                pre = cur;
                cur = cur -> next;
            }
        }
        return reverse(newHead);
    }
};