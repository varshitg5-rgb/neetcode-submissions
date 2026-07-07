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
    pair<ListNode*,ListNode*> rev(ListNode* head, int k){
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* ans;
        int i = 0;
        while(i<k && cur!=NULL){
            ListNode* temp = cur->next;
            cur->next = prev;
            if(prev==NULL) ans = cur;
            prev = cur;
            cur = temp;
            i++;
        }
        return {prev,ans};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int i = 0;
        vector<ListNode*> kth;
        while(cur!=NULL){
            
            if(i%k==0){
                kth.push_back(cur);
                cout << cur->val << endl;
            }
            
            i++;
            cur = cur->next;
        }
        ListNode* lhead = kth[kth.size()-1];
        if(i%k!=0){
            kth.pop_back();
        }
        ListNode* ans = NULL;
        ListNode* prevhead = NULL;
        for(auto x : kth){
            auto y = rev(x,k);
            //cout << y.first->val << " " << y.second ->val << endl;
            if(ans==NULL){
                ans = y.first;
            }
            if(prevhead!=NULL){
                prevhead->next = y.first;
            }
            prevhead = y.second;
        }
        if(i%k!=0){
            prevhead->next = lhead;
        }
        return ans;
    }
};
