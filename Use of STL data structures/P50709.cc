/* Creator: Aina Gomez.
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    
    priority_queue<int> cua;
    char operacio;
    int x;
    
    while (cin >> operacio) {
        
        if (operacio == 'S') {
            cin >> x;
            cua.push(x);
        }
        else if (operacio == 'A') {
            
            if (cua.empty()) cout << "error!" << endl;
            else cout << cua.top() << endl;
        }
        else if (operacio == 'R') {
            
            if (cua.empty()) cout << "error!" << endl;
            else cua.pop();
        }
        else if (operacio == 'I') {
            
            cin >> x;
            
            if (cua.empty()) cout << "error!" << endl;
            else {
                x += cua.top();
                cua.pop();
                cua.push(x);
            }
        }
        else {
            
            cin >> x;
            if (cua.empty()) cout << "error!" << endl;
            else {
                x = cua.top() - x;
                cua.pop();
                cua.push(x);
            }
        }
    }
}
