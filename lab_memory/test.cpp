#include <iostream>

int main() {
    // Example of use-after-free
    int * arr = new int[100];
    delete [] arr;
    return arr[5]; //NOPE 
}
