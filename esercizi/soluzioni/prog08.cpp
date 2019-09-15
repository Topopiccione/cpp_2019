#include <iostream>

struct frazione {
    int num;
    int den;
};

void mcm( const frazione a, const frazione b, frazione & c ) {
    if (a.den == b.den) {
        c.den = a.den;
        return;
    }

    int temp_k;
    if (a.den > b.den)
        temp_k = a.den;
    else
        temp_k = b.den;

    do {
        if ((temp_k % a.den == 0) && (temp_k % b.den == 0)) {
          c.den = temp_k;
        }
          temp_k++;
    }
    while ( ((temp_k - 1) % a.den != 0) || ((temp_k - 1) % b.den != 0) );
}

void convertiNum( const frazione mcm, frazione& in ) {
    in.num = (mcm.den / in.den) * in.num;
}

void calcolaSomma( const frazione a, const frazione b, frazione & c ) {
    c.num = a.num + b.num;
}

int main( void ) {
    frazione a, b, somma;
    a.num = 2;
    a.den = 5;
    b.num = -2;
    b.den = 9;

    mcm( a, b, somma );
    convertiNum( somma, a );
    convertiNum( somma, b );
    calcolaSomma( a, b, somma );

    std::cout << "Frazione somma = " << somma.num << "/" << somma.den << std::endl;

}
