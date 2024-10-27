#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char* ReplacePatternWithAsterisks(char* str, bool& foundPattern) {
    int len = strlen(str);
    foundPattern = false;

    for (int i = 1; i < len - 1; i++) {
       
        if (str[i - 1] == 'n' && str[i + 1] == 'o' && isalpha(str[i])) {
            str[i - 1] = '*';  
            str[i] = '*';      
            foundPattern = true;

            
            for (int j = i + 1; j < len; j++) {
                str[j - 1] = str[j + 1];
            }

           
            len -= 1;
        }
    }

    return str;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    bool foundPattern;
    ReplacePatternWithAsterisks(str, foundPattern);

    if (foundPattern) {
        cout << "letter between n and o: yes" << endl;
    }
    else {
        cout << "letter between n and o: no" << endl;
    }

    cout << "Modified string: " << str << endl;

    return 0;
}
