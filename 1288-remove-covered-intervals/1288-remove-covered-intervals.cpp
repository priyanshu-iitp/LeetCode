class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n=intervals.size();
        int merg=0;

        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];

        for(int i=1;i<n;i++)
        {
            if(start==intervals[i][0])
            {
                merg++;
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else if(end>=intervals[i][0] && end>=intervals[i][1])
            {
                merg++;
            }
            else
            {
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        

        return intervals.size()-merg;
        
        
    }
};