class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int longest = 0;
        std::unordered_set<int> numsSet(nums.begin(), nums.end());
        for (const auto& num : numsSet)
        {
            if (numsSet.find(num - 1) == numsSet.end()) // We have found the start of a sequence
            {
                int currentStreak = 0;
                int currentNum = num;
                while (numsSet.find(currentNum) != numsSet.end()) // Look for next element greater than 1
                {
                    currentStreak++;
                    currentNum++;
                }
                
                if (currentStreak > longest)
                    longest = currentStreak;
            }
        }
        return longest;
    }
};
