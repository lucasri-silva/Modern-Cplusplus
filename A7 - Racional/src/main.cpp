#include "racional.hpp"

int main()
{
    Racional r1(3, 4);
    Racional r2(1, 2);

    cout << "r1: " << r1.getNumerador() << "/" << r1.getDenominador() << endl;
    cout << "r2: " << r2.getNumerador() << "/" << r2.getDenominador() << endl;

    Racional r3 = r1 + r2;
    cout << "r3 = r1 + r2: " << r3.getNumerador() << "/" << r3.getDenominador() << endl;

    r3 += r2;
    cout << "r3 += r2: " << r3.getNumerador() << "/" << r3.getDenominador() << endl;

    Racional r4 = -r3;
    cout << "-r3: " << r4.getNumerador() << "/" << r4.getDenominador() << endl;

    Racional r5 = ++r4;
    cout << "++r4: " << r5.getNumerador() << "/" << r5.getDenominador() << endl;

    Racional r6 = r5--;
    cout << "r5--: " << r6.getNumerador() << "/" << r6.getDenominador() << endl;

    double valor = r6.valor();
    cout << "valor de r6: " << valor << endl;


    vector<Racional> v;
    v.push_back(Racional(3, 4));
    v.push_back(Racional(1, 2));
    v.push_back(Racional(2, 3));

    sort(v.begin(), v.end());

    cout << "Vetor Ordenado: ";
    for (const auto& num : v) {
        cout << num.getNumerador() << "/" << num.getDenominador() << " ";
    }
    cout << endl;

    Racional soma(0, 1);
    for (const auto& num : v) {
        soma += num;
    }

    cout << "soma: " << soma.getNumerador() << "/" << soma.getDenominador() << endl;

    return 0;
}