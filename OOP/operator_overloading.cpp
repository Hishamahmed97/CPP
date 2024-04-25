#include <iostream>
#include <string>
#include <iostream>

class Complex
{
    private:
    float real;
    float imaginary;

    public:
    Complex(float m_real = 0,float m_imag = 0):real(m_real),imaginary(m_imag)
    {

    }
    // operator overloading for + operator
    Complex operator+(Complex &rhs)
    {
        Complex temp;
        temp.real = real + rhs.real;
        temp.imaginary = imaginary + rhs.imaginary;
        return temp;
    }
    friend std::ostream & operator<<(std::ostream &output,Complex &input); // header for friend function

};
    // operator overloading for << operator
std::ostream & operator<<(std::ostream &output,Complex &input)
{
    output<<input.real<<" "<<input.imaginary;
}

int main()
{
    Complex C1(5,2);
    Complex C2(6,7);
    Complex C3;
    C3 = C1 + C2;
    std::cout<<C3;


    return 0;
}


