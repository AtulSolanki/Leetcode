class Solution
{
    public:
        int solve(vector<int> &nums, int i, int j)
        {
            if (i > j)
            {
                return 0;
            }
            int take_i = nums[i] - solve(nums,i+1,j);
            int take_j = nums[j] - solve(nums, i, j - 1);
            return max(take_i, take_j);
        }
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size(), total = 0;
        for (auto x: nums) total += x;
        int sum = solve(nums, 0, n - 1);
        if (sum >= 0) return true;
        return false;
    }
};