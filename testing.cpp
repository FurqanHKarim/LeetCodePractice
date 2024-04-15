#include <stack>
#include <string.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* constructTree(const std::vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[0]);
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    int i = 1;
    while (!nodeQueue.empty() && i < arr.size()) {
        TreeNode* currNode = nodeQueue.front();
        nodeQueue.pop();

        if (arr[i] != INT_MIN) {
            currNode->left = new TreeNode(arr[i]);
            nodeQueue.push(currNode->left);
        }
        i++;

        if (i < arr.size() && arr[i] != INT_MIN) {
            currNode->right = new TreeNode(arr[i]);
            nodeQueue.push(currNode->right);
        }
        i++;
    }

    return root;
}

ListNode* arrayToLinkedList(vector<int>arr) {
  // Create a dummy node to simplify head handling
  ListNode dummy(0);
  ListNode* curr = &dummy;

  // Iterate through the array and create nodes
  for (int i = 0; i < arr.size(); ++i) {
    curr->next = new ListNode(arr[i]);
    curr = curr->next;
  }

  // Return the actual list (skip the dummy node)
  return dummy.next;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* Head;
        ListNode* temp;
        if(list1->val < list2->val)
        {
            Head = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            Head = new ListNode(list2->val);
            list2 = list2->next;
        }
        temp = Head;

        while (list1 || list2)
        {
            if(list2 == nullptr)
            {
                temp->next = list1;
                return Head;
            }

            if(list1 == nullptr)
            {
                temp->next = list2;
                return Head;
            }

            if(list1->val < list2->val)
            {
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
                temp = temp->next;
            }
        }
        
        return Head;
    }
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* temp;
        if(list1->val<list2->val)
        {
            head = list1;
        }
        else
        {
            head = list2;
            temp = list1;
            list1 = list2;
            list2 = temp;
            
        } 
        
        while(list1 && list2)
        {
            if(list1->next->val < list2->val)
            {
                list1 = list1->next;
            }
            else
            {
                temp = list1->next;
                list1->next = list2;


            }
        }

        return list1;
    }
    /*
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* del;
        int a = 0;
        while(temp)
        {
            temp = temp->next;
            a++;
        }
        if(head->next == nullptr)
            return nullptr;
        temp = head;
        for (int i = 0; (i < a-1) ; i++)
        {
            temp = temp->next;
            if(!temp->next)
                temp->next = head;
        }
        del = temp->next;
        // if(!temp->next->next)
        //  delete temp->next;
        // if(temp->next->next == nullptr)
        // {
        //     temp->next = nullptr;
        //     return head;
        // }
        
        temp->next->next = temp->next->next->next;
        // delete del;
        return head;
    }*/
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* del;
        if(!head->next)
            return nullptr;

        int a = 0;
        while(temp)
        {
            temp = temp->next;
            a++;
        }
        temp = head;
        for (int i = 0; i < (a-n-1); i++)
        {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;
        
    }
    int reverse(int x) {
        long long y = 0;
        while(x)
        {
            y *=10;
            y += x%10;
            x = x/10;
        }
        if(y>INT_MAX||y<INT_MIN)
            return 0;
        return y;
        
    }

    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int score = 0;
        int Max_score;
        int left = 0;
        int right = tokens.size();
        while(left<=right)
        {
            if(power>=tokens[left]){
                power -= tokens[left++];
                score++; 
                
            } else if(score>0 && power<tokens[left]){
                score--;
                power +=tokens[right--];
            }else
                break;

        }
        return score;


    }

    void popfront(string &pass,int till)
    {
        while(till--){
            for (size_t i = 0; i < pass.size()-1; i++)
            {
                pass[i] = pass[i+1];
            }
            pass.pop_back();
        }
    }
    void popback(string &pass, int till)
    {
        int temp = pass.size()-till-1;
        while(temp--)
            pass.pop_back();

    }
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right && s[left] == s[right]) {
            char ch = s[left];
            while (left <= right && s[left] == ch) {
                left++;
            }
            while (right >= left && s[right] == ch) {
                right--;
            }
        }

        return right - left + 1;
    }
    int minimumLength1(string s) {
        while(1)
        {
            int prefix_int = 0;
            int suffix_int = s.size()-1;
            char prefix = s[0];
            char suffix = s[s.size()-1];

            while(prefix == s[prefix_int])
                prefix_int++;
            if(prefix_int == s.size())
                return 0;

            while(suffix == s[suffix_int])
                suffix_int--;

            if(prefix_int != suffix_int && (s.size()-prefix_int)-(s.size()-1-suffix_int))
            {
                popback(s,suffix_int);
                popfront(s,prefix_int);
            }
            else    
                return s.size();
                

        }    
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* fastboi = head;
        ListNode* slowboi = head;
        bool even = false;


        while((fastboi != nullptr)&&(fastboi->next != nullptr))   
        {
            even = !even;
            fastboi = fastboi->next->next;
            slowboi = slowboi->next;
        }
        if(even)
            return slowboi->next;
        else
            return slowboi;
    }
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i]=='1'){
                swap(s[i],s[s.size()-1]);
                return s;
            }
        }
        return s;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums2.size()+nums1.size();
        vector<double> boi;
        int n1 = 0;
        int n2 = 0;
        for (size_t i = 0; i < total; i++)
        {
            boi.push_back(nums1[n1]>nums2[n2]?nums1[n1]:nums2[n2]);
            n1++;n2++;
        }
        if(total%2)
            return boi[(total/2)+1];
        else
            return (boi[total/2]+boi[(total/2)+1])/2;
        
    }

    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> count;
        int max = 0;
        int iter = nums.size();
        for (size_t i = 0; i < iter; i++)
        {
            count[nums[i]]++;

            if(max < count[nums[i]])
                max = count[nums[i]];
        }
        int returnmax = 0;
        for (auto i = count.begin(); i != count.end(); i++)
        {
            if(max == i->second)
                returnmax += max;
        }
        

        return returnmax;
           
        
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // map<int,int> histogram;
        // int sizenums = nums1.size();
        // for (size_t i = 0; i < sizenums; i++)
        // {
        //     histogram[nums1[i]]++;
        // }
        
        // int sizenums = nums2.size();
        // for (size_t i = 0; i < sizenums; i++)
        // {
        //     histogram[nums2[i]]++;
        // }
        // int smallest = INT_MIN;

        // for (auto i = histogram.begin(); i != histogram.end(); i++)
        // {
        //     if(i->first<smallest && i->second >1)
        //         smallest = i->first;
        // }
        
        // if(smallest == INT_MIN)
        //     return -1;
        // else
        //     return

        vector<int>::iterator first = nums1.begin(),second = nums2.begin();
        while (first != nums1.end() && second != nums2.end())
        {
            if(*first<*second )
                first++;
            else if(*first>*second )
                second++;
    
            if(*first == *second)
                return *first;
        }
        return -1;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int j = 0; j < nums2.size(); j++)
        {
            if(find(nums1.begin(),nums1.end(),nums2[j])!=nums1.end())
                if(find(result.begin(),result.end(),nums2[j]) == result.end())
                    result.push_back(nums2[j]);
                    
        }
        return result;
    }


    string customSortString(string order, string s) {
        map<char,int> histo = {};
        for (size_t i = 0; i < s.size(); i++)
        {
            histo[s[i]]++;
        }
        string result = {};

        for (size_t i = 0; i < order.size(); i++)
        {
            while(histo[order[i]]--)
            {
                result += order[i];
            }
        }

        for (auto i = histo.begin() ; i != histo.end(); i++)
        {
            while(i->second-- > 0)
            {
                result += i->first;

            }
        }
        return result;
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* aiween = new ListNode(0);
        aiween->next = head;
        int sum = 0;
        unordered_map<int,ListNode*> currentsum;
        currentsum[0] = aiween;
        ListNode* current = head;

        while(current){
            sum += current->val;
            if(currentsum.find(sum) != currentsum.end())
            {
                ListNode* todelete = currentsum[sum]->next;
                int temp_sum = sum + todelete->val;
                while(todelete != current){
                    currentsum.erase(temp_sum);
                    todelete = todelete->next;
                    temp_sum += todelete->val;
                }
                currentsum[sum]->next = current->next;
            } else {
                currentsum[sum] = current;
            }
            current = current->next;
            
        }

        
        return aiween->next;

    }

    int pivot_integer(int n){

        unordered_map<int, int> map1;
        int sum = 0;
        for (size_t i = 1; i <= n; i++)
        {
            sum += i;
            map1[sum] = i;
        }
        int reversesum = 0;
        for (size_t i = n; i > 1; i--)
        {
            reversesum += i ;
            if(map1[reversesum] > 1 && i!=n)
                return i-1;
        }
        return -1;
    }
    int sum(vector<int>nums,int start ,int stop){
        int sums = 0;
        for (size_t i = start; i <= stop; i++)
        {
            sums += nums[i];
        }
        return sums;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end()) {
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }

        return total_subarrays;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1),suffix(n,1);

        for (size_t i = 1; i < n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
            suffix[n-1-i] = suffix[n-i] *nums[n-i];

        }
       
        vector<int> answer(n);
        for (size_t i = 0; i < n; i++)
        {
            answer[i] = prefix[i] *suffix[i];
        }
        return answer;
    }
    int findMaxLength(vector<int>& nums) {
        int control = 0,maxcount = 0;
        unordered_map<int,int> sumsagain;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i])
                control++;
            else    
                control--;
            
            if(!control)
                maxcount = i+1;
            else if(sumsagain.find(control) != sumsagain.end())
                maxcount = maxcount>(i-sumsagain[control])?maxcount:(i-sumsagain[control]);
            else
                sumsagain[control] = i;
        }
        return maxcount;
    }

    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     vector<int> boi;
    //     for (size_t i = 0; i < intervals.size(); i++)
    //         for (size_t j = 0; j < 2; j++)
    //             boi.push_back(intervals[i][j]);
        
    //     int temp1 = 0,temp2 = 0;
    //     bool in_interval = false;
    //     for (size_t i = 0; i < boi.size(); i++)
    //     {
    //         temp1 = boi[i];
    //         in_interval = true;
    //         if(boi[i+1]<newInterval[0])
    //         {
    //             in_interval = false;
    //             i++;
    //             continue;
    //         }else if (boi[i+1]>newInterval[1])
    //         {
    //             break;
    //         }
    //         else if()
    //         while(in_interval != false)
    //         {

    //         }
    //     }
        
    // }
            
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    //     vector<vector<int>> result;
    //     int i = 0;
    //     while(i<intervals.size() && intervals[i][1] <newInterval[0])
    //     {
    //         result.push_back(intervals[i]);
    //         i++;
    //     }

    //     while(i<intervals.size() && intervals[i][0]<=newInterval[1])
    //     {
    //         newInterval = {min(newInterval[0],intervals[i][0]),max(intervals[i][1],newInterval[1])};
    //         i++;
    //     }
    //     result.push_back(newInterval);
    //     while(i<intervals.size()){
    //         result.push_back(intervals[i]);
    //         i++;
    //     }

    //     return result;
            
    // }

    int leastInterval(vector<char>& tasks, int n) {
        int frequency[26] = {};
        for(char task: tasks)
            frequency[task - 'A']++;
        
        sort(begin(frequency),end(frequency));
        int chunk = frequency[25]-1,ideal = chunk *n;

        for (int i = 24; i >= 0; i--)
        {
            ideal -=min(chunk,frequency[i]);
        }
        

    return ideal<0?tasks.size():tasks.size()+ideal;
    }

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *Temp = list1,*start,*stop;
        for (size_t i = 0; i < a -1; i++)
            Temp = Temp->next;
        
        start = Temp;
        Temp = Temp->next;
        for (size_t i = a; i < b; i++)
            Temp = Temp->next;

        stop = Temp->next;
        start->next = list2;
        Temp = list2;
        while(Temp->next != NULL){
            Temp = Temp->next;
        }
        Temp->next = stop;
        return list1;
    }


    bool isPalindrome(ListNode* head) {
        vector<int> boi;
        while(head)
        {
            boi.push_back(head->val);
            head = head->next;
        }
        vector<int>::iterator forward = boi.begin();
        vector<int>::reverse_iterator backward = boi.rbegin();
        for (size_t i = 0; i < boi.size(); i++)
        {
            if(*forward != *backward)
                return 0;
            forward++;backward++;
        }
        return 1;
        
    }
    void reorderList(ListNode* head) {
        deque<int> stuff;
        ListNode *temp = head;
        while(temp){
            stuff.emplace_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (!stuff.empty())
        {
            temp->val = stuff.front();
            temp = temp->next;
            stuff.pop_front();
            if(stuff.empty())
                return ;
            temp->val = stuff.back();
            stuff.pop_back();
            temp = temp->next;
            
        }
        
        return;
    }
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]);
            if (nums[index] < 0)
                return index;
            nums[index] = -nums[index];
        }
        return -1; // return -1 if no duplicate found
        
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int left = 0, right = 0, t = nums.size();
        int product = 1, sub_arrays = 0;
        product = 1;
        while(right < t){
            product *= nums[right];
            while(product>=k)
                product /= nums[left++];
            sub_arrays += right - left +1;
            right++;
        }
            return sub_arrays;

    }

    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0,n = nums.size();
        unordered_map<int,int> checker;
        for(int l = 0, r = 0; r<n;r++){
            checker[nums[r]]++;
                if(checker[nums[r]]>k){
                    while(nums[l]!=nums[r]){
                        checker[nums[l]]--;
                        l++;
                    }
                    checker[nums[l]]--;
                    l++;
                }
                ans = max(ans,r-l+1);
        }
        return ans;

    }
    long long countSubarrays(vector<int>& nums, int k) {
        int maximum = *max_element(nums.begin(),nums.end());
        int end = nums.size(),ans = 0,count=0;
        for(int left =0, right = 0; right<end; right++)
        {
            if(maximum == nums[right])
                count++;
            
            if(count>=k){
                if(nums[left]==count)
                    count--;
                left++;
                ans += end-right;
            }
            
        }   
        return ans;
    }

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int bad_idx = -1, left_idx = -1, right_idx = -1;
        long long end = nums.size();   
        for (long long  i = 0; i < end; i++)
        {
            if(!(minK<= nums[i] && nums[i]<=maxK))
                bad_idx = i;
            
            if(nums[i] == minK)
                left_idx = i;
            if(nums[i] == maxK)
                right_idx = i;
            
            res += max(0,min(left_idx,right_idx)-bad_idx);
        }
        return res;
    }
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> heelo;
        int end = nums.size();
        heelo.reserve(end);
        for (int i = 0; i < end; i++)
        {
            heelo[nums[i]]++;
            if(heelo[nums[i]]>1)
                return true;
        }
        return false;
        
    }
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())   
            return false;
        int end =s.length();
        unordered_map<char,int> map1,map2;
        for (int i = 0; i < end; i++)
        {
            map1[s[i]]++;
            map2[t[i]]++;
        }
        for (int i = 0; i < end; i++)
        {
            if(map1[s[i]]!=map2[s[i]])
                return false;
        }
        return true;

        //floowing is a better way
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t)return true;
        // return false;    
    }
    int lengthOfLastWord(string s) {
        int y = s.length(),count = 0;
        while(s[y] == ' ' || s[y] == '\0') y--;
        while(s[y] != ' '){
            y--;
            count++;
            if(y<0)
                return count;
        }
        return count;
    }

    bool isIsomorphic(string s, string t) {
        vector<int> alpha,beta;
        alpha.resize(27);
        beta.resize(27);
        int end = s.length();
        for (int i = 0; i < end; i++)
        {
            if(alpha[s[i] - 'a'] !=beta[t[i] - 'a'])
                return false;
            alpha[s[i] - 'a']++;
            beta[t[i] - 'a']++;
        }
        sort(alpha.begin(),alpha.end());
        sort(beta.begin(),beta.end());
        for (int i = 0; i < alpha.size(); i++)
            if(!alpha[i]==beta[i])
                return false;
        
        return true;
        
        
    }
    string makeGood(string s) {
        int end =s.length();
        bool capital = false;
        for (int i = 1; i < end; i++)
        {
            if(s[i-1]-s[i] == 32){
                s.erase(i-1,2);
                end-=2;
                i=0;
            }         
        }
        return s;
        
    }
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int end = tickets.size(), time = 0,iter = 0;
        while(tickets[k]!=0){
            if(iter == end)
                iter = 0;
            if(tickets[iter] == 0){
                iter++;
                continue;
            }
            --tickets[iter++];
            time++;
        }
        return time;
    }
    string removeKdigits(string num, int k) {
        while(num[k] == '0')
            k++;
        num = num.substr(k,num.length()-k);
        sort(num.begin(),num.end());
        
        return num;
        
    }
    int dfs(TreeNode* passed, int pathsum){
        if(!passed)
            return 0;
        
        pathsum = pathsum*10 + passed->val;

        if(!passed->left && !passed->right)
            return pathsum;
        
        return dfs(passed->left,pathsum)+dfs(passed->right,pathsum);
    }
    int sumNumbers(TreeNode* root) {
       return dfs(root,0);
    }
};

int main()
{
    
    std::vector<int> arr = {4,9,0,5,1};
    TreeNode* root = constructTree(arr);

    cout<<Solution().sumNumbers(root);


}