class Solution {
public:

    long long possible(vector<int>&piles,int mid)
    {
        long long hrs=0;
        for(auto it:piles)
        {   
            hrs+=(it/mid)+1;
            if(it%mid==0) hrs--;
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int high=0;
        for(auto it:piles)
        high=max(high,it);

        int low=1;
        int ans=INT_MAX;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            long long totalhr=possible(piles,mid);

            if(totalhr<=h)
            ans=min(ans,mid),high=mid-1;
            else low=mid+1;
        }

        return ans;

        
    }
};