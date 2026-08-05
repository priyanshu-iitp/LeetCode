class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum=0;
        for(auto it:nums)
        sum+=it;

        if(sum%2==1) return false;
        
        int n=nums.size();
        int k=sum/2;

        vector<bool>prev(k+1,0);
        vector<bool>temp(k+1,0);

       
        prev[0]=temp[0]=true;

        if(k>=nums[0])
        prev[nums[0]]=true;


        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                //not pick
                bool notpick=prev[j];

                //pick
                bool pick=false;
                if(j>=nums[i])
                pick=prev[j-nums[i]];

                temp[j]=pick||notpick;
            }
            prev=temp;
        }
        return prev[k];
        
    }
};