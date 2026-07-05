class Solution {
public:
    void helper(vector<vector<int>> &v, vector<int> &cur, vector<int>& nums, int idx, int target){
        if(target==0){
            v.push_back(cur);
            return;
        }
        if(idx==nums.size()) return;

        if(target>=nums[idx]){
            cur.push_back(nums[idx]);
            helper(v,cur,nums,idx,target-nums[idx]);
            cur.pop_back();
        }
        helper(v,cur,nums,idx+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> v;
        int cursum = 0;
        helper(v,cur,nums,0,target);
        return v;
    }
};
