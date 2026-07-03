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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* f = list1;
        ListNode* s = list2;
        ListNode* ans = new ListNode();
        ListNode* prev = ans;
        while(f!=NULL && s!=NULL){
            if(f->val < s->val){
                ans->next = f;
                f = f->next;
                ans = ans->next;
            }else{
                ans->next = s;
                s = s->next;
                ans = ans ->next;
            }
        }

        while(f!=NULL){
            ans->next = f;
            f = f->next;
            ans = ans->next;
        }

        while(s!=NULL){
            ans->next = s;
            s = s->next;
            ans = ans ->next;
        }

        return prev->next;
    }
};
