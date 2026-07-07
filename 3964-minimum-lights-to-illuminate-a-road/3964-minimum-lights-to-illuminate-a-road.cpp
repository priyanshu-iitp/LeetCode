class Solution {
public:
    int minLights(vector<int>& lights) {

        int n=lights.size();
        vector<int>dup(n);
        vector<vector<int>>inter;
        for(int i=0;i<n;i++)
        dup[i]=lights[i];

        for(int i=0;i<n;i++)
        {   
            if(lights[i]!=0)
            {
                int l=max(0,i-lights[i]);
                int j=min(n-1,i+lights[i]);
                inter.push_back({l,j});
            }
        }

        //merge interval
        sort(inter.begin(),inter.end());
        vector<vector<int>>ans;
        int m=inter.size();
        if(m>0)
        {
            int start=inter[0][0];
            int end=inter[0][1];
            for(int i=1;i<m;i++)
            {
                if(end>=inter[i][0])
                {
                    end=max(end,inter[i][1]);
                }
                else
                {
                    ans.push_back({start,end});
                    start=inter[i][0];
                    end=inter[i][1];
                }
            }
            ans.push_back({start,end});

        }

        for(auto it:ans)
        {
            for(int i=it[0];i<=it[1];i++)
            dup[i]=-1;
        }

        int cnt=0;
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(dup[i]==0)cnt++;
            else 
            {
                if(cnt>0)
                res++;

                cnt=0;
            }

            if(cnt==3)
            res++,cnt=0;
        }

        if(cnt>0)
        res++;

        return res;
        
    }
};