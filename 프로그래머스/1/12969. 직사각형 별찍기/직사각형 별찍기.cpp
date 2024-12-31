#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    string stars(a, '*');
    for (int i = 0; i < b; i++){
        cout << stars << endl;
    }
    
    return 0;
}