class Solution {
public:
    void make(string & s,int i,unordered_map<int,char>&m)
    {
        while(i>0)
        {
            if(m.count(i))
            {
                char c=m[i];
                s.push_back(c);
                i=0;
            }
            else
            {   
                int idx=-1;
                for(int j=0;j<26;j++)
                {
                    int pwr=1<<j;
                    if(pwr>i) break;
                
                    idx=j;
                }

                s.push_back('a'+idx);
                int p=pow(2,idx);
                i-=p;

            }
        }

    }
    vector<string> largestString(vector<int>& nums) {

       
        int n=nums.size();

        unordered_map<int,char>m;
        for(int i=0;i<26;i++)
        {
            int x=1<<i;
            m[x]='a'+i;
        }

        vector<string>ans(n);
        for(int i=0;i<nums.size();i++)
        {
            string s="";
            make(s,nums[i],m);
            ans[i]=s;
        }

        return ans;


        
        
    }
};