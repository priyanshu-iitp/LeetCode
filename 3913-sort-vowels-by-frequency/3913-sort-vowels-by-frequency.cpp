class Solution {
public:
    string sortVowels(string s) {

        int n=s.size();
        vector< pair<int,pair<int,int>> >vowel(26,{0,{26,0}});

        for(int i=0;i<n;i++)
        {
            if( s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
            {
                int freq=vowel[s[i]-'a'].first+1;
                int idx=vowel[s[i]-'a'].second.first;
                int charc=s[i]-'a';

                if(idx==26)
                idx=i;

                vowel[s[i]-'a']={freq,{idx,charc}};
            }
        }

        sort(vowel.begin(),vowel.end(), [](const pair<int,pair<int,int>>&a, const pair<int,pair<int,int>>&b){
            if(a.first!=b.first) return a.first>b.first;
            return a.second.first<b.second.first;
        });

        int k=0;
        for(int i=0;i<n;i++)
        {
            if( s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
            {
                s[i]=vowel[k].second.second+'a';
                vowel[k].first--;
                if(vowel[k].first==0)
                k++;   
            }
        }

        return s;


        
    }
};