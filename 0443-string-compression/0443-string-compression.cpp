class Solution {
public:
    void numbers(int cnt,vector<int>& ans)
    {
        if(cnt<=1) return;
        while(cnt>0)
        {
            int rem=cnt%10;
            ans.push_back(rem);
            cnt/=10;
        }
        reverse(ans.begin(),ans.end());
    }
    int compress(vector<char>& chars) {
        
        int n=chars.size();
        char ch=chars[0];

        int idx=0;
        int cnt=1;

        for(int i=1;i<n;i++)
        {
            if(chars[i]==ch) cnt++;
            else
            {
                chars[idx++]=ch;

                vector<int>ans;
                numbers(cnt,ans);

                for(int i=0;i<ans.size();i++)
                chars[idx++]=ans[i]+'0';

                ch=chars[i];
                cnt=1;
            }
        }

        chars[idx++]=ch;

        vector<int>ans;
        numbers(cnt,ans);
        for(int i=0;i<ans.size();i++)
        chars[idx++]=ans[i]+'0';

        return idx;
    }
};