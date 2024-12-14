#include <mpfr.h>
#include <iostream>
#include <iomanip>
int main() {
    int n;
    std::cin >> n;
    const int prec = n + 1;
    mpfr::mpreal pi = mpfr::const_pi();
    mpfr::mpreal pi_str;
    mpfr::mpreal::set_default_prec(prec * mpfr::digits());
    mpfr::mpreal pi_prec = mpfr::const_pi();
    std::string pi_str = mpfr::get_str(pi_prec, prec, mpfr::mpreal::get_default_rnd());
    std::cout << "π to "<< prec <<" decimal places:\n" << pi_str << std::endl;
    return 0;
}
