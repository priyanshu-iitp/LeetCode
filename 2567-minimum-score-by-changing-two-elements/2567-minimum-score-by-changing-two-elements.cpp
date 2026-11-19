class Solution {
public:
    int minimizeSum(vector<int>& nums) {

    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;

    for (int num : nums) 
    {
    // Find 3 largest elements
        if (num > max1) 
        {
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        else if (num > max2) 
        {
            max3 = max2;
            max2 = num;
        }
        else if (num > max3) 
        {
            max3 = num;
        }

        // Find 3 smallest elements
              
        if (num < min1) 
        {
                  
            min3 = min2;
            min2 = min1;
            min1 = num;

        }
        else if (num < min2) 
        {
            min3 = min2;
            min2 = num;
        }
        else if (num < min3) 
        {
            min3 = num;

        }
    }

    int case1 = max3 - min1;
    int case2 = max2 - min2;
    int case3 = max1 - min3;

    return min({case1, case2, case3});
 
        
    }
};