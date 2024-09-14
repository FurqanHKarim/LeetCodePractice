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
//! END of Array & Hashing Section


///
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