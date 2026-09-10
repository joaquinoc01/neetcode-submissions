class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::vector<std::vector<int>> bucket (nums.size() + 1);
        std::unordered_map<int, int> frequencies;

        for (const auto& num : nums) // count frequencies
        {
            frequencies[num]++;
        }

        for (const auto& [num, frecuency] : frequencies) // group values by frequency
        {
            bucket[frecuency].push_back(num);
        }

        std::vector<int> solution;

        for (int i = bucket.size() - 1; i >= 0; --i) // get the k highest frequencies
        {
            for (const auto& num : bucket[i])
            {
                if (solution.size() == k)
                    break;

                solution.push_back(num);
            }
        }
        return solution;
    }
};