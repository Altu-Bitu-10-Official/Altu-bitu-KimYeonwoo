#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
    
    string s;
    cin >> s;

    set<string> string;

 
    for (int i = 0; i < s.length(); i++) {
        for (int len = 1; len <= s.length() - i; len++) {
            string.insert(s.substr(i, len));
        }
    }

    cout << string.size() << '\n';
    
    return 0;
    
}