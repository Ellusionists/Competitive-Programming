#include <iostream>
using namespace std;

int main() {
    int test; cin >> test;
    int slen, k;
    char c;
    while(test--) {
        string output;
        cin >> slen >> k;
        string s; cin >> s;

        for(int i = 0; i < s.length(); i++) {
            c = s[i];
            int x = c;
            if(c >= 'A' && c <= 'Z') {
                x += k%26;
                while(x > 'Z') 
                    x -= 26;
            }
            if(c >= 'a' && c <= 'z') {
                x += k%26;
                while(x > 122)
                    x -= 26;
            }
            
            if(c >= '0' && c <= '9') {
                x += k%10;
                while(x > '9')
                    x -= 10;
            }
            c = x;
            output.push_back(c);
        }
        cout << output << endl;
    }
}
