class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> u;
        for(auto x : nums){
            if(u.find(x)!=u.end()) return true;
            u.insert(x);
        }
        return false;
    }
};