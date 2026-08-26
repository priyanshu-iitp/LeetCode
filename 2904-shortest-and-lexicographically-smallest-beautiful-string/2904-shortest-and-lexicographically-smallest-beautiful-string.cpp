class Solution {
public:
    
    string shortestBeautifulSubstring(string s, int k) {

        int n=s.size();
        int idx=-1;
        int len=INT_MAX;
        int ones=0;
        int l=0;

        for(int r=0;r<n;r++)
        {   
            if(s[r]=='1') ones++;

            while(ones>k)
            {
                if(s[l]=='1')ones--;
                l++;
            }

            while(ones==k && l<r && s[l]=='0')
            {
                l++;
            }



            if(ones==k && len>r-l+1)
            {
                idx=l;
                len=r-l+1;
            }

        }

        if(idx==-1) return "";
        
        l=0;
        ones=0;
        vector<string>ans;
        for(int r=0;r<n;r++)
        {   
            if(s[r]=='1') ones++;

            while(ones>k)
            {
                if(s[l]=='1')ones--;
                l++;
            }

            while(ones==k && l<r && s[l]=='0')
            {
                l++;
            }



            if(ones==k && len==r-l+1)
            {
                ans.push_back(s.substr(l,len));
            }

        }



        sort(ans.begin(),ans.end());
        return ans[0];
       
        
        
    }
};