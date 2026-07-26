class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {


        int n=s1.size();
        int m=s2.size();
        
        int fir=0;
        int sec=0;

        vector<vector<int>>ans;
        while(fir<n && sec<m)
            {
                if(s1[fir][0]<s2[sec][0])
                {
                    s1[fir][1]=s1[fir][1]+s2[sec][1];
                    ans.push_back(s1[fir]);
                        fir++;
                }
                else if(s1[fir][0]==s2[sec][0])
                {
                    s1[fir][1]=s1[fir][1]+s2[sec][1];
                    ans.push_back(s1[fir]);
                        fir++;
                        sec++;
                }
                else
                {
                    s2[sec][1]=s1[fir][1]+s2[sec][1];
                    ans.push_back(s2[sec]);
                    sec++;
                }
            }

          
           while(fir<n)
               {
                   ans.push_back(s1[fir]);
                   fir++;
               }

        while(sec<m)
               {
                   ans.push_back(s2[sec]);
                   sec++;
               }


        // sort(ans.begin(),ans.end());
        return ans;

        
    }
};