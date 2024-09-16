#include <../inc/libraries.hpp>
#include <../inc/dataStructures.hpp>


using namespace std;

class Solution {
public:


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2);
    ListNode* removeNthFromEnd(ListNode* head, int n);
    int bagOfTokensScore(vector<int>& tokens, int power);
    void popfront(string &pass,int t);
    void popback(string &pass, int t);
    int minimumLength(string s);
    int minimumLength1(string s);
    ListNode* middleNode(ListNode* head);
    string maximumOddBinaryNumber(string s);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    int maxFrequencyElements(vector<int>& nums);
    int getCommon(vector<int>& nums1, vector<int>& nums2);
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
    string customSortString(string order, string s);
    ListNode* removeZeroSumSublists(ListNode* head);
    int pivot_integer(int n);
    int sum(vector<int>nums,int start ,int stop);
    int numSubarraysWithSum(vector<int>& nums, int goal);
    vector<int> productExceptSelf(vector<int>& nums);
    int findMaxLength(vector<int>& nums);
    int leastInterval(vector<char>& tasks, int n);
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2);
    bool isPalindrome(ListNode* head);
    void reorderList(ListNode* head);
    int findDuplicate(vector<int>& nums);
    int numSubarrayProductLessThanK(vector<int>& nums, int k);
    int maxSubarrayLength(vector<int>& nums, int k);
    long long countSubarrays(vector<int>& nums, int k);
    long long countSubarrays(vector<int>& nums, int minK, int maxK);
    bool isAnagram(string s, string t);
    int lengthOfLastWord(string s);
    bool isIsomorphic(string s, string t);
    string makeGood(string s);
    int timeRequiredToBuy(vector<int>& tickets, int k);
    string removeKdigits(string num, int k);
    int dfs(TreeNode* passed, int pathsum);
    int sumNumbers(TreeNode* root);
    int checkneighbour(vector<vector<int>>&grid,int x, int y);
    int islandPerimeter(vector<vector<int>>& grid);
    int tribonacci(int n);
    int minOperations(vector<int>& nums, int k);
    string reversePrefix(string word, char ch);
    int compareVersion1(string& v1, string& v2);
    int compareVersion(string version1, string version2);
    void deleteNode(ListNode* node);
    int numRescueBoats(vector<int>& people, int limit);
    ListNode* removeNodes(ListNode* head);
    ListNode* doubleIt(ListNode* head);
    vector<string> findRelativeRanks(vector<int>& score);
    vector<int> luckyNumbers (vector<vector<int>>& matrix);
    bool containsNearbyDuplicate(vector<int>& nums, int k);
    int countConsistentStrings(string allowed, vector<string>& words);
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries);
    int longestSubarray(vector<int>& nums);
    int findMinDifference(vector<string>& timePoints);


    //!Neet Code Problems
    //!Array & Hashing Section
    bool containsDuplicate(vector<int>& nums);



    //!Math and Geometry Section
    void rotate(vector<vector<int>>& matrix);
    vector<int> spiralOrder(vector<vector<int>>& matrix);
    void setZeroes(vector<vector<int>>& matrix);
    int sum_squared_digits(int input);
    bool isHappy(int n);
    vector<int> plusOne(vector<int>& digits);
    double myPowmine(double x, long n);
    double myPow(double x, int n);
    string multiply(string num1, string num2);



    //!Bit Manipulation Section
    int singleNumber(vector<int>& nums);
    int hammingWeight(int n);
    vector<int> countBits(int n);
    uint32_t reverseBits(uint32_t n);
    int missingNumber1(vector<int>& nums);
    int missingNumber(vector<int>& nums);
    int getSum(int a, int b);
    int reverse(int x);


};

TreeNode* constructTree(const std::vector<int>& arr);
ListNode* arrayToLinkedList(vector<int>arr);

