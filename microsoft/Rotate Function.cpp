class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int s=0,c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s+=nums[i];
            c+=i*nums[i];
        }
        int ans=c;
        for(int i=1;i<=n;i++){
            ans=max(ans,c);
            c=c+s-n*nums[n-i];
        }
        return ans;
    }
};
