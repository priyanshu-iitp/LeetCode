class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n=arr.size();
        if(n==0) return arr;
        vector<pair<int,int>>temp(n);  //element and their index

        for(int i=0;i<n;i++)
        temp[i]={arr[i],i};

        sort(temp.begin(),temp.end());

        vector<int>ans(n);
        ans[temp[0].second]=1;
        int idx=1;
        
        for(int i=1;i<n;i++)
        {
            if(temp[i].first==temp[i-1].first)
            ans[temp[i].second]=idx;
            else
            {
                idx++;
                ans[temp[i].second]=idx;
            }
        }

        return ans;



        
    }
};