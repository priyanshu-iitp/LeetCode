class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
      
        unordered_map<string,int>m;

        for(auto it:arr)
        {
           m[it]++;
        }

        for(auto it:arr)
        {
            if(k==1 && m[it]==1)return it;
            if(m[it]==1)k--;

        }
        return "";
        
    }
};