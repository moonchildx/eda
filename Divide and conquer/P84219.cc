#include <iostream>
#include <vector>
using namespace std;

int search_position(int l, int r, double x, const vector<double>& v) {
    
    if (l <= r) {
        int midd = (l + r)/2;
        
        if (v[midd] > x) return search_position(l, --midd, x, v);
        else if (v[midd] < x) return search_position(++midd, r, x, v);
        else if (v[midd] == x and midd != 0 and v[midd - 1] == x) return search_position(l, --midd, x,v);
        else return midd;
    }
    else return -1;
}

int first_occurrence(double x, const vector<double>& v) {
    
    int l = 0;
    int r = v.size() - 1;
    int pos = search_position(l, r, x, v);
    return pos;
}


int main() {
    
    int n;
    cin >> n;
    
    vector<double> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    
    double x;
    cin >> x;
    
    int position = first_occurrence(x, v);
    if (position != -1) cout << "The element " << x << " is in " << position << endl;
    else cout << "Element not found" << endl;
}
