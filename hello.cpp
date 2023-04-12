#include <iostream>
#include <gmpxx.h>

int main() {
    mpz_t a, b;

    mpz_init_set_str(a, "45", 10);
    mpz_init_set_str(b, "12", 10);
    mpz_add(a, a, b);
    
    std::cout << "Hello world: \n";
    std::cout << mpz_get_str(NULL, 10, a);
    return 0;
    }