class Solution {
public:
    int evalRPN(vector<string>& nums) {

        int n=nums.size();
        stack<int>s;

        for(int i=0;i<n;i++)
        {
            if(nums[i]=="+" || nums[i]=="-" || nums[i]=="*" || nums[i]=="/")
            {
                int a=s.top();s.pop();
                int b=s.top();s.pop();

                if(nums[i]=="+") s.push(b+a);
                else if(nums[i]=="-") s.push(b-a);
                else if(nums[i]=="*") s.push(b*a);
                else s.push(b/a);
            }
            else
            s.push(stoi(nums[i]));
        }

        return s.top();
        
    }
};