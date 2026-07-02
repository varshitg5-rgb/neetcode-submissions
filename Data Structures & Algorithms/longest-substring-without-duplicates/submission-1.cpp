class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int ans =0;
        int st = 0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]>=st){
                    ans = max(ans,i-st);
                    st = mp[s[i]]+1;
                }else{

                }
            }
            mp[s[i]] = i;
            ans = max(ans,i-st+1);
        }
        return ans;
    }

};
