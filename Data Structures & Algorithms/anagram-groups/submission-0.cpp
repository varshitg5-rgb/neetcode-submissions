class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> u;
        for(auto x : strs){
            string y = x;
            sort(y.begin(),y.end());
            u[y].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto it = u.begin();it!=u.end();it++){
            ans.push_back(it->second);
        }
        return ans;
        
    }
};
