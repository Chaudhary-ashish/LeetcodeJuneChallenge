class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int flag=32;
        int ct;
        long long int ans=0;
        int x=0;
        while(flag--)
        {
            ct=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]&1>0)
                  ct++;
                nums[i]=nums[i]>>1;
            }
            if(ct%3>0)
                ans+=pow(2,x);
            x++;
        }
        return ans;
        
    }
};