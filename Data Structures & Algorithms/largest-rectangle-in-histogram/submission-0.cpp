class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        vector<int> right(n);
        vector<int> left(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }

            int a = (s.empty())? n-i : s.top()-i;
            s.push(i);
            right[i] = a*heights[i];
        }
        s={};
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }

            int a = (s.empty())? i+1 : i-s.top();
            s.push(i);
            left[i] = a*heights[i];
        }
        int ans =0;
        for(int i=0;i<n;i++){
            int a = left[i]+right[i] - heights[i];
            ans =max(ans,a);
        }
        return ans;
    }
};
