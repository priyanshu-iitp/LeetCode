class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;

        int idx2=n/2;
        int idx1=idx2-1;

        int f=0,s=0;
        int cnt=0;
        int eleidx1=0,eleidx2=0;
        while(f<n1 && s<n2)
        {
            if(nums1[f]<=nums2[s])
            {
                if(cnt==idx2)eleidx2=nums1[f];
                if(cnt==idx1)eleidx1=nums1[f];
                
                f++;
                cnt++;
            }
            else
            {
                if(cnt==idx2)eleidx2=nums2[s];
                if(cnt==idx1)eleidx1=nums2[s];
                s++;
                cnt++;
            }
        }
        //if nums1 left
        while(f<n1)
        {
            if(cnt==idx2)eleidx2=nums1[f];
            if(cnt==idx1)eleidx1=nums1[f];
                
            f++;
            cnt++;
        }
        //if nums2 left
        while(s<n2)
        {
            if(cnt==idx2)eleidx2=nums2[s];
            if(cnt==idx1)eleidx1=nums2[s];
                
            s++;
            cnt++;
        } 

        if(n%2==1) return eleidx2;

        return (eleidx1+eleidx2)/2.0;

    }
};