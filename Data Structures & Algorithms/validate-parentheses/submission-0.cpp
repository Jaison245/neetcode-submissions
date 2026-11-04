class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            char p = s[i];

            if(p == '{' || p == '(' || p == '['){
                st.push(p);
            }else{
                if(st.empty()) return false;
                char n = st.top();
                st.pop();
                if((n == '[' && p == ']') || (n == '{' && p == '}') || (n == '(' && p == ')') ){
                    continue;
                }else{
                    return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
        
    }
};
