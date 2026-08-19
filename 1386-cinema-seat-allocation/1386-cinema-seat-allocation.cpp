class Solution {
public:
    int safe(vector<int>&temp)
    {
        unordered_map<int,int>m;
        for(auto it:temp)
        {
            m[it]=1;
        }
        int ans=0;
        if(m[2]==0 && m[3]==0 && m[4]==0 && m[5]==0) 
        {   
            m[2]=1,m[3]=1,m[4]=1,m[5]=1;
            ans++; 
        }
        if(m[4]==0 && m[5]==0 && m[6]==0 && m[7]==0)
        {
            m[4]=1,m[5]=1,m[6]=1,m[7]=1;
            ans++; 
        }
        if(m[6]==0 && m[7]==0 && m[8]==0 && m[9]==0) ans++;

        return ans;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {

        int ans=2*n;

        unordered_map<int,vector<int> >m;
        for(auto it:rs)
        {
            int row=it[0];
            int col=it[1];

            if(col==1 || col==10) continue;
            m[row].push_back(col);
        }

        for(auto it:m)
        {
            int row=it.first;
            vector<int>temp=it.second;

            if(temp.size()>=5)
            ans-=2;
            else if(temp.size()==1)
            ans-=1;
            else
            ans=ans-(2-safe(temp));
        }

        return ans;

        
       



        
    }
};