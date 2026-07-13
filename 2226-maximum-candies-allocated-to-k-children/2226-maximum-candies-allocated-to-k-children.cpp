class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        int n=candies.size();
     
        int low=1;
        int high=INT_MIN;
        for(auto it:candies)
        {
            high=max(high,it);
        }

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            long long ans=0;
            for(auto it:candies)
            {
               ans+=it/mid;
            }

            if(ans>=k) low=mid+1;
            else if(ans<k) high=mid-1;
        }


        

        return high;
        
    }
};