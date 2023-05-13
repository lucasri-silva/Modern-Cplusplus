// /*Implemente uma classe BigInt que represente valores inteiros. A representação interna deverá ser feita com
// array ou string. Além disso, a classe deve implementar: Construtor que recebe uma string como parâmetro
// de entrada; um construtor de cópia; operadores +, -, * e / .*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BigInt
{

private:
    vector<int> digits;

public:
    BigInt(std::string str)
    {
        for (int i = str.size() - 1; i >= 0; i--)
        {
            digits.push_back(str[i] - '0');
        }
    }

    BigInt(const BigInt &other)
    {
        digits = other.digits;
    }

    string toString() const
    {
        string result;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            result += to_string(digits[i]);
        }
        return result;
    }

    BigInt operator+(const BigInt &other) const
    {
        BigInt result = *this;
        result += other;
        return result;
    }

    BigInt operator-(const BigInt &other) const
    {
        BigInt result = *this;
        result -= other;
        return result;
    }

    BigInt operator*(const BigInt &other) const
    {
        BigInt result = *this;
        result *= other;
        return result;
    }

    BigInt operator/(const BigInt &other) const
    {
        BigInt result = *this;
        result /= other;
        return result;
    }

    BigInt &operator+=(const BigInt &other)
    {
        int carry = 0;
        for (int i = 0; i < std::max(digits.size(), other.digits.size()) || carry; i++)
        {
            if (i == digits.size())
                digits.push_back(0);
            digits[i] += carry + (i < other.digits.size() ? other.digits[i] : 0);
            carry = digits[i] >= 10;
            if (carry)
                digits[i] -= 10;
        }
        return *this;
    }

    BigInt &operator-=(const BigInt &other)
    {
        int carry = 0;
        for (int i = 0; i < other.digits.size() || carry; i++)
        {
            digits[i] -= carry + (i < other.digits.size() ? other.digits[i] : 0);
            carry = digits[i] < 0;
            if (carry)
                digits[i] += 10;
        }
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        return *this;
    }

    BigInt &operator*=(const BigInt &other)
    {
        std::vector<int> result(digits.size() + other.digits.size());
        for (int i = 0; i < digits.size(); i++)
        {
            for (int j = 0; j < other.digits.size(); j++)
            {
                result[i + j] += digits[i] * other.digits[j];
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
        while (result.size() > 1 && result.back() == 0)
            result.pop_back();
        digits = result;
        return *this;
    }

    BigInt &operator/=(const BigInt &other)
    {
        if (other.digits.size() == 1 && other.digits[0] == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        BigInt quotient(""), remainder("");
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            remainder.digits.insert(remainder.digits.begin(), digits[i]);
            int q = 0;
            while (remainder >= other)
            {
                remainder -= other;
                q++;
            }
            quotient.digits.insert(quotient.digits.begin(), q);
        }
        while (quotient.digits.size() > 1 && quotient.digits.back() == 0)
            quotient.digits.pop_back();
        digits = quotient.digits;
        return *this;
    }

    bool operator>=(const BigInt &other) const
    {
        return !(*this < other);
    }

    bool operator<(const BigInt &other) const
    {
        if (digits.size() != other.digits.size())
        {
            return digits.size() < other.digits.size();
        }
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] != other.digits[i])
            {
                return digits[i] < other.digits[i];
            }
        }
        return false;
    }
};
