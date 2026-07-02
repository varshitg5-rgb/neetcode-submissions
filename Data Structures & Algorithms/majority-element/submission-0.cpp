class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int c_heighest;
        for(int i=0;i<nums.size();i++){
             if(count==0){
                c_heighest = nums[i];
            }
            if(nums[i]==c_heighest) count ++;
            else count--;
        }
        return c_heighest;
    }
};