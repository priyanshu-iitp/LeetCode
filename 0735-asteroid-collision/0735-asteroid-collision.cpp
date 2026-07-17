class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {

        int n=nums.size();
        stack<int>s;

        for(auto it:nums)
        {   
            bool flag=true;
            while (!s.empty() && s.top()>0 && it<0) 
            {
                if(abs(it)==s.top())
                {
                    s.pop(),flag=false;
                    break;
                }
                else if(s.top()>abs(it))
                {
                    flag=false;
                    break;
                }
                else if(s.top()<abs(it))
                s.pop();
            }

            if(flag)
            s.push(it); 
        }

        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;


        
    }
};