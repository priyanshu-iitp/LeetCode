class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int n=nums.size();
        //create closest x;
        vector<int>close(n,0);
        close[0]=1;
        close[n-1]=n-2;
        for(int i=1;i<=n-2;i++)
        {
            if( abs(nums[i]-nums[i-1]) <= abs(nums[i]-nums[i+1])  )
            close[i]=i-1;
            else
            close[i]=i+1;
        }

        //left to right min cost
        vector<int>lr(n,0);
        for(int i=1;i<n;i++)
        {
            if(close[i-1]==i)
            lr[i]=1+lr[i-1];
            else  
            lr[i]=lr[i-1]+abs(nums[i]-nums[i-1]);
        }
        //right to left min cost
        vector<int>rl(n,0);
        for(int i=n-2;i>=0;i--)
        {
            if(close[i+1]==i)
            rl[i]=1+rl[i+1];
            else  
            rl[i]=rl[i+1]+abs(nums[i]-nums[i+1]);
        }

        //return ans;
        vector<int>ans;
        for(auto it:queries)
        {
            int start=it[0];
            int end=it[1];

            if(start<=end)
            {   
                int x=lr[end]-lr[start];
                ans.push_back(x);
            }
            else
            {
                int x=rl[end]-rl[start];
                ans.push_back(x);
            }
        }

        return ans;


    }
};