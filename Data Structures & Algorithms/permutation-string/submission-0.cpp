class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        unordered_map<char,int> mp;
        unordered_map<char,int> check;
        for(auto x : s1){
            mp[x]++;
        }

        for(int i=0;i<n;i++){
            if(mp.find(s2[i])!=mp.end()) check[s2[i]]++;
        }
        if(mp==check) return true;
        for(int i=n;i<m;i++){
            if(mp.find(s2[i-n])!=mp.end()) check[s2[i-n]]--;
            if(mp.find(s2[i])!=mp.end()) check[s2[i]]++;
            if(mp==check) return true;
        }
        return false;
    }
};
