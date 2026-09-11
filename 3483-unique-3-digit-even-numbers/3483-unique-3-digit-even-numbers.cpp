class Solution {
public:
    
    int totalNumbers(vector<int>& nums) {

        unordered_set<string>s;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;

                for(int k=0;k<n;k++)
                {
                    if(i==k || j==k) continue;

                    int x=(nums[i]*100)+(nums[j]*10)+nums[k];
                    string a=to_string(x);
                    if(a.size()==3 && (a[2]-'0')%2==0) s.insert(a);
                }
            }
        }

        return s.size();


        
        
    }
};