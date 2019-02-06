#include <iostream>
#include <map>

using namespace std;

int main() {
    int test; cin >> test;
    while(test--) {
        int total = 0, count = 0, count2 = 0;
        std::map<char, int> nmap;
        string str; cin >> str;
        for(int i = 0; i < str.length(); i++) {
            nmap[str[i]] = nmap[str[i]] + 1;
        }
        map<char, int>::iterator it;
        it = nmap.find('{');
        count = (it->second);
        it = nmap.find('}');
        count2 = (it->second);
        if(count/2 == count2/2)
            total += (count+count2)/2;
        else
            total += (std::min(count, count2));
            
        it = nmap.find('[');
        count = (it->second);
        it = nmap.find(']');
        count2 = (it->second);
        if(count/2 == count2/2)
            total += (count+count2)/2;
        else
            total += (std::min(count, count2));
        
        it = nmap.find('(');
        count = (it->second);
        it = nmap.find(')');
        count2 = (it->second);
        if(count/2 == count2/2)
            total += (count+count2)/2;
        else
            total += (std::min(count, count2));
  
        cout << total*2 << endl;
    }
}
// Write your code here

