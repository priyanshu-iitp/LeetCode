class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int first=INT_MIN;
        int sec=INT_MIN;
        for(auto it:nums)
        {
            if(it>first)
            {
                sec=first;
                first=it;
            }
            else if(it>sec) sec=it;
        }


        return (first-1)*(sec-1);
        
    }
};