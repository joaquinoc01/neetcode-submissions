class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        // Preffix and Suffix Technique
        std::vector<int> preffixVector(nums.size(), 1);
        for (size_t i = 1; i < nums.size(); ++i)
        {
            preffixVector[i] = preffixVector[i - 1] * nums[i - 1];
        }

        std::vector<int> suffixVector(nums.size(), 1);
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            suffixVector[i] = suffixVector[i + 1] * nums[i + 1];
        }

        std::vector<int> solution(nums.size());
        for (size_t i = 0; i < nums.size(); ++i)
        {
            solution[i] = preffixVector[i] * suffixVector[i];
        }
        return solution;
    }
};
