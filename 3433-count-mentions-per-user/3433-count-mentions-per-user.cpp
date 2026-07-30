class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        
        vector<int>ans(n,0);
        vector<int>online(n,0);

        sort(events.begin(),events.end(),[](vector<string>&a,vector<string>&b){
            
            if( stoi(a[1])==stoi(b[1]) ) return a[0]>b[0];
            return stoi(a[1])<stoi(b[1]);
        });

        for(auto it:events)
        {
            if(it[0]=="MESSAGE")
            {   
                if(it[2]=="ALL")
                {
                    for(int i=0;i<n;i++)
                    ans[i]+=1;
                }
                else if(it[2]=="HERE")
                {
                    for(int i=0;i<n;i++)
                    {
                        if(online[i]<=stoi(it[1]))
                        ans[i]+=1;
                    }
                }
                else
                {
                    int s=it[2].size();
                    int i=0;
                    int x=0;
                    while(i<s)
                    {   
                        char c=it[2][i];

                        if(isdigit(c)) x=x*10+(c-'0');

                        if(c==' ')
                        {
                            ans[x]+=1,x=0;
                        }

                        i++;
                    }
                    ans[x]+=1;
                }
            }
            else
            {
                online[stoi(it[2])]=stoi(it[1])+60;
            }
        }

        return ans;

    }
};