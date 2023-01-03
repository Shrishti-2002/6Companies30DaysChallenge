class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int> a=nums;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1,n=0,m=0;
        while(j>i){
            if(m==0 && nums[i]==a[i]) i++;
            else m=1;
            if(n==0 && nums[j]==a[j]) j--;
            else n=1;
            if(m==1 && n==1) break;
        }
        if(i==j) return 0;
        return j-i+1;

    }
};
