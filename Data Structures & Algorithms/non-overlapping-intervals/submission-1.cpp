class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0 || intervals.size()==1) return 0;
        sort(intervals.begin(),intervals.end());
        int ans = 0;
        vector<vector<int>> res;
        int prev_end;
        for(auto x : intervals){
            if(res.empty() || prev_end<=x[0]){
                res.push_back(x);
                prev_end = x[1];
                ans++;
            }else{
                prev_end = min(prev_end,x[1]);
            }
        }
        return intervals.size()-ans;
    }
};
