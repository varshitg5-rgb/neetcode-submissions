class Solution {
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        
        return a.second > b.second;
    }
};
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        unordered_map<int,int> u;
        for(auto x : nums){
            u[x]++;
        }
        for(auto y : u){
            pq.push({y.first,y.second});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()!=0){
            pair<int,int> temp = pq.top();
            ans.push_back(temp.first);
            pq.pop();
        }
        return ans;
    }
};
