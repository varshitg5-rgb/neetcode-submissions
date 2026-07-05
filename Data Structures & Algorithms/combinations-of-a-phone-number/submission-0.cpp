class Solution {
public:
    vector<string> letterCombinations(string digits) {
         unordered_map<char,vector<string>> mp;
        mp['2'] = {"a","b","c"};
        mp['3'] = {"d","e","f"};
        mp['4'] = {"g","h","i"};
        mp['5'] = {"j","k","l"};
        mp['6'] = {"m","n","o"};
        mp['7'] = {"p","q","r","s"};
        mp['8'] = {"t","u","v"};
        mp['9'] = {"w","x","y","z"};

        vector<string> ans;
        int n = digits.length();
        for(auto t : mp[digits[0]]){
            ans.push_back(t);
        }
        for(int i=1;i<n;i++){
            int k = ans.size();
            for(int j=0;j<k;j++){
                for(auto t : mp[digits[i]]){
                    string cur = ans[0];
                    cur += t;
                    ans.push_back(cur);
                }
                ans.erase(ans.begin());
            }
        }
        return ans;
    }
};
