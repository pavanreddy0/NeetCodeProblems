//
//  TwoPointers.cpp
//  NeetCodeProblems
//
//  Created by Pavan Reddy on 7/3/24.
//

#include "TwoPointers.hpp"

/*
 1. A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

 Given a string s, return true if it is a palindrome, or false otherwise.

  

 Example 1:

 Input: s = "A man, a plan, a canal: Panama"
 Output: true
 Explanation: "amanaplanacanalpanama" is a palindrome.
 Example 2:

 Input: s = "race a car"
 Output: false
 Explanation: "raceacar" is not a palindrome.
 Example 3:

 Input: s = " "
 Output: true
 Explanation: s is an empty string "" after removing non-alphanumeric characters.
 Since an empty string reads the same forward and backward, it is a palindrome.
  
 
 */

bool is_alpha_numeric(char s){
    if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))
        return 1;
    return 0;
}

char to_lower(char s){
    if(s >= 'A' && s <= 'Z')
        s += 32;
    return s;
}

bool isPalindrome(string s) {
    int len = (int)s.size(), low, high;
    if(len == 0) return 1;
    low = 0; high = len - 1;
    char first, last;
    while(low < high){
        while (low < high && !is_alpha_numeric(s[low])) low += 1;
        while (low < high && !is_alpha_numeric(s[high])) high -= 1;
        first = to_lower(s[low]);
        last = to_lower(s[high]);
        if(first != last) return 0;
        low += 1;
        high -= 1;
        
    }
    return 1;
}


/*
 2. Two Sum II - Input Array Is Sorted
 Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

 Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

 The tests are generated such that there is exactly one solution. You may not use the same element twice.

 Your solution must use only constant extra space.

  

 Example 1:

 Input: numbers = [2,7,11,15], target = 9
 Output: [1,2]
 Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
 Example 2:

 Input: numbers = [2,3,4], target = 6
 Output: [1,3]
 Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
 Example 3:

 Input: numbers = [-1,0], target = -1
 Output: [1,2]
 Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
  
 */

vector<int> twoSum(vector<int>& A, int target) {
    vector<int> ans = {-1, -1};
    int len = (int)A.size(), low, high;
    if(len <= 1) return ans;
    low = 0; high = len - 1;
    while(low < high){
        if(A[low] + A[high] == target){
            ans[0] = low + 1;
            ans[1] = high + 1;
            break;
        }
        else if(A[low] + A[high] < target) low += 1;
        else high -= 1;
    }
    return ans;
}


/*
 3. 3Sum
 Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

 Notice that the solution set must not contain duplicate triplets.

  

 Example 1:

 Input: nums = [-1,0,1,2,-1,-4]
 Output: [[-1,-1,2],[-1,0,1]]
 Explanation:
 nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 The distinct triplets are [-1,0,1] and [-1,-1,2].
 Notice that the order of the output and the order of the triplets does not matter.
 Example 2:

 Input: nums = [0,1,1]
 Output: []
 Explanation: The only possible triplet does not sum up to 0.
 Example 3:

 Input: nums = [0,0,0]
 Output: [[0,0,0]]
 Explanation: The only possible triplet sums up to 0.
  
 */

void findSum(vector<int> &A, vector<vector<int>> &ans, vector<int> &temp, int index, int target){
    int low = index + 1, high = (int)A.size() - 1;
    while(low < high){
        if(A[low] + A[high] == target){
            temp.push_back(A[index]);
            temp.push_back(A[low]);
            temp.push_back(A[high]);
            ans.push_back(temp);
            temp.clear();
            while(low + 1 < high && A[low] == A[low + 1]) low += 1;
            while(high - 1 > low && A[high] == A[high] - 1) high -= 1;
            low += 1;
            high -= 1;
        }
        else if(A[low] + A[high] < target) low += 1;
        else high -= 1;
        
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int i,n = (int)nums.size();
    sort(nums.begin(), nums.end());
    vector<int> temp;
    i = 0;
    while(i < n){
        findSum(nums, ans, temp, i, -1 * nums[i]);
        
        while(i + 1 < n && nums[i] == nums[i + 1])
            i += 1;
        i += 1;
    }
    return ans;
}

/*
 4. Container With Most Water
 You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

 Find two lines that together with the x-axis form a container, such that the container contains the most water.

 Return the maximum amount of water a container can store.

 Notice that you may not slant the container.

 Input: height = [1,8,6,2,5,4,8,3,7]
 Output: 49
 Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 Example 2:

 Input: height = [1,1]
 Output: 1
 */

int maxArea(vector<int>& A) {
    int n = (int)A.size(), left, right;
    if(n <= 1) return 0;
    long long ans = 0, temp;
    left = 0; right = n - 1;
    while(left < right){
        temp = (right - left) * min(A[left], A[right]);
        ans = max(ans, temp);
        if(A[left] <= A[right]) left += 1;
        else right -= 1;
    }
    
    return (int)ans;
}

