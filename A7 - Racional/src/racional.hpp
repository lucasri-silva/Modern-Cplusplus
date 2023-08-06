/*

Implemente uma classe com nome Racional, a qual será utilizada para representar números racionais de maneira exata. Para isso, a 
ele deverá representar os valores em um formato de fração irredutível, ou seja, internamente a classe deverá ter um atributo inteiro
para representar o numerador e outro atributo para representar o denominador. Caso o valor representado seja negativo, o numerador
é quem deverá ser negativo. Além disso, a classe Racional deverá implementar:

• Construtor padrão (construtor que não recebe nenhum argumento), o qual deverá produzir um objeto de Racional que represente o 
valor zero.
• Construtor que receba dois números inteiros sendo, respectivamente, o numerador e o denominador.
• Construtor de cópia (construtor que recebe uma referência de lvalor constante para o mesmo tipo da classe).
• Construtor de transferência (construtor que recebe uma referência de rvalor para o mesmo tipo da classe).
• Destrutor, caso seja necessário desalocar algum recurso dinâmico alocado pela classe.
• Operadores de atribuição por cópia e por transferência.
• Operadores relacionais <, <=, >, >=, e ==. Tais operadores devem ser métodos constantes, pois não modificam o objeto.
• Operadores aritméticos +, –, *, /, +=, –=, *=, /=, ++ (pré-fixado e pós-fixado), –– (pré-fixado e pós-fixado), e o operador 
– (unário). Os operadores aritméticos que não modificam o objeto devem ser implementados como métodos constantes.
• Métodos constantes numerador() e denominador() que retornem referências constantes para o numerador e denominador, respectivamente.
• Métodos (não constantes) numerador(int num) e denominador(int den) que alterem os valores do numerador e do denominador, respectivamente.
• Um método constante valor() que retorne um valor do tipo double referente ao valor representado pelo objeto de Racional.


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Racional
{
private:
    int numerador;
    int denominador;

    int mdc(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return mdc(b, a % b);
    }

    void reduce()
    {
        int divisor = mdc(numerador, denominador);
        numerador /= divisor;
        denominador /= divisor;

        if (denominador < 0)
        {
            numerador = -numerador;
            denominador = -denominador;
        }
    }

public:
    Racional() : numerador(0), denominador(1) {}

    Racional(int num, int den) : numerador(num), denominador(den)
    {
        reduce();
    }

    Racional(const Racional &other) : numerador(other.numerador), denominador(other.denominador) {}

    Racional(Racional &&other) noexcept : numerador(other.numerador), denominador(other.denominador) {}

    ~Racional() {}

    Racional &operator=(const Racional &other)
    {
        if (this != &other)
        {
            numerador = other.numerador;
            denominador = other.denominador;
        }
        return *this;
    }

    Racional &operator=(Racional &&other)
    {
        if (this != &other)
        {
            numerador = other.numerador;
            denominador = other.denominador;
        }
        return *this;
    }

    bool operator<(const Racional &other) const
    {
        return (numerador * other.denominador) < (other.numerador * denominador);
    }

    bool operator<=(const Racional &other) const
    {
        return (numerador * other.denominador) <= (other.numerador * denominador);
    }

    bool operator>(const Racional &other) const
    {
        return (numerador * other.denominador) > (other.numerador * denominador);
    }

    bool operator>=(const Racional &other) const
    {
        return (numerador * other.denominador) >= (other.numerador * denominador);
    }

    bool operator==(const Racional &other) const
    {
        return (numerador * other.denominador) == (other.numerador * denominador);
    }

    Racional operator+(const Racional &other) const
    {
        int num = (numerador * other.denominador) + (other.numerador * denominador);
        int den = denominador * other.denominador;
        return Racional(num, den);
    }

    Racional operator-(const Racional &other) const
    {
        int num = (numerador * other.denominador) - (other.numerador * denominador);
        int den = denominador * other.denominador;
        return Racional(num, den);
    }

    Racional operator*(const Racional &other) const
    {
        int num = numerador * other.numerador;
        int den = denominador * other.denominador;
        return Racional(num, den);
    }

    Racional operator/(const Racional &other) const
    {
        int num = numerador * other.denominador;
        int den = denominador * other.numerador;
        return Racional(num, den);
    }

    Racional &operator+=(const Racional &other)
    {
        *this = *this + other;
        return *this;
    }

    Racional &operator-=(const Racional &other)
    {
        *this = *this - other;
        return *this;
    }

    Racional &operator*=(const Racional &other)
    {
        *this = *this * other;
        return *this;
    }

    Racional &operator/=(const Racional &other)
    {
        *this = *this / other;
        return *this;
    }

    Racional operator-() const
    {
        return Racional(-numerador, denominador);
    }

    Racional &operator++()
    {
        numerador += denominador;
        return *this;
    }

    Racional operator++(int)
    {
        Racional temp = *this;
        ++(*this);
        return temp;
    }

    Racional &operator--()
    {
        numerador -= denominador;
        return *this;
    }

    Racional operator--(int)
    {
        Racional temp = *this;
        --(*this);
        return temp;
    }

    const int &getNumerador() const
    {
        return numerador;
    }

    const int &getDenominador() const
    {
        return denominador;
    }

    void setNumerador(int num)
    {
        numerador = num;
        reduce();
    }

    void setDenominador(int den)
    {
        denominador = den;
        reduce();
    }

    double valor() const
    {
        return static_cast<double>(numerador) / denominador;
    }

};