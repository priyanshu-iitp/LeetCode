class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        string s="123456789";
        int n=s.size();

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=i;j<n;j++)
            {
                temp=temp*10+s[j]-'0';
                
                if(low<=temp && temp<=high)
                ans.push_back(temp);
                
                if(temp>high)
                break;

            }
        }

        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};