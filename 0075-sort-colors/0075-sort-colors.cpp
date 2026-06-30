class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //most optimal solution(dutch national flag algo (dnf));
        
        int l=0,mid=0,r=nums.size()-1;
        while(mid<=r)
        {
            if(nums[mid]==2)
            {
                swap(nums[mid],nums[r]);
                r--;
            }
            else if (nums[mid]==0)
            {
                swap(nums[mid],nums[l]);
                l++;
                mid++;
            }
            else mid++;
        }
        
    }
};