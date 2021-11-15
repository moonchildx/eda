
#include <iostream>
using namespace std;

int calcular_exp_modm(int b, int e, int m) {
    
    if (e == 0) return 1;
    else if (e%2 == 0) {
        int y = calcular_exp_modm(b, e/2, m)%m;
        return (y*y)%m;
    }
    else {
        int y = calcular_exp_modm(b, e/2, m)%m;
        return ((b*y)%m*y)%m;
    }
}

int main() {
    
    int base, exp, mod;
    
    while (cin >>base) {
        cin >> exp >> mod;
    
        int m = calcular_exp_modm(base%mod, exp, mod);
        
        cout << m << endl;
        
    }
    
}
