#include <../inc/libraries.hpp>
#include <../inc/dataStructures.hpp>
#include <../inc/classSolution.hpp>

using namespace std;

int main()
{

    vector<int> arr1 = {1,10,100},arr2 = {1000};


    vector<int> boi(Solution().longestCommonPrefix(arr1,arr2));

    return 1;

}