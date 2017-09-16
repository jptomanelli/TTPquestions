#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool sumOfTwo (vector<int> &a, vector<int> &b, int v) {

    if (a.empty() || b.empty()) return false;

    set<int> setA(a.begin(), a.end());
    set<int> setB(b.begin(), b.end());

    set<int>::iterator itA;
    set<int>::iterator itB;

    int sum = 0;

    for (itA = setA.begin(); itA != setA.end(); ++itA) {

        for (itB = setB.begin(); itB != setB.end(); ++itB) {
            
            sum = *itA + *itB;
            if (sum == v) return true;
            else if (sum > v) break;
            
        }
    }

    return false;
}


int main()
{
    static const int a1[] = {16, 2, 77, 29, -1, 44, 44};
    static const int a2[] = {6, 76, 7, -54, 11};
    vector<int> v1 (a1, a1 + sizeof(a1) / sizeof(a1[0]) );
    vector<int> v2 (a2, a2 + sizeof(a2) / sizeof(a2[0]) );
    if (sumOfTwo(v1,v2,10)) 
        cout << "TRUE";
    else 
        cout << "FALSE";
}