#include <../inc/libraries.hpp>
#include <../inc/classSolution.hpp>
#include <../inc/dataStructures.hpp>



/// 
//! Array & Hashing Section
//! START of Array & Hashing Section
bool Solution:: containsDuplicate(vector<int>& nums) {
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
bool Solution:: isAnagram1(string s, string t) {
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
    
}
vector<int> Solution:: twoSum(vector<int>& nums, int target) {

    unordered_map<int,int> map_of_numbers;
    int end = nums.size();
    map_of_numbers.reserve(end);
    for (size_t i = 0; i < end; i++)
        map_of_numbers[nums[i]] = i;

    vector<int> answer;
    for (size_t i = 0; i < end; i++)
    {
        if(map_of_numbers[target - nums[i]] != 0){
            answer.push_back(i);
            answer.push_back(map_of_numbers[target - nums[i]]);
            return answer;
        }
    }
    
    return answer;
    
}

vector<vector<string>> Solution:: groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> mother_of_maps;
    int end = strs.size();

    for (size_t i = 0; i < end; i++)
    {
        string x = strs[i];
        sort(x.begin(),x.end());
        mother_of_maps[x].push_back(strs[i]);
    }
    
    vector<vector<string>> answer;
    for (auto  x:mother_of_maps)
        answer.push_back(x.second);

    return answer;
}

vector<int> Solution::topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> map_of_numbers;
    int end = nums.size();
    for (size_t i = 0; i < end; i++)
        map_of_numbers[nums[i]]++;
    
    vector<pair<int,int>> collection_of_pairs(map_of_numbers.begin(),map_of_numbers.end());
    
    sort(collection_of_pairs.begin(),collection_of_pairs.end(),[](const pair<int,int>& a, const pair<int,int>& b){
        return a.second>b.second;
    });  

    vector<int> answer;
    for (size_t i = 0; i < k; i++)
        answer.push_back(collection_of_pairs[i].first);
    
    return answer;
        
}

vector<int> Solution:: productExceptSelf1(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n),suffix(n);
    auto multiply = [](int a,int b){ return a*b;};

    suffix[n-1] = 1;//this isnt exactly a suffix product rather shifted by 1
    std::transform(nums.rbegin(),nums.rend()-1,suffix.rbegin(),suffix.rbegin()+1,multiply);
    
    prefix[0] = 1;
    std::transform(nums.begin(),nums.end()-1,prefix.begin(),prefix.begin()+1,multiply);
    
    std::transform(prefix.begin(),prefix.end(),suffix.begin(),nums.begin(),multiply);
    return nums;
        
    //turns out this is not really an efficient approach why beacuse it uses lambdas and transform is essentially a complete
    // iteration over the vector and obviously is time consuming
}

    bool Solution:: checkValid(vector<vector<int>>& matrix) {
        int end = matrix.size();
        vector<set<int>> row_dict(end),column_dict(end);
        set<int> comparison;
        for (size_t i = 1; i <= end; i++)
            comparison.insert(i);
        
        for (size_t i = 0; i < matrix.size(); i++)
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                row_dict[i].insert(matrix[i][j]);
                column_dict[i].insert(matrix[j][i]);
            }
        
        for (size_t i = 0; i < end; i++)
            if(column_dict[i] != comparison || row_dict[i]!=comparison)  
                return false;
        
        return true;

        
    }


    bool Solution:: isValidSudoku(vector<vector<char>>& board) {
        int end = board.size();
        vector<unordered_map<char,int>> row_dict(end),column_dict(end);
        unordered_map<char,int> box_dict;
        
        for (size_t i = 0; i < 9; i+=3)
        for (size_t j = 0; j < 9; j+=3){
            for (size_t row = 0; row < 3; row++)
                for (size_t column = 0; column < 3; column++)
                {
                    //following to check if there is repeatition in row or column
                    
                    if(board[column+j][row+i] != '.'){
                        column_dict[row+i][board[column+j][row+i]]++;
                        if(column_dict[row+i][board[column+j][row+i]]>1) return false;
                    }
                    
                    
                    if(board[row+i][column+j] == '.')  continue;
                    row_dict[row+i][board[row+i][column+j]]++;
                    
                    if(row_dict[row+i][board[row+i][column+j]] >1 ) 
                        return false;

                    //foloowing to check if there is repeatition in a box
                    box_dict[board[row+i][column+j]]++;
                    if(box_dict[board[row+i][column+j]]>1)
                        return false;
                    
                }
            box_dict.clear();
        }
        
        return true;
    
}

int Solution:: longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int end = nums.size(),longer = 0, answer = 0 ;
        if(end == 0)
            return 0;
        
        for (size_t i = 1; i < end; i++)
        {   
            if(nums[i-1]  == nums[i])
                continue;
            if(nums[i-1] +1 == nums[i])
                longer++;
            else
                longer = 0;

            if (answer<longer)
                answer = longer;


        }
        return answer+1;
    }
//! END of Array & Hashing Section


///
//! Two Pointers Section
//! Start of Two Pointers Section
bool Solution:: isPalindrome(string s) {
        string palin,revpalin;
        palin.reserve(s.size());
        revpalin.reserve(s.size());
        for (auto &&i : s)
            if(isalnum(i))
                palin +=tolower(i);        
        revpalin = palin;
        std::reverse(revpalin.begin(),revpalin.end());
        return revpalin == palin;
}

vector<int> Solution:: twoSum2(vector<int>& numbers, int target) {
        int left  = 0, right = numbers.size()-1 ,comparison;
        comparison = numbers[left]+numbers[right];
        while(comparison != target){
            if(comparison < target)
                left++;
            else if(comparison > target)
                right--;
            
            comparison = numbers[left]+numbers[right];
        }
        
        vector<int> a;
        a.push_back(left);
        a.push_back(right);
        return a;
}
vector<vector<int>> Solution:: threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> answer;
    for (size_t i = 0; i < nums.size()-2; i++)
    {
        if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

        int j  = i+1, k = nums.size()-1 ,comparison;
        while(j<k){
            comparison = nums[i] + nums[j] + nums[k];
            if(comparison < 0)
                j++;
            else if(comparison > 0)
                k--;
            else {
                answer.push_back({nums[i],nums[j],nums[k]});
                j++;
                while (nums[j] == nums[j-1] && j<k)
                    j++;
                
            }
            
        }
    }
    return answer;
}

int Solution:: maxArea(vector<int>& height) {
    int l = 0,r = height.size()-1;
    int answer = 0;
    while(l<r){
        int currentAns = (height[l]<height[r]?height[l]:height[r])*(r-l);
        answer = currentAns>answer?currentAns:answer;
        height[l]<height[r]?l++:r--;
    }
    return answer;
}


//! END of Two Pointers Section
///


//! Stack
//! Start of Stack
///
bool Solution:: isValid(string s) {
    stack<char> stuff;
    int end = s.size();
    if(end == 1)
        return false;
    for (size_t i = 0; i < end; i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[' )
            stuff.push(s[i]);
        else {
            if(stuff.empty())
                return false;
            else {

                char test = stuff.top();
                stuff.pop();
                if((s[i] == ')' && test!='(') || (s[i] == '}' && test!='{') || (s[i] == ']' && test!='['))
                    return false;
            }
        }
        
    }

    if(stuff.size())
        return false;
        
    return true;
    
    
}

int Solution:: evalRPN(vector<string>& tokens){
    stack<int> stuff;
    for (auto &&i : tokens)
    {
    
        int first = 0, result = 0;
        switch (*(i.end()-1))
        {
        case '+':
            first = stuff.top();
            stuff.pop();
            result = first + stuff.top();
            stuff.pop();
            stuff.push(result);
            break;
        case '-':
            first = stuff.top();
            stuff.pop();
            result = stuff.top() - first;
            stuff.pop();
            stuff.push(result);
            break;
        case '*':
            first = stuff.top();
            stuff.pop();
            result = first * stuff.top();
            stuff.pop();
            stuff.push(result);
            break;
        case '/':
            first = stuff.top();
            stuff.pop();
            result = stuff.top()/first;
            stuff.pop();
            stuff.push(result);
            break;
        
        default:
            stuff.push(stoi(i));
            break;
        }
    }
    return stuff.top();
}

void backtracker(vector<string>& answer, int left, int right, string current, int n){
    if(current.length() == 2*n){
        answer.push_back(current);
        return;
    }

    if(left<n)
        backtracker(answer,left+1,right,current+'(',n);
    
    if(right<left)
        backtracker(answer,left,right+1,current+')',n);
}
vector<string> Solution:: generateParenthesis(int n) {
    vector<string> answer;

    backtracker(answer,0,0,"",n);
    return answer;
    
}

//! END of Stack

//! Math & Geometery Section
//! Start of Math & Geometery Section

void Solution:: rotate(vector<vector<int>>& matrix) {
    int end = matrix.size();
    for (int i = 0; i < end; i++)
        for (int j = 0; j < i; j++)
            std::swap(matrix[i][j],matrix[j][i]);
    
    for (int i = 0; i < end; i++)
        std::reverse(matrix[i].begin(),matrix[i].end());
    
}

vector<int> Solution:: spiralOrder(vector<vector<int>>& matrix) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> result;
    result.reserve(matrix[0].size()*matrix.size());
    int left = 0, right = matrix[0].size();
    int top = 0, bottom = matrix.size();
    while(left<right & top<bottom){
        for(int i = left; i<right; i++)
            result.push_back(matrix[top][i]);
        top++;
        
        for(int i = top; i<bottom; i++)
            result.push_back(matrix[i][right-1]);
        right--;

        if(!(left<right & top<bottom))
            break;
        
        for(int i = right-1; i>=left; i--)
            result.push_back(matrix[bottom-1][i]);
        bottom--;

        for(int i = bottom-1; i>=top; i--)
            result.push_back(matrix[i][left]);
        left++;
    }
    return result;

}

void Solution:: setZeroes(vector<vector<int>>& matrix) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>rows,columns;
    int endrow = matrix.size(), endcolumn = matrix[0].size();
    rows.reserve(endrow);columns.reserve(endcolumn);
    
    for(int i = 0; i<endrow; i++)
        for(int j = 0; j<endcolumn; j++)
            if(matrix[i][j] == 0){
                rows.push_back(i);columns.push_back(j);
            }
    int end = rows.size();

    for(int a =0; a<end; a++){
        for(int i = 0; i<endrow; i++)
            matrix[i][columns[a]] = 0;

        for(int j = 0; j<endcolumn; j++)
            matrix[rows[a]][j] = 0;
    }

}

int Solution:: sum_squared_digits(int input){
    int result = 0;
    while(input !=0){
        result += (input%10)*(input%10);
        input /=10;
    }
    return result;
}

bool Solution:: isHappy(int n) {
    
    int slow = n, fast = n;
    while(fast != 1)
    {
        slow = sum_squared_digits(slow);
        fast = sum_squared_digits(sum_squared_digits(fast));
        if(slow == fast & slow!=1)
            return false;
    }
    
    return true;
}

vector<int> Solution:: plusOne(vector<int>& digits) {

    vector<int>::iterator last = digits.end();
    last--;
    (*last) = *last+1;
    while((*last)/10)
    {
        *last %= 10;
        if(last == digits.begin())
        {
            digits.insert(digits.begin(),1);
            return digits;
        }
        last--;
        (*last)++;
        
    }
    return digits;
}

double Solution:: myPowmine(double x, long n) {
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    if(n == 0) return 1;
    if(n == 1 || x == 1) return x;
    cout<<x<<"\t"<<n<<endl;
    if(n/abs(n) == -1)
        return myPow(1/x,(-1)*n);
    
    double temp = x;
    if(n&1)
    {
        x = myPow(x*x,(n&1) ? ((n-1)/2):n/2);
        x *= temp;
    }
    else
    {
        x = myPow(x*x,n/2); 
    }
    
    return x;
}

double Solution:: myPow(double x, int n) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long y = n;
    if(y<0)
        y = -y;
    double ans = 1;
    while(y)
    {
        if(y&1)
            ans = ans*x;

        x *= x;
        y >>=1;
    }
    return ans;
}

string Solution:: multiply(string num1, string num2) {
    int number1 = 0, number2 = 0;
    for (int i = 0; i < num1.size(); i++)
    {
        number1 *= 10;
        number1 += num1[i] - '0';
    }
    for (int i = 0; i < num2.size(); i++)
    {
        number2 *= 10;
        number2 += num2[i] - '0';
    }

    number1 *= number2;
    string answer;
    while(number1){
        answer.insert(answer.begin(),((number1%10) + '0'));
        number1/=10;
    }

    return answer;
    
}


//! END of Math & Geometery Section


/// 
//! Bit Manipulation Section
//! START of Bit Manipulation Section
int Solution:: singleNumber(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int okay = 0;
    for(int i = 0,a=nums.size();i<a; i++)
        okay = okay^nums[i];
    return okay;
}

int Solution:: hammingWeight(int n) {
    int sum = 0;
    for(int i=0,a = 8*sizeof(n);i<a;i++)
        if(n&(1<<i))
            sum++;
    return sum;
}

vector<int> Solution:: countBits(int n) {
    std:: vector<int> ans(n + 1, 0);
    cout<<"i \t\ti>>1\t\tans[i>>1]\t\t(i&1)"<<endl;
    for(int i = 1; i <= n; i++){
        ans[i] = ans[i >> 1] + (i & 1);
    cout<<i<<"\t\t"<<(i>>1)<<"\t\t"<<ans[i>>1]<<"\t\t"<<(i&1)<<endl;
    }
    return ans;
}

uint32_t Solution:: reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for(int i = 32; i>=0 ; i--)
        ans |=  ((n>>i)&1)<<(31-i);
    return ans;
}

int Solution:: missingNumber1(vector<int>& nums) {
    int ans = nums.size();
    for(int i = 0,end = nums.size(); i < end; i++)
        ans ^= i ^ nums[i];


    return ans;

}

int Solution:: missingNumber(vector<int>& nums) {
    int sum = (nums.size()*(nums.size()+1))/2,sum_calc =0;

    for(int i = 0,end = nums.size(); i < end; i++)
        sum_calc += nums[i];

    return sum - sum_calc;
}

int Solution:: getSum(int a, int b) {
    int sum = 0, carry = 0;

    while(b){
        sum |= (a^b);
        carry = (a&b)<<1;
        a = sum;
        b = carry; 
    }

    return a;
}

int Solution:: reverse(int x) {
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
//! END of Bit Manipulation Section