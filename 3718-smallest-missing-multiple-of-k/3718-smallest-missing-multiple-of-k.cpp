class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

       unordered_map<int,int>m;
       for(auto it:nums)
       {
            m[it]++;
       } 

       for(int j=k;j<=100+k;j=j+k)
       {
            if(m.count(j)) continue;
            else
            return j;
       }
       return 0;
        
    }
};