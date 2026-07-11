class Solution {
public:
    bool ispossible(vector<int>& weights,int w, int days)
    {
       int useday=1,load=0;
       for(auto it:weights)
       {
            if(load+it>w)
            {
                useday++;
                load=it;
            }
            else
            load+=it;
       }

       return useday<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int high=0;
        int low=0;  
        for(auto it:weights)
        {
            low=max(low,it);
            high+=it;
        }

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(ispossible(weights,mid,days)) high=mid-1;
            else  low=mid+1;
        }

        return low;
        
    }
};