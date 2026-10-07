class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& nums) {

        int n=s.size();
        vector<int>diff(n+1,0);

        for(auto it:nums)
        {
            int start=it[0];
            int end=it[1];
            int k=it[2];

            if(k==0)
            {
                diff[start]+=-1;;
                diff[end+1]+=1;
            }
            else
            {
                diff[start]+=1;;
                diff[end+1]+=-1;
            }
        }

        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=diff[i];
            s[i]=((s[i]-'a'+sum)%26+26)%26+'a';
        }
        

        return s;

        

        
        
    }
};