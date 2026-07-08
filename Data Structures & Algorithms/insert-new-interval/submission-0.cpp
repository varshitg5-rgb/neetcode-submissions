class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if(n==0){
            ans.push_back(newInterval);
            return ans;
        }

        int l = 0;
        int r = n-1;
        while(l<=r){
            int m = l +(r-l)/2;
            if(intervals[m][0]<newInterval[0]){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        intervals.insert(intervals.begin() + l, newInterval);

        for(auto &interval : intervals){
            if(ans.empty() || ans.back()[1]<interval[0]){
                ans.push_back(interval);
            }else{
                ans.back()[1] = max(ans.back()[1],interval[1]);
            }
        }
        return ans;
    }
};
