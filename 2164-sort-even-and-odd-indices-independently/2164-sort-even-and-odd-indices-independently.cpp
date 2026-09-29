class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {

        vector<int>odd;
        vector<int>even;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }

        sort(odd.rbegin(),odd.rend());
        sort(even.begin(),even.end());

        int j=0;
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {   
                nums[i]=even[j];
                j++;
            }
            else
            {
                nums[i]=odd[k];
                k++;
            }
        }
        return nums;


        
    }
};