class Solution {
public:
    vector<string> letterCombinations(string digits) {

        unordered_map<int,vector<string> >m;
        m[2]={"a","b","c"};
        m[3]={"d","e","f"};
        m[4]={"g","h","i"};
        m[5]={"j","k","l"};
        m[6]={"m","n","o"};
        m[7]={"p","q","r","s"};
        m[8]={"t","u","v"};
        m[9]={"w","x","y","z"};

        int n=digits.size();
        if(n==1)return m[digits[0]-'0']; 
        else if(n==2)
        {
            vector<string>ans;
            vector<string>p=m[digits[0]-'0'];
            vector<string>q=m[digits[1]-'0'];

            int n1=p.size();
            int n2=q.size();

            for(int i=0;i<n1;i++)
            {
                string t="";
                for(int j=0;j<n2;j++)
                {
                    t=p[i]+q[j];
                    ans.push_back(t);
                }
            }

            return ans;
        }
        else if(n==3)
        {
            vector<string>ans;
            vector<string>p=m[digits[0]-'0'];
            vector<string>q=m[digits[1]-'0'];
            vector<string>r=m[digits[2]-'0'];

            int n1=p.size();
            int n2=q.size();
            int n3=r.size();

            for(int i=0;i<n1;i++)
            {
                for(int j=0;j<n2;j++)
                {   
                    for(int k=0;k<n3;k++)
                    {
                        string t = p[i]+q[j]+r[k];
                        ans.push_back(t);
                    }
                }
            }

            return ans;
        }
        else
        {
            vector<string>ans;
            vector<string>p=m[digits[0]-'0'];
            vector<string>q=m[digits[1]-'0'];
            vector<string>r=m[digits[2]-'0'];
            vector<string>s=m[digits[3]-'0'];

            int n1=p.size();
            int n2=q.size();
            int n3=r.size();
            int n4=s.size();

            for(int i=0;i<n1;i++)
            {
                for(int j=0;j<n2;j++)
                {   
                    for(int k=0;k<n3;k++)
                    {
                        for(int l=0;l<n4;l++)
                        {
                            string t = p[i]+q[j]+r[k]+s[l];
                            ans.push_back(t);
                        }
                    }
                }
            }

            return ans;
        }



        return {};
        
    }
};