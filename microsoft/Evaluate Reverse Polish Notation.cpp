class Solution {
public:
    bool isOperator(string s){
        if(s.size()==1 &&(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/')) return true;
        return false;
    }
    int tonum(string s){
        int i=0,k=1;
        if(s[0]=='-') {k=-1; i=1;}
        int ans=0;
        for(;i<s.length();i++){
            ans=ans*10+(s[i]-'0');
        }
        return ans*k;
    }
    int solve(int c,int d,char oper){
        switch(oper){
            case '+': return c+d;
            case '-': return d-c;
            case '*': return c*d;
            case '/': return d/c;
        }
        return 0;
    }
    int evalRPN(vector<string>& t) {
        stack<int> st;
        for(int i=0;i<t.size();i++){
            int k;
            if(!isOperator(t[i])) {k=tonum(t[i]); st.push(k); continue;}
            int c=st.top();
            st.pop();
            int d=st.top();
            st.pop();
            int temp=solve(c,d,t[i][0]);
            st.push(temp);
        }
        return st.top();
    }
};