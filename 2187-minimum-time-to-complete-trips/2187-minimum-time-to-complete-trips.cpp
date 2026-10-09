class Solution {
public:
    bool check(long long mid,vector<int>&nums,int totalTrips)
    {
        long long ans=0;
        for(auto it:nums)
        {
            ans+=(mid/(long long )it);
            
        }
       return (ans>=totalTrips) ;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        

        long long right=1;
        long long left=1;

        for(auto it:time) 
        {   
            right=max(right,(long long)it);
        }

        right*=1ll*totalTrips;
        
        

        while(left<=right)
        {
            long long mid=left+(right-left)/2;

            if(check(mid,time,totalTrips)) right=mid-1;
            else left=mid+1;
        }

        return left;
        

        
    }
};