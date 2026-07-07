class Solution {
public:
    int minLights(vector<int>& lights) {

        int n=lights.size();
        vector<int>dup(n+1,0);

        for(int i=0;i<n;i++)
        {
            if(lights[i]==0) continue;

            int l=max(0,i-lights[i]);
            int r=min(n-1,i+lights[i]);

            dup[l]++;
            
            if(r+1<n)
            dup[r+1]--;
        }

        int dist=0;
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            dist+=dup[i];
            if(dist==0)
            cnt++;
            else
            {
                ans+=(cnt+2)/3;
                cnt=0;
            }
        }
        ans+=(cnt+2)/3;

        return ans;
        
    }
};