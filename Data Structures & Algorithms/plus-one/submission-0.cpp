class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 1;
        int i =0;
        while(carry!=0 && i<digits.size()){
            int sum = digits[i]+carry;
            digits[i] = sum%10;
            carry = sum/10;
            i++;
        }

        if(carry!=0){
            digits.push_back(carry);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
