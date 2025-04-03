#include <libraries.hpp>
#include <dataStructures.hpp>
#include <classSolution.hpp>

using namespace std;
// // Function to find the parent of a node in a Min-Max Heap
// int getParentIndex(int i) {
//     if (i == 0) return -1; // Root has no parent
//     return (i - 1) / 2;
// }

// // Function to find the level of a node
// bool getLevel(int i) {
//     return ((int)floor(log2(i + 1))) % 2;
// }

// // Function to check if a node satisfies Min-Max heap conditions with its parent
// bool checkParentCondition(int heap[], int i) {
//     if (i == 0) return true; // Root node is always correct

//     int parentIndex = getParentIndex(i);
//     bool level = getLevel(i);

//     if (level) { // Min level
//         return heap[i] >= heap[parentIndex]; // Parent must be larger
//     } else { // Max level
//         return heap[i] <= heap[parentIndex]; // Parent must be smaller
//     }
// }

// int main() {
//     int min_max_heap[33] = {5,65,80,25,37,8,15,57,36,45,59,20,14,32,18,28,30,34,27,39,38,45,50,15,12,13,10,30,31,16,17}; // Example Min-Max Heap
        
//     int index  = 31;
//     min_max_heap[index] = 100;
//     if (checkParentCondition(min_max_heap, index)) {
//         cout << "Parent-child relationship satisfies Min-Max Heap conditions." << endl;
//     } else {
//         cout << "Parent-child relationship is incorrect!" << endl;
//     }

//     return 0;
// }



#include <iostream>
#include <queue>
using namespace std;

void vectInit(vector<int>&);

void printVector(const vector<int>& vec)
{
    for(const int& i : vec)
        cout << i << '\t';
    cout << endl;
}

void bisection(vector<int>& vec, int val)
{
    auto lowerIt = vec.begin();
    auto upperIt = vec.end() - 1;
    auto midIt = vec.begin();
    

    if(val < *lowerIt)
    {
        vec.insert(lowerIt, val); // for 0
        return;
    }
    else if(val > *upperIt)
    {
        vec.insert(vec.end(), val); // for 45
        return;
    }

    while((upperIt-lowerIt) > 1)
    {
        midIt = lowerIt + (distance(lowerIt, upperIt) / 2);
        upperIt = *midIt>val?midIt-1:upperIt;
        lowerIt = *midIt<val?midIt:lowerIt;
        
        if(val == *midIt)
        {
            vec.insert(midIt, val); // for 12
            return;
        }

    }
    
    vec.insert(lowerIt+1, val); // for 17, 35
    
}

int main()
{
    vector<int> vec1 = {3,7,8,9,11,12,18,27,30,37,40};
    printVector(vec1);
    bisection(vec1, 13);
    printVector(vec1);
    
    
    vec1 = {3,7,8,9,11,12,18,27,30,37,40};
    printVector(vec1);
    bisection(vec1, 28);
    printVector(vec1);

    
    vec1 = {3,7,8,9,11,12,18,27,30,37,40};
    printVector(vec1);
    bisection(vec1, 39);
    printVector(vec1);

    
    vec1 = {3,7,8,9,11,12,18,27,30,37,40};
    printVector(vec1);
    bisection(vec1, 10);
    printVector(vec1);

    

}

void vectInit(vector<int>& binaryTree)
{
    binaryTree.push_back(3);
    binaryTree.push_back(7);
    binaryTree.push_back(8);
    binaryTree.push_back(9);
    binaryTree.push_back(11);
    binaryTree.push_back(12);
    binaryTree.push_back(18);
    binaryTree.push_back(27);
    binaryTree.push_back(30);
    binaryTree.push_back(37);
    binaryTree.push_back(40);
}
/*
!  int main()
{
    vector<int> something = {3,1,2};
    Solution().findMin(something);
        
    return 1;

}*/