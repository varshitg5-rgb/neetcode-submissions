class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0;
        int hi=n-1;
        while(l<=hi){
            int m = l + (hi-l)/2;
            if(nums[m]==target) return m;
            else if(nums[m]<target) l = m+1;
            else hi = m-1;
        }
        return -1;
    }
};
