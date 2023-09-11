class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleets = position.size();
        map<int, float > mp;
            
        for(int i=0;i<position.size();i++)
        {
            float time = ((float)target -  position[i]) / speed[i];
            mp[position[i]] = time;
        }
        sort(position.begin(), position.end());
        int i = position.size() - 1;
        while(i > 0)
        {
            float c= mp[position[i]];
            i--;
        while(i >=0 && c >= (float)mp[position[i]])
        {
            fleets--;
            i--;
        }
        
        }
            return fleets;
    }
};