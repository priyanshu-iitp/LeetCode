class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n=nums.size();

       
        stack<int>s;//min element
        int mini=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            mini=min(mini,nums[i]);
            s.push(mini);
        }

        int maxi=INT_MIN;

       for(int i=0;i<n;i++)
       {
            maxi=max(maxi,nums[i]);

            int x=maxi-s.top();
            s.pop();

            if(x<=k)
            return i;
       }
       return -1;
        
    }
};