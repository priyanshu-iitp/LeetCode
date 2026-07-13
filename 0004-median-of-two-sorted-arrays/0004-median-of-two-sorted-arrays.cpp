class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        int m=nums2.size();

        vector<int>ans;
        int f=0,s=0;
        while(f<n && s<m)
        {
            if(nums1[f]<=nums2[s])
            {
                ans.push_back(nums1[f]);
                f++;
            }
            else
            {
                ans.push_back(nums2[s]);
                s++;
            }
        }
        //if nums1 left
        while(f<n)
        {
            ans.push_back(nums1[f]);
            f++;
        }
        //if nums2 left
        while(s<m)
        {
            ans.push_back(nums2[s]);
            s++;
        } 

        int a=ans.size();

        if(a%2==0) 
        return (ans[a/2]+ans[(a/2)-1])/2.0;

        return (ans[a/2])/1.0;

    }
};