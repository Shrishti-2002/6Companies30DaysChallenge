class Solution {
public:
    string tostring(int a){
        if(a==0) return "0";
        string ans;
        while(a>0){
            int r=a%10;
            ans+=(r+'0');
            a/=10;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string getHint(string s, string g) {
        unordered_map<int,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        int k=0,a=0;
        for(int i=0;i<g.length();i++){
            if(g[i]==s[i]) a++;
            if(m[g[i]]>0) {m[g[i]]--; k++;}
        }
        string ans;
        ans+=tostring(a)+'A'+tostring(k-a)+'B';
        return ans;
    }
};
