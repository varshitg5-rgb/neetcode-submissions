class KthLargest {
public:
    //priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq2;
    int n;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto x : nums){
            pq2.push(x);
            if(pq2.size()>n) pq2.pop();
        }
    }
    
    int add(int x) {
        pq2.push(x);
        if(pq2.size()>n) pq2.pop();
        return pq2.top();
    }
};
