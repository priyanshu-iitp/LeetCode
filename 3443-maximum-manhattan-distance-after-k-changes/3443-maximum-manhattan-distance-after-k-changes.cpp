class Solution {
public:
    int maxDistance(string s, int k) {


        int ans=0;
        int curr=0;
        string t=s;
        int kk=k;

        //ne,
        for(auto it:t)
        {
            if(it=='S' && k>0)
            ans++,k--;
            else if(it=='W' && k>0)
            ans++,k--;
            else if(it=='N' || it=='E')ans++;
            else ans--;


            curr=max(ans,curr);
        }

        ans=0;
        k=kk;
        //nw
        for(auto it:t)
        {
            if(it=='S' && k>0)
            ans++,k--;
            else if(it=='E' && k>0)
            ans++,k--;
            else if(it=='N' || it=='W')ans++;
            else ans--;


            curr=max(ans,curr);
        }

        ans=0;
        k=kk;
        //se
        for(auto it:t)
        {
            if(it=='N' && k>0)
            ans++,k--;
            else if(it=='W' && k>0)
            ans++,k--;
            else if(it=='S' || it=='E')ans++;
            else ans--;


            curr=max(ans,curr);
        }

        ans=0;
        k=kk;
        //sw
        for(auto it:t)
        {
            if(it=='N' && k>0)
            ans++,k--;
            else if(it=='E' && k>0)
            ans++,k--;
            else if(it=='S' || it=='W')ans++;
            else ans--;


            curr=max(ans,curr);
        }

        return curr;
        
        
    }
};