/* Creator: Aina Gomez.
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    
    map<string,int> m;
    string op, paraula;
    
    map<string,int>::const_iterator it = m.begin();
    while (cin >> op) {
        
        if (op == "minimum?") {
            if (m.empty()) cout << "indefinite minimum" << endl;
            else {
                it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (op == "maximum?") {
            
            if (m.empty()) cout << "indefinite maximum" << endl;
            else {
                it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (op == "store") {
            
            cin >> paraula;
            
            if (m.find(paraula) == m.end()) m.insert({paraula,1});
            else m[paraula]++;
        }
        else {
            
            cin >> paraula;
            it = m.find(paraula);
            
            if (it != m.end()) {
                if (it->second == 1) m.erase(it);
                else m[paraula]--;
            }
        }
    }
}
