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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* cur = head;
        while(cur!=NULL){
            count++;
            cur = cur->next;
        }
        int i =0;
        cur = head;
        ListNode* prev = NULL;
        while(count-i>n){
            prev = cur;
            cur = cur->next;
            i++;
        }
        ListNode* temp = cur->next;
        if(prev!=NULL) prev->next = temp;
        else return temp;

        return head;
    }
};
