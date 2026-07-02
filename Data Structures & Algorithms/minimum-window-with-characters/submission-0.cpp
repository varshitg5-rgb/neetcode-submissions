class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n) return "";

        unordered_map<char,int> u;
        for(auto x : t){
            u[x]++;
        }
        int targetremaining = m;
        int st = 0;
        int len = INT_MAX;
        string ans = "";
        for(int i=0;i<n;i++){
            char a = s[i];
            if(u.find(a)!=u.end() && u[a]>0){
                targetremaining--;
            }
            u[a]--;
            

            if(targetremaining==0){
                while(u[s[st]]<0){
                    u[s[st]]++;
                    st++;
                }
                
                if(i-st+1<len){
                    len = i-st+1;
                    ans = s.substr(st,len);
                }

                u[s[st]]++;
                st++;
                targetremaining++;
            }
        }
        return ans;
    }
};
