class Solution {
public:
    int missingInteger(vector<int>& nums) {

        unordered_map<int,bool>m;
        int n=nums.size();

       

        int sum=nums[0];
        bool flag=true;
        m[nums[0]]=true;

        for(int i=1;i<n;i++)
        {   
            m[nums[i]]=true;
            if(nums[i]==nums[i-1]+1 && flag)
            sum+=nums[i];
            else flag=false;
        }

        for(int i=sum;i<=51;i++)
        {
            if(!m.count(i)) 
            return i;
        }
        return sum;

        
    }
};