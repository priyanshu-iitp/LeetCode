class Solution {
public:
    bool possible(vector<int>& position, int m,int force)
    {
        int pos=0;
        int x=1;
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-position[pos]>=force)
            {
                x++,pos=i;
            }
            if(x==m) return true;
        }

        return x==m;
    }
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(),position.end());

        int n=position.size();
        int low=1;
        int high=position[n-1]-position[0];

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(position,m,mid)) low=mid+1;
            else high=mid-1;
        }
        return high;
        
    }
};