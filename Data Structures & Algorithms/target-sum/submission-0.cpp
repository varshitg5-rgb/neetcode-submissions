class Solution {
public:
    void help(vector<int>& nums, int target, int cur, int &count, int idx){
        if(idx==nums.size()){
            if(cur==target){
                count += 1;
                return;
            }else return;
        }

        int n = cur + nums[idx];
        help(nums,target,n,count,idx+1);
        int m = cur-nums[idx];
        help(nums,target,m,count,idx+1);
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        int cur = 0;
        help(nums,target,cur,count,0);
        return count;
    }
};
