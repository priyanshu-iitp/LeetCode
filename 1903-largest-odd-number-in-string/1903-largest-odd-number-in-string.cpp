class Solution {
public:
    string largestOddNumber(string nums) {

        int n=nums.size()-1;
        int idx=-1;
        for(int i=n;i>=0;i--)
        {
            if((nums[i]-'0')%2==1)
            {
                idx=i;
                break;
            }
        }

        return idx==-1?"":nums.substr(0,idx+1);
        
    }
};