#include <iostream>
#include <vector>

// Hàm tìm tổng lớn nhất của một dãy số sử dụng chia để trị
int maxSubArraySum(std::vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }

    int mid = (left + right) / 2;

    // Tìm tổng lớn nhất trên dãy con bên trái
    int maxLeft = maxSubArraySum(nums, left, mid);

    // Tìm tổng lớn nhất trên dãy con bên phải
    int maxRight = maxSubArraySum(nums, mid + 1, right);

    // Tìm tổng lớn nhất chứa phần tử ở vị trí mid
    int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
    for (int i = mid; i >= left; --i) {
        sum += nums[i];
        leftSum = std::max(leftSum, sum);
    }
    sum = 0;
    for (int i = mid + 1; i <= right; ++i) {
        sum += nums[i];
        rightSum = std::max(rightSum, sum);
    }

    // Tổng lớn nhất có thể là tổng lớn nhất trên dãy con bên trái,
    // tổng lớn nhất trên dãy con bên phải hoặc tổng lớn nhất chứa phần tử ở vị trí mid
    return std::max(std::max(maxLeft, maxRight), leftSum + rightSum);
}

int main() {
    std::vector<int> nums = {4, -1, 3, -4,2,4};
    int n = nums.size();

    int result = maxSubArraySum(nums, 0, n - 1);
    std::cout << "Tong lon nhat cua day so la: " << result << std::endl;

    return 0;
}
