class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        // Two pointers
        unsigned int left = 0;
        unsigned int right = numbers.size() - 1;

        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)
            {
                return std::vector<int>{int(left)+1, int(right)+1};
            }
            else if (numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }
    }
};
