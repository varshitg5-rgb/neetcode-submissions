/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        unordered_map<Node*,Node*> mp;
        mp[NULL] = NULL;
        while(cur!=NULL){
            Node* temp = new Node(cur->val);
            mp[cur] = temp;
            cur = cur->next;
        }

        cur = head;
        Node* ans = NULL;
        while(cur!=NULL){
            Node* temp = mp[cur];
            if(cur==head) ans = mp[cur];
            temp->next = mp[cur->next];
            temp->random = mp[cur->random];
            cur = cur->next;
        }
        return ans;

    }
};
