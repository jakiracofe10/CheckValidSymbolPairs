#include <iostream>
#include <stack>

using namespace std;

//Time: O(n)
//Space: O(n)

//Check c and stringChar make a correct pair
bool checkChar(char c, char stringChar) {
    if (stringChar == ')' && c =='(')
        return true;
    if (stringChar == ']' && c =='[')
        return true;
    if (stringChar == '}' && c =='{')
        return true;
    return false;
}

//Logic: every closing char must match last open char in stack for exp to have valid pairs
bool checkSymbolPairs(string s) {
    stack<char> symbols;
    int quoteCount = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            symbols.push(s[i]); //push open char onto stack
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            char c = symbols.top();
            if (checkChar(c,s[i]))
                symbols.pop(); //if correct pair, remove last open from stack
            else
                return false;
        }
        if (s[i] == '"')
            quoteCount++; //quote count must be even to be valid
    }
    if (quoteCount%2 != 0)
        return false;

    return true;
}

int main() {
    string input = "\"[()]{}{[()()]()}\"";
    //string input = "[()]{}{[()()]()}";
    //string input = "[(])";
    bool result = checkSymbolPairs(input);
    string output = result ? "valid" : "not valid";
    cout << "Input: "+input+" is " + output << endl;

};