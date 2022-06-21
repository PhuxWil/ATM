
//Implementation of the class CheckingAccount.
#include <iostream>
#include <cmath>
using namespace std;

// To Do: include necessary header files
#include "CheckingAccount.h"


// To Do: Please write comments and code to implement CheckingAccount here
// Constructor that takes dollar, cents and fee
// Initializes the account balance to $dollars.cents and the check fee to fee.
CheckingAccount::CheckingAccount(int dollars, int cents, double fee) : BankAccount(dollars, cents), check_fee(fee)
{
   if (fee < 0) {
      cout << " Invaild Fee " << endl;
      exit(1);
   }

}
CheckingAccount::CheckingAccount(int dollars, double fee) : BankAccount(dollars), check_fee(fee)
{
   if (fee < 0) {
       cout << " Invaild Fee " << endl;
       exit(1);
   }

}
CheckingAccount::CheckingAccount() : BankAccount(), check_fee(0.0)
{
   // left empty for perm.
}

// Output the CheckingAccount
void CheckingAccount::output(ostream& outs) const
{
	BankAccount::output(outs);
    outs << "Check fee: $" << getFee() << " " << endl;
}

// Input the balance for the BankAccount
void CheckingAccount::input(istream& ins)
{
	BankAccount::input(ins);
    ins >> check_fee;

}
//return checking fee
double CheckingAccount::getFee() const
{
    return check_fee;
}
//check function how much to withdraw + fee
void CheckingAccount::checking(int dollars, int cents)
{ 
    double amount = dollars + .01*cents;
    double bal = get_balance();
    if (dollars >= 0 && cents >= 0 && amount <= get_balance())
    {
       double check = (bal - (amount + getFee()));
       set_balance(check);
    }
    else {
       cout << "Illegal values for money must be greater than or equal 0 ";
       cout << "and less than or equal to the balance.\n";
    }    
} 

