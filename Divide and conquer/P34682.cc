#include <iostream>
#include <vector>

using namespace std;

int posicion_fixed_recursive(const vector<int>& v, int a, int esq, int dre) {
    
    if (dre < esq) return -1;
    else {
        
        int mig = (dre + esq)/2;
        
        if (v[mig] + a < mig + 1) return posicion_fixed_recursive(v, a, mig+1, dre);
        else if (v[mig] + a > mig + 1) return posicion_fixed_recursive(v, a, esq, mig-1);
        else if (v[mig] + a == mig + 1) {
            if (mig != 0 and v[mig - 1] + a == mig) return posicion_fixed_recursive(v, a, esq, mig-1);
            else return mig + 1;
        }
        else return -1;
    }
}

int postition_fixed(const vector<int>& v, int a) {
    
    int esq = 0;
    int dre = v.size() - 1;
    int r = posicion_fixed_recursive(v, a, esq, dre);
    return r;
}

int main() {
    
    int n;
    int seq = 1;
    
    while (cin >> n) {
        
        cout << "Sequence #" << seq << endl;
        
        vector<int> S(n);
        for (int i = 0; i < n; ++i) cin >> S[i];
        
        int m;
        cin >> m;
        
        while (m > 0) {

            int a;
            cin >> a;
            
            int pos = postition_fixed(S,a);
            
            if (pos == -1) cout << "no fixed point for " << a << endl;
            else cout << "fixed point for " << a <<  ": " << pos << endl;
            
            --m;
        }
        ++seq;
        cout << endl;
        
    }
}
