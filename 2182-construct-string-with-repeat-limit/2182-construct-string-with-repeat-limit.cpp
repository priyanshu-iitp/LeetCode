class Solution {
public:
    string repeatLimitedString(string s, int limit) {

       vector<int>fr(26,0);
       for(auto it:s)
       fr[it-'a']++;

        string ans="";

        int i=25;
        while(i>=0)
        {
            if(fr[i]==0)
            {
                i--;
                continue;
            }

            bool br=true;
            while (fr[i]>limit)
            {
                int x=limit;
                while(x--) 
                {   
                    ans.push_back('a'+i);
                } 
                
                fr[i]-=limit;

                bool found=false;
                for(int j=i-1;j>=0;j--)
                {
                    if(fr[j]!=0)
                    {
                        ans.push_back('a'+j);
                        fr[j]--;
                        found=true;
                        break;
                    }
                }
                if(found==false) 
                {
                    br=false;
                    break;
                }



            }
            if(fr[i]<=limit && br==true)
            {
                while(fr[i]--) ans.push_back('a'+i);
            }

            i--;
        }

        return ans;

        
    }
};