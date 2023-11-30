// Task 3
// You will implement a Currency Conversion calculator.
// Three classes are defined:
// CurrencyBDT represents an amount in BDT and poisha. It has two private member variables:
// taka and poisha.
// CurrencyDollar represents an amount in US Dollars and cents. It has two private member
// variables: dollars and cents.
// CurrencyEuro represents an amount in Euros and cents. It also has two private member variables:
// euros and cents.
// The member functions:
// The classes have constructors to initialize the currency amounts. The default constructor sets the
// amounts to zero, and the parameterized constructor is used to specify the amount in
// taka/dollars/euros and poisha/cents.
// There are two conversion functions: The first one is used to convert an amount in USD to an
// equivalent amount in BDT. It takes into account the conversion rate (1 BDT = 0.0091 USD) and
// performs the necessary calculations to convert the amount (11 dollar 44 cents= 1254 taka 72
// poisha). The second conversion is used for Euro to BDT(1 BDT = 0.0085 Euro)
// In the main() function, show both conversions.


#include <bits/stdc++.h>
using namespace std;
class CurrencyBDT
{
private:
    int taka;
    int poisha;

public:
    CurrencyBDT(int t = 0, int p = 0) : taka(t), poisha(p) {}

    void convertFromUSD(int dollars, int cents)
    {
        double usdAmount = dollars + cents / 100.0;
        double bdtAmount = usdAmount / 0.0091;
        taka = static_cast<int>(bdtAmount);
        poisha = static_cast<int>((bdtAmount - taka) * 100);
    }
    void convertFromEuro(int euros, int cents)
    {
        double euroAmount = euros + cents / 100.0;
        double bdtAmount = euroAmount / 0.0085;
        taka = static_cast<int>(bdtAmount);
        poisha = static_cast<int>((bdtAmount - taka) * 100);
    }
    void display() const
    {
        cout << "Amount in BDT: " << taka << " Taka " << poisha << " poisha " << endl;
    }
};

class CurrencyDollar
{
private:
    int dollars;
    int cents;

public:
    CurrencyDollar(int d = 0, int c = 0) : dollars(d), cents(c) {}

    void convertToBDT(CurrencyBDT& bdt) const {
        double usdAmount = dollars + cents / 100.0;
        double bdtAmount = usdAmount * 0.0091;
        bdt = CurrencyBDT(static_cast<int>(bdtAmount), static_cast<int>((bdtAmount - static_cast<int>(bdtAmount)) * 100));
    }

    void display() const {
        cout << "Amount in USD: $" << dollars << "." << cents << endl;
    }
};

class CurrencyEuro{
    private:
    int euros;
    int cents;

    public:
    CurrencyEuro(int e = 0, int c = 0) : euros(e), cents(c) {}

    void convertToBDT(CurrencyBDT& bdt) const {
        double euroAmount = euros + cents / 100.0;
        double bdtAmount = euroAmount * 0.0085;
        bdt = CurrencyBDT(static_cast<int>(bdtAmount), static_cast<int>((bdtAmount - static_cast<int>(bdtAmount)) * 100));
    }
    void display() const {
        cout << "Amount in Euros: €" << euros << "." << cents << endl;
    }

};
int main()
{
    CurrencyDollar usd(11, 44);
    CurrencyEuro euro(8, 75);

    CurrencyBDT bdtFromUSD, bdtFromEuro;

    usd.convertToBDT(bdtFromUSD);
    euro.convertToBDT(bdtFromEuro);

    cout << "Conversion from USD to BDT:" << endl;
    usd.display();
    bdtFromUSD.display();

    cout << "\nConversion from Euro to BDT:" << endl;
    euro.display();
    bdtFromEuro.display();

    return 0;

}