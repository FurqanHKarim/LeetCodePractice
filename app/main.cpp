#include <../inc/libraries.hpp>
#include <../inc/dataStructures.hpp>
#include <../inc/classSolution.hpp>

using namespace std;

int main()
{

    vector<string> arr = {"00:00","23:59","00:00"};

    cout<<Solution().findMinDifference(arr);
    return 1;

}