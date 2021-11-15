/* Creator: Aina Gomez
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    
    map<string,int> m;
    
    string nom, op;
    int punts;
    
    map<string,int>::const_iterator it = m.begin();
    
    while (cin >> nom >> op) {
        
        if (op == "enters") {
//             pair<iterator,bool> b = m.insert({nom,0});
            if (not m.insert({nom,0}).second) cout << nom << " is already in the casino" << endl;
        } else if (op == "wins") {
            
            cin >> punts;
            if (m.find(nom) != m.end()) m[nom] += punts;
            else cout << nom << " is not in the casino" << endl;
        }
        else {
            it = m.find(nom);
            if (it != m.end()) {
                cout << nom << " has won " << it->second << endl;
                m.erase(nom);
            }
            else cout << nom << " is not in the casino" << endl;
        }
    }
    
    cout << "----------" << endl;
    it = m.begin();
    
    while (it != m.end()) {
        cout << it->first << " is winning " << it->second << endl;
        ++it;
    }
}
