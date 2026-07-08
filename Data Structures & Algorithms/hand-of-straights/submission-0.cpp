class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        unordered_map<int,int> u;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x : hand){
            u[x]++;
            pq.push(x);
        }

        while(!pq.empty()){
            auto a = pq.top();
            if(u.find(a)!=u.end()){
                for(int i=0;i<groupSize;i++){
                    if(u.find(a+i)!=u.end()){
                        u[a+i]--;
                        if(u[a+i]==0) u.erase(a+i);
                    }else{
                        return false;
                    }
                }
            }
            pq.pop();
        }

        return true;

        
    }
};
