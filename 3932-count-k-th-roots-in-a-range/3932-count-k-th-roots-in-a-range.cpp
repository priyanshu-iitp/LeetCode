class Solution {
public:
    bool maxpossible(int n,int k,int r,int l)
    {
        long long ans=1;
        while(k--)
        {
            ans=(ans*n);
            if(ans>r) return false;
        }
           return ans<=r;
    }

    bool minpossible(int n,int k,int r,int l)
    {
        long long ans=1;
        while(k--)
        {
            ans=(ans*n);
            if(ans>l) return false;
        }
        return ans<l;
    }
    int countKthRoots(int l, int r, int k) {
        
        int low=0,high=r;
        if(l==0&&r==0) return 1;

        //max value that exist in range beyound it next number is goes out of range
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(maxpossible(mid,k,r,l)) low=mid+1;
            else high=mid-1;
        }
        int maxnum=high;

        //min value that exist in range beyound it next number is goes out of range
        low=0,high=maxnum;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(minpossible(mid,k,r,l)) low=mid+1;
            else high=mid-1;
        }
        int minnum=high;

        return maxnum-minnum;


        //note :-minnum is not included in range hence maxnum-minnum;
        
    } 
};