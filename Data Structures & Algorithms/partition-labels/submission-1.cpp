class Solution {
public:
    static bool comp(pair<int,int> &p1, pair<int,int> &p2){
        return p1.first<p2.first;
    }
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>> u;
        int i =0;
        for(auto x : s){
            if(u.find(x)==u.end()){
                u[x].first = i;
            }
            u[x].second = i;
            i++;
        }
        vector<pair<int,int>> v;
        for(auto x : u){
            v.push_back(x.second);
           
        }
        
        sort(v.begin(),v.end(),comp);
        
        vector<pair<int,int>> res;
        res.push_back(v[0]);
        for(int j=1;j<v.size();j++){
            if(v[j].first<res[res.size()-1].second){
                res[res.size()-1].second = max(res[res.size()-1].second,v[j].second);
            }else{
                res.push_back(v[j]);
            }
        }
        vector<int> ans;
        for(auto x : res){
            
            ans.push_back(x.second-x.first+1);
        }
        return ans;
    }
};
