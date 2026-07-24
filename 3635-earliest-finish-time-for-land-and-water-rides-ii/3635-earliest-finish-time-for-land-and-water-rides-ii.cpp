class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        

        int ls=landStartTime.size();
        int ws=waterStartTime.size();
        
        int ans=INT_MAX;

        int minland=INT_MAX;
        for(int i=0;i<ls;i++)
        {
            minland=min(minland,landStartTime[i]+ landDuration[i]);
        }

        //land->water
        
        for(int i=0;i<ws;i++)
        {
            int water=max(minland,waterStartTime[i])+waterDuration[i];
            ans=min(ans,water);
        }

        int minwater=INT_MAX;
        for(int i=0;i<ws;i++)
        {
            minwater=min(minwater,waterStartTime[i]+ waterDuration[i]);
        }

        //water->land
        
        for(int i=0;i<ls;i++)
        {
            int land=max(minwater,landStartTime[i])+landDuration[i];
            ans=min(ans,land);
        }
        

        return ans;

    }
};