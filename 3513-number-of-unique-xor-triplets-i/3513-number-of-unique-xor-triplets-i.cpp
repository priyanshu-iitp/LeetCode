class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n=nums.size();


        //edge case
        if(n<=2) return n;
        if(n==3) return  4;

        int ans=0;
        for(int i=4;i<=1000000;i=i*2)
        {

            if(i==n)
            {
                ans=i*2;
                break;
            }
            else if(n<i)
            {
                ans=i;
                break;
            }
        }

        return ans;
        
    }
};