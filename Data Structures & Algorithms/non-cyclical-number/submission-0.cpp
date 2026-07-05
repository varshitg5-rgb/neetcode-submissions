class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> u;
        while(n!=1){
            vector<int> digits;
            while(n){
                digits.push_back(n%10);
                n /= 10;
            }
            int sum =0;
            for(auto x : digits){
                sum += x*x;
            }
            if(u.find(sum)!=u.end()) return false;
            u.insert(sum);
            n = sum;
        }
        if(n==1) return true;
        return false;
    }
};
