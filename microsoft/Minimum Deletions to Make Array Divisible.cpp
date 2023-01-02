class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int a= INT_MAX;
        for(int i=0;i<numsDivide.size();i++){
            a=min(a,numsDivide[i]);
        }
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        unordered_set<int> s;
        for(int i=0;i<numsDivide.size();i++){
            s.insert(numsDivide[i]);
        }
        long long ans=0;
        for(auto it=m.begin();it!=m.end();it++){
            int k=(*it).first,f=0;
            cout<<k<<' ';
            if(k>a) return -1;
            for(auto i=s.begin();i!=s.end();i++){
                if((*i)%k!=0){
                    ans+=(*it).second;
                    f=1;
                    break;
                }
            }
            cout<<f<<' ';
            if(f==0) return ans;
        }
        if(ans==nums.size()) return -1;
        return ans;
    }
};
