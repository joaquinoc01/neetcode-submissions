class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int max_water = 0;
        size_t left = 0;
        size_t right = heights.size() - 1;

        while (left < right)
        {
            // Base x Height
            int area = static_cast<int>(right - left) * (std::min(heights[left], heights[right]));
            max_water = std::max(max_water, area);

            if(heights[left] < heights[right])
                left++;
            else
                right--;
        }
        return max_water;
    }
};
