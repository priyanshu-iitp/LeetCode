class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        unordered_map<int,bool>m;
        int maxi=0;
        for(auto it:arr)
        {
            maxi=max(maxi,it);
            m[it]=1;
        }

        int cnt=0;
        for(int i=1;i<=maxi+k;i++)
        {
            if(!m.count(i))
            cnt++;

            if(cnt==k) return i;
        }

        return 0;
        
    }
};