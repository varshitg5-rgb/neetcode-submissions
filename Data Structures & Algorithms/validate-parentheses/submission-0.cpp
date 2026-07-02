class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x : s){
            if(x=='(' || x=='{' || x=='[') st.push(x);
            else{
                if(x==')'){
                    if(st.empty() || st.top()!='(') return false;
                }

                else if(x=='}'){
                    if(st.empty() || st.top()!='{') return false;
                }

                else if(x==']'){
                    if(st.empty() || st.top()!='[') return false;
                }

                st.pop();
            }
        }
        return st.empty();


    }
};
