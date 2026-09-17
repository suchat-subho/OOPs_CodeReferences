#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

int main(){
    int x = 10;   // normally may generate unused-variable warning

    std::cout << "Hello\n";

    return 0;
}

#pragma GCC diagnostic pop