class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(auto x : tokens){
            if(x=="+" || x=="-" || x=="*" || x=="/"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                int res;
                if(x=="+") res = a+b;
                else if(x=="-") res = b-a;
                else if(x=="*") res = a*b;
                else res = b/a;
                st.push(to_string(res));
            }
            else st.push(x);
        }

        return stoi(st.top());
    }
};
