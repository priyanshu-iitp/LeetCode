class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n=nums1.size();
        int maxi=0;
        long long k=1ll*k1+k2;
        vector<int>diff(n);

        for(int i=0;i<n;i++)
        {
            diff[i]=abs(nums1[i]-nums2[i]);
            maxi=max(maxi,diff[i]);
        }

        vector<int>bucket(maxi+1);
        for(auto it:diff) bucket[it]++;
        
        for(int i=maxi;i>0 && k>0 ;i--)
        {
            int take=min(1ll*bucket[i],k);
            bucket[i]-=take;
            bucket[i-1]+=take;
            k-=take;
        }

        long long ans=0;
        for(int i=0;i<=maxi;i++)
        ans+=1ll*bucket[i]*i*i;

        return ans;

        
    }
};