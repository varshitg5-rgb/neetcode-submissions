class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_map<int,vector<int>> u;

        for(int i=0;i<triplets.size();i++){
            auto x = triplets[i];
            if(x[0]==target[0]){
                u[0].push_back(i);
            }
            if(x[1]==target[1]){
                u[1].push_back(i);
            }
            if(x[2]==target[2]){
                u[2].push_back(i);
            }
        }

        for(auto x : u[0]){
            if(triplets[x][1]>target[1] || triplets[x][2]>target[2]){
                erase(u[0],x);
            }
        }
        if(u[0].size()==0) return false;
        for(auto x : u[1]){
            if(triplets[x][0]>target[0] || triplets[x][2]>target[2]){
                erase(u[1],x);
            }
        }
        if(u[1].size()==0) return false;
        for(auto x : u[2]){
            if(triplets[x][0]>target[0] || triplets[x][1]>target[1]){
                erase(u[2],x);
            }
        }
        if(u[2].size()==0) return false;

        return true;
    }
};
