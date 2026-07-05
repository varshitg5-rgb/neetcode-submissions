class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        v.push_back({});
    
        for(auto x : nums){
            int n = v.size();
            for(int i=0;i<n;i++){
                auto t = v[i];
                t.push_back(x);
                v.push_back(t);
            }
        }

        return v;
    }
};
