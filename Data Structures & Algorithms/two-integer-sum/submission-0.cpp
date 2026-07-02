class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> u;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(u.find(target-nums[i])!=u.end()) {
                v.push_back(u[target-nums[i]]);
                v.push_back(i);
                return v;
            }
            u[nums[i]] = i;
        }
        return v;
    }
};
