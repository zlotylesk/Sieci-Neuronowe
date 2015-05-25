#include "faktoryzacja.h"

void introSNE09() {
    cout << "Wybrales zadanie nr 3." << endl;
    cout << "----------------------" << endl;
    cout << "Faktoryzacja" << endl;
};


long NWD(long a, long b) {
    if (a % b == 0) {
        return b;
    } else {
        return NWD(b, a % b);
    }
}

long potega(long a, long b) {
    long output = 1;
    for (long i = 0; i < b; i++) {
        output = output * a;
    }
    return output;
}

long solveDL(long a, long n) {
    long r = 1;

    while (potega(a, r) % n != 1 && r < 10) {
        r++;
    }
    if (r == 10) {
        return -1;
    } else {
        return r;
    }
}

void factorize(long n) {

    srand(time(NULL));
    long randomed = rand() % n;
    //printf("%d\n", randomed);

//	printf("%d --- %d\n", n, randomed);
    if (NWD(n, randomed) > 1) {
        printf("%d --- %d\n", n, NWD(n, randomed));
    } else {
        long r = solveDL(randomed, n);
        printf("%d\n", r);
        if (r == -1) {
            factorize(n);
        } else if (r % 2 == 0) {
            if (NWD(n, potega(randomed, r / 2) + 1) > 1) {
                printf("%d --- %d\n", n, potega(randomed, r / 2) + 1);
            } else if (NWD(n, potega(randomed, r / 2) - 1) > 1) {
                printf("%d --- %d\n", n, potega(randomed, r / 2) - 1);
            } else {
                factorize(n);
            }
        } else {
            factorize(n);
        }
    }

}

int SNE09() {
    introSNE09();
    //	factorize(12);
    //	factorize(91);
    //	factorize(143);
    //	factorize(1737);
    factorize(1859);
    return 0;
};
