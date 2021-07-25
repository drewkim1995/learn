// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution
{
	public:
		vector<int> searchRange(vector<int>& nums, int target)
		{
			int lowerBound = -1;
			int upperBound = -1;
			int left = 0;
			int right = nums.size();

			// Find first instance of target (lower bound?)
			while (left < right)
			{
				int mid = (left + right) / 2;
				if (nums[mid] >= target)	// Greater than Equal
					right = mid;
				else
					left = mid+1;
			}
			lowerBound = left;
			right = nums.size();

			// Find the last instance of target
			while (left < right)
			{
				int mid = (left + right) / 2;
				if (nums[mid] > target)		// Greater than
					right = mid;
				else
					left = mid+1;
			}
			upperBound = left;

			if (lowerBound == upperBound)
				return {-1, -1};
			else
				return {lowerBound, upperBound-1};	// Minus One
		}
};