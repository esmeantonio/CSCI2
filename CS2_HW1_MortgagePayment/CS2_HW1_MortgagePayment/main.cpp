/*
 Program name: mortgage_payment.cpp
 Programmer: Esmeralda Antonio
 Date: 02/16/2023
 Version: 1.5
 Description: We obtain the loan amount, interest rate, and
 the number of years of the loan from the user. With this,
 we are able to calculate the monthly payment and total
 amount paid to the bank by the end of the loan period.
 */

#include <iostream>
#include <cmath>
using namespace std;

class MortgagePayment
{
private:
    /*
    principal -> loan amount
    rate -> interest rate
    term -> years
    */
    double principal;
    double rate;
    double term;
public:
    //Default Constructor
    MortgagePayment()
    {
        principal = 0.0;
        rate = 0.0;
        term = 0;
    }
    //Constructor with three arguments
    MortgagePayment(double p, double r, double t)
    {
        principal = p;
        rate = r/1200.0;
        term = t*12.0;
    }
    //Accessor
    double getPrincipal()
    {
        return principal;
    }
    //Mutator
    void setPrincipal(double p)
    {
        principal = p;
        while (principal < 0.0) {
            cout << "You may not enter negative loan values. Please try again." << endl;
            cin >> principal;
        }
    }
    //Accessor
    double getRate()
    {
        return rate;
    }
    //Mutator
    void setRate(double r)
    {
        rate = r/1200.0;
    }
    //Accessor
    double getTerm()
    {
        return term;
    }
    //Mutator
    void setTerm(double t)
    {
        term = t*12.0;
    }
    //Calculate monthly payment
    double getMonthlyPayment() const
    {
        double monthlypayment = (principal*rate)/(1.0 - pow(rate+1, -term));
        double roundedPayment = (int) ((monthlypayment*100)+0.5);
        return (double) roundedPayment/100;
    }
    //Calculate total amount paid to bank at end of loan period
    double getTotalPaid() const
    {
        return getMonthlyPayment()*term;
    }
    //Outputs monthly payment and total amount paid to bank at end of loan period
    void display()
    {
        cout << "The monthly payment is: $" << getMonthlyPayment() << " and the total amount paid at the end of the loan period is $" << getTotalPaid() << endl;
    }
    
};



int main() {
    MortgagePayment paym2(1200, 0.5, 3);
    paym2.display();
    
    MortgagePayment paym3(70000, 3.7, 6);
    paym3.setPrincipal(-5000);
    paym3.display();
    
    MortgagePayment paym4(50000, 1.6, 5);
    paym4.display();
}
