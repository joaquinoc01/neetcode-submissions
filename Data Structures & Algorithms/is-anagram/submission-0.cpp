#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        std::unordered_map<char, int> sMap;
        std::unordered_map<char, int> tMap;

        for (const char c : s)
        {
            if (sMap.find(c) == sMap.end()) // key not found
                sMap.insert({c, 1});
            else // key found, add 1 to such element
                sMap[c]++;
        }

        for (const char c : t)
        {
            if (tMap.find(c) == tMap.end()) // key not found
                tMap.insert({c, 1});
            else // key found, add 1 to such element
                tMap[c]++;
        }

        if (sMap == tMap)
            return true;
        else
            return false;
    }
};
