#include <unordered_map>
#include <list>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        std::unordered_map<std::string, std::vector<std::string>> result;

        for (const auto& str : strs)
        {
            std::string alphabet (26, 0);
            for (const auto& c : str)
            {
                alphabet[c - 'a']++;
            }
            result[alphabet].push_back(str);
        }

        std::vector<std::vector<std::string>> solution;
        for (auto& [key, anagramList] : result)
        {
            solution.push_back(std::vector<std::string>(anagramList.begin(), anagramList.end()));
        }
        return solution;
    }
};
