class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++){
            string res = "";
            for(int j=0;j<ans.length();j++){
                if(strs[i][j]==ans[j]) res += ans[j];
                else break;
            }
            ans = res;
        }
        return ans;
    }
};