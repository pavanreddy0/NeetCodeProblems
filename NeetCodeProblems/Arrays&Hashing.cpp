//
//  Arrays&Hashing.cpp
//  NeetCodeProblems
//
//  Created by Pavan Reddy on 7/3/24.
//

#include "Arrays&Hashing.hpp"

/*
 1. Contains Duplicate
 
 Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

  

 Example 1:

 Input: nums = [1,2,3,1]
 Output: true
 Example 2:

 Input: nums = [1,2,3,4]
 Output: false
 Example 3:

 Input: nums = [1,1,1,3,3,4,3,2,4,2]
 Output: true
 */

bool containsDuplicate(vector<int>& A) {
    int len = (int)A.size(), index;
    if(len <= 1) return false;
    unordered_map<int, bool> map;
    for(index = 0; index < len; index++){
        if(map.find(A[index]) != map.end())
            return 1;
        map[A[index]] = 1;
    }
    return false;
        
}


/*
 2. Two Sum
 
 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

 You may assume that each input would have exactly one solution, and you may not use the same element twice.

 You can return the answer in any order.

  

 Example 1:

 Input: nums = [2,7,11,15], target = 9
 Output: [0,1]
 Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 Example 2:

 Input: nums = [3,2,4], target = 6
 Output: [1,2]
 Example 3:

 Input: nums = [3,3], target = 6
 Output: [0,1]

 
 */

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    int n, i;
    unordered_map<int, int> map;
    n = (int)nums.size(); i = 0;
    while(i < n){
        if(map.find(target - nums[i]) != map.end())
        {
            result.push_back(map[target - nums[i]]);
            result.push_back(i);
            i = n;
            continue;
        }
        map[nums[i]] = i;
        i += 1;
        
    }
    return result;
    
}

/*
 3. Valid Anagram
 Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

  

 Example 1:

 Input: s = "anagram", t = "nagaram"
 Output: true
 Example 2:

 Input: s = "rat", t = "car"
 Output: false
  

 Constraints:

 1 <= s.length, t.length <= 5 * 104
 s and t consist of lowercase English letters.
  


 */
bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return 0;
    vector<int> freq(26, 0);
    for(int i = 0; i < (int)s.size(); i++)
        freq[s[i] - 'a'] += 1;
    for(int i = 0; i < (int)t.size(); i++)
        freq[t[i] - 'a'] -= 1;
    for(int i = 0; i < 26; i++) if(freq[i] != 0) return 0;
    return 1;
}
