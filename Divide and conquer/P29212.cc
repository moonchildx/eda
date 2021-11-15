/* Creator: Aina Gomez
*/

#include <iostream>
using namespace std;

// funcio recursiva que calcula b^e mod m
// per obtenir la manera mes eficient, a cada crida calculem el mod de m.
int calcular_exp_modm(int b, int e, int m) {
    
    if (e == 0) return 1;                       // cas base: exponent = 0.
    else if (e%2 == 0) {                        // en cas que l'exponent es parell, podem simplificar l'operacio com b^(e/2) * b^(e/2) (= b^e).
        int y = calcular_exp_modm(b, e/2, m)%m;
        return (y*y)%m;
    }
    else {                                      // en cas que l'exponent es imparell, podem simplificar l'operacio com b^(e/2) * b^(e/2) * b (= b^e).
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
