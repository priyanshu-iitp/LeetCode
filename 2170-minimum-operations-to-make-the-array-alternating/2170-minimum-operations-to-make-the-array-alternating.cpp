class Solution {
public:
    void find(vector<int>&temp,int&a,int&b)
    {
        int first=0;
        int sec=0;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]>first)
            {
                sec=first;
                first=temp[i];
                b=a;
                a=i;
            }
            else if(temp[i]>sec)
            {
                sec=temp[i];
                b=i;
            }
        }
    }
    int minimumOperations(vector<int>& nums) {

        int n=nums.size();
        if(n==1) return 0;

        vector<int>odd(100001,0);
        vector<int>even(100001,0);

        for(int i=0;i<n;i++)
        {
            if(i%2) odd[nums[i]]++;
            else even[nums[i]]++;
        }

        vector<pair<int,int>>e(2);
        int a=0;
        int b=0;
        find(even,a,b);

        e[0]={a,even[a]};
        e[1]={b,even[b]};


        vector<pair<int,int>>o(2);
        a=0,b=0;
        find(odd,a,b);
        o[0]={a,odd[a]};
        o[1]={b,odd[b]};


        int k=0;
        if(e[0].first!=o[0].first) k=e[0].second+o[0].second;
        else 
        {
            k=max(o[1].second+e[0].second,o[0].second+e[1].second);
        }


        return n-k;




         
        
    }
};