class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        if(strs.size() < 2)
            return result;
        map<string, vector<string> > anagramMap;
        
        for(int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            if(anagramMap.find(key) != anagramMap.end())
                anagramMap[key].push_back(strs[i]);
            else
            {
                vector<string> value;
                value.push_back(strs[i]);
                anagramMap[key] = value;
            }
        }
        
        for(map<string, vector<string> >::iterator it = anagramMap.begin(); it != anagramMap.end(); it++)
        {
            if(it->second.size() > 1)
            {
                vector<string> temp = it->second;
                for(int i = 0; i < temp.size(); i ++)
                    result.push_back(temp[i]);
            }
        }
        return result;
    }
};
