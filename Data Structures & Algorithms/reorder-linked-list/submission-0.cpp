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
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        deque<ListNode*> q;
        while(cur!=NULL){
            q.push_back(cur);
            cur = cur->next;
        }
        ListNode* prev = NULL;
        while(!q.empty()){
            ListNode* f = q.front();
            q.pop_front();
            if(prev!=NULL) prev->next = f;
            if(!q.empty()){
                ListNode* b = q.back();
                q.pop_back();
                f->next = b;
                prev = b;
            }else{
                prev = f;
            }
        }
        prev->next = NULL;
        return;
    }
};
