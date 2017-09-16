#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getMatchingClosingChar(string& sentence, unsigned int openingIndex, char openingChar, char closingChar) {
    
    stack<int> openIndexStack;

    for (unsigned int i = 0; i < sentence.length(); i++) {
        
        if (sentence[i] == openingChar) {
            openIndexStack.push(i);
        } else if (sentence[i] == closingChar) {

            if (openIndexStack.empty()) return -1;
            openIndexStack.pop();
            if (openIndexStack.empty()) return i + 1;     //  Position not index

        }

    }
    return -1;
}

int getClosingParen(string sentence, unsigned int openingIndex) {
    if (sentence[openingIndex] != '(') return -1;
    return getMatchingClosingChar(sentence, openingIndex, '(', ')');
}

int main()
{
    string str = "Sometimes (when I nest them (my perentheticals) too much (like this(and this)))";
    string badStr = "Somet)imes (when I nest them (my perentheticals) too much (like this(and this)))";

    cout << getClosingParen(str, 11) << endl;   //  No seg fault (return -1 if error)
    cout << getClosingParen(str,9) << endl;    //  If char at index is not '(' then return -1 error
    cout << getClosingParen(str, 10) << endl;

}