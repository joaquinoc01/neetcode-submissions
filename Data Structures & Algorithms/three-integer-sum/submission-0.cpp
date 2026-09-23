class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // Sort the vector in ascending order
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> solution;

        for (size_t i = 0; i + 2 < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) // avoid duplicates
                continue;

            unsigned int left = i + 1;
            unsigned int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0) // is a solution
                {
                    solution.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                    right--;
            }
        }
        return solution;
    }
};
