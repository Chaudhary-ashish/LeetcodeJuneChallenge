class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i,j,t,k;
        int flag;
        i=0;
        j=nums.size()-1;
        k=0;
        while(i<=j)
        {
            if(nums[i]==0)
            {
                nums[i]=1;
                i++;
                nums[k]=0;
                k++;
                continue;
            }
            if(nums[i]==1)
            {
                i++;
                continue;
            }
            if(nums[i]==2)
            {
                if(nums[j]==2)
                    j--;
                else
                {
                    t=nums[j];
                    nums[i]=t;
                    nums[j]=2;
                    j--;
                }
            }
        }
        //return nums;
    }
};