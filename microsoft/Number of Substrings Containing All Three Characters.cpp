class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m;
        int i=0,j=0;
        int n=s.length();
        int c=0;
        while(j<n){
            if(m.size()<3){
                m[s[j]]++;
                j++;
            } 
            while(m.size()==3){
                c+=n-j+1;
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
            }
        }
        return c;
    }
};
