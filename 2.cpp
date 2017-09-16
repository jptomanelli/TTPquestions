#include <iostream>
#include <string>

using namespace std;

string stringFormatting(string str, int k) {
    
    if (k <= 0) return str;

    str.erase(remove(str.begin(), str.end(), '-'), str.end());
    reverse(str.begin(), str.end());

    for (int i = k; i < str.length(); i+=k) {
        str.insert(i++, "-");
    }

    reverse(str.begin(),str.end());

    return str;
}

int main()
{
    string str = "2-4a0r7-4k";
    cout << stringFormatting(str, 4) << endl;   //  24a0-r74k
    cout << stringFormatting(str, 3) << endl;   //  24-a0r-74k
    cout << stringFormatting(str, 2) << endl;   //  24-a0-r7-4k
    cout << stringFormatting(str, 1) << endl;   //  2-4-a-0-r-7-4-k
    cout << stringFormatting(str, 0) << endl;   //  2-4a0r7-4k
    cout << stringFormatting(str, -1) << endl;  //  2-4a0r7-4k

}