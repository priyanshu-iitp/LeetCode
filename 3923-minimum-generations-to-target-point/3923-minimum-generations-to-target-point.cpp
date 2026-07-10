class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        map< pair<int,pair<int,int>>,int >m;
        int gen=0;
        int n=points.size();

        for(auto it:points)
        {
            m[ {it[0],{it[1],it[2]}}]=1;
        }

        if(m.count({target[0],{target[1],target[2]}})) return gen;
        else if(n==1) return -1;

        while( !m.count({target[0],{target[1],target[2]}}))
        {
            gen++;
            n=points.size();

            bool newaddedpoints=false;
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int first=(points[i][0]+points[j][0])/2;
                    int sec=(points[i][1]+points[j][1])/2;
                    int third=(points[i][2]+points[j][2])/2;

                    if( ! m.count({first,{sec,third}}))
                    {
                        points.push_back({first,sec,third});
                        newaddedpoints=true;
                    }

                    m[{first,{sec,third}}]=1;
                }
            }

            if(newaddedpoints==false)
            return -1;
        }

        return gen;


        
    }
};