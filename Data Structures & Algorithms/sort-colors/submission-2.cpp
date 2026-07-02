class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int sidx = 0;
        int eidx = n-1;

        while(sidx!= n && nums[sidx]==0) sidx++;
        while(eidx>=0 && nums[eidx]==2) eidx--;

        int i = sidx;
        while(i<=eidx){
            if(nums[i]==0){
                nums[i] = nums[sidx];
                nums[sidx] = 0;
                sidx++;
            }else if(nums[i]==2){
                nums[i] = nums[eidx];
                nums[eidx] = 2;
                eidx--;
                i--;
            }
            i++;
        }
    }
};