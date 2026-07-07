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
    ListNode* merge2(ListNode* l1, ListNode* l2){   
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        while(cur1!=NULL && cur2!=NULL){
            if(cur1->val<cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;
            }else{
                cur->next = cur2;
                cur2 = cur2->next;
            }
            
            cur = cur->next;
        }
        while(cur1!=NULL){
            cur->next = cur1;
            cur1 = cur1->next;
            cur = cur->next;
        }
        while(cur2!=NULL){
            cur->next = cur2;
            cur2 = cur2->next;
            cur = cur->next;
        }
        return ans->next;

    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if (lists.size() == 1) return lists[0];
        vector<ListNode*> nlist;
        for(int i=0;i<lists.size();i=i+2){
            if(i+1<lists.size()){
                nlist.push_back(merge2(lists[i],lists[i+1]));
            }
        }
        if(lists.size()%2!=0){
            nlist.push_back(lists[lists.size()-1]);
        }
        if(nlist.size()==1) return nlist[0];
        return mergeKLists(nlist);
    }
};
