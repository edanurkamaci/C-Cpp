#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>

using namespace std;

const double MINIMUM_BALANCE = 1000.00;
const double SERVICE_CHARGE = 25.00;

int main()
{
	ifstream infile;
	ofstream outfile;

	int  acctNumber;
	double beginningBalance;
	double accountBalance;

	double amountDeposited= 0.0;
	int numberOfDeposits=0;

	double amountWithdrawn= 0.0;
	int numberOfWithdrawals=0;

	double interestPaid=0.0;

	char transactionCode;
	double transactionAmount;

	bool isServiceCharged=false;

	infile.open("account.txt");
	outfile.open("last_shot.out");

	outfile << fixed << showpoint;
	outfile << setprecision(2);

	infile >> acctNumber >> beginningBalance;
	accountBalance = beginningBalance;

	infile >> transactionCode >> transactionAmount;

	while(infile)
	{
		switch (transactionCode)
		{
		    case 'D':
			case 'd':
			{
				accountBalance += transactionAmount;
				amountDeposited += transactionAmount;
				numberOfDeposits++;
				break;
			}
			case 'I':
			case 'i':
			{
				accountBalance += transactionAmount;
				interestPaid += transactionAmount;
				break;
			}
			case 'W':
			case 'w':
			{
				accountBalance -= transactionAmount;
				amountWithdrawn += transactionAmount;
				numberOfWithdrawals++;

				if (accountBalance < MINIMUM_BALANCE && !isServiceCharged)
				{
					accountBalance -= SERVICE_CHARGE;
					isServiceCharged = true;
				}
				break;
			}
			default:
			{
				cout << "Invalid transaction code!!!" << endl << endl;
			}
				
		}
		infile >> transactionCode >> transactionAmount;
	}

	outfile << "Account Number: " << acctNumber << endl;
	outfile << "Beginning Balance: " << beginningBalance<<endl<<endl;
	outfile << "Ending Balance: " << accountBalance << endl;
	outfile << "Interest Paid: " << interestPaid << endl<<endl;
	outfile << "Amount Deposited: " << amountDeposited << endl;
	outfile << "Number of Deposits: " << numberOfDeposits << endl<<endl;
	outfile << "Amount Withdrawn: " << amountWithdrawn << endl;
	outfile << "Number of Withdrawls: " << numberOfWithdrawals << endl;

	infile.close();
	outfile.close();

	system("pause");
	return 0;
}
