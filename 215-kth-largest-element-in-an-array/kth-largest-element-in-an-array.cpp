class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }
private:
    int quickselect(vector<int>& nums, int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }

        auto pivotIndex = left + (rand() % (right - left + 1));
        auto [firstEqual, firstGreater] = threeWayPartition(nums, left, right, nums[pivotIndex]);
        if (k < firstEqual) {
            return quickselect(nums, left, firstEqual - 1, k);
        }
        if (k >= firstEqual && k < firstGreater) {
            return nums[k];
        }
        return quickselect(nums, firstGreater, right, k);
    }

    pair<int, int> threeWayPartition(vector<int>& nums, int left, int right, int pivot) {
        int i = left, j = left, k = right;
        while (j <= k) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if (nums[j] == pivot) {
                j++;
            } else {
                swap(nums[k], nums[j]);
                k--;
            }
        }
        return {i, j};
    }
};