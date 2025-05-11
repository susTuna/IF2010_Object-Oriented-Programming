#include "Kompleks.hpp"

int main(){
    Kompleks k(1,0);
    Kompleks k2(1,1);
    Kompleks k3(1,-1);

    Kompleks k4 = k2 * k3;

    cout << k << endl;
    cout << k2 << endl;
    cout << k4 << endl;
    return 0;
}