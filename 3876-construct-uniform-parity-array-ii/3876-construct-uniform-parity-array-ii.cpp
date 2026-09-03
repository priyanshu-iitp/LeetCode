class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int odd=0;
        int minio=INT_MAX;
        int minie=INT_MAX;

        for(auto it:nums1)
        {
            if(it%2==1)
            {
                odd++;
                minio=min(minio,it);
            }
            else
            minie=min(minie,it);
        }

        if(odd==nums1.size()|| odd==0)
        return true;

        return minie>minio;
        
    }
};