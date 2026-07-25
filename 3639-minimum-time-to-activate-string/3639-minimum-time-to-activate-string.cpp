class Solution {
public:

    long long count(string&t)
    {
        int n=t.size();
        long long total=1ll*n*(n+1)/2;

        int len=0;
        long long nonstar=0;
        for(auto it:t)
        {
            if(it=='*')
            {
                nonstar+=1ll*len*(len+1)/2;
                len=0;
            }
            else
            len++;
        }
        nonstar+=1ll*len*(len+1)/2;

        return total-nonstar;

    }
    int minTime(string s, vector<int>& order, int k) {
        

        int n=s.size();



        int l=0,r=n-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;

            string t=s;
            for(int i=0;i<=mid;i++)
            t[order[i]]='*';

            if(count(t)>=k) r=mid;
            else l=mid+1;
        }
        string t=s;
        for(int i=0;i<=l;i++)
        t[order[i]]='*';

        if(count(t)<k)return -1;

        return l;
    }
};