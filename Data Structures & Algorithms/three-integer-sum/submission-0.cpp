class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i-1>=0 && nums[i]==nums[i-1]) continue;
            int a = nums[i];
            int j = i+1;
            int k = n-1;
            while(j<k){
                int b = nums[j];
                int c = nums[k];
                if(b+c==-1*a){
                    ans.push_back({a,b,c});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(k>j && nums[k]==nums[k+1]) k--;
                }else if(b+c<-1*a){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};
