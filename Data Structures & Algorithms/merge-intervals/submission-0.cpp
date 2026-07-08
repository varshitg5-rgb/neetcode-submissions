class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n==0) return ans;
        sort(intervals.begin(),intervals.end(),comp);
        for(int i=0;i<n;i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            if(ans.empty() || x>ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};
