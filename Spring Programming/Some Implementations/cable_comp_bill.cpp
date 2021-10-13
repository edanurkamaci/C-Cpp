#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
	int accountNumber;
	char customerType;
	int numOfPremChannels;
	int numOfBasicServiceConn;
	double amountDue;

	const double RESS_BILL_PROC_FEES = 4.50;
	const double RESS_BASIC_SERV_COST = 20.50;
	const double RESS_COST_PREM_CHANNEL = 7.50;

	const double BUSS_BILL_PROC_FEES = 15.00;
	const double BUSS_BASIC_SERV_COST = 75.00;
	const double BUSS_COST_PREM_CHANNEL = 5.00;
	const double BUSS_BASIC_CONN_COST = 50.00;

	cout << fixed << showpoint;
	cout << setprecision(2);

	cout << "Enter the customer account number(5 digits): ";
	cin >> accountNumber;
	
	cout << "Enter the customer code(B or R): ";
	
	while (1)
	{
		
		cin >> customerType;

		if (customerType == 'R' || customerType == 'r')
		{
			cout << "Enter number of premium channels: ";
			cin >> numOfPremChannels;

			amountDue = RESS_BASIC_SERV_COST + RESS_BILL_PROC_FEES + numOfPremChannels * RESS_COST_PREM_CHANNEL;
			break;
		}
		else if (customerType == 'B' || customerType == 'b')
		{
			cout << "Enter number of basic serve connections: ";
			cin >> numOfBasicServiceConn;

			cout << "Enter number of premium channels: ";
			cin >> numOfPremChannels;

			if (numOfBasicServiceConn <= 10)
			{
				amountDue = BUSS_BASIC_SERV_COST + BUSS_BILL_PROC_FEES + numOfPremChannels * BUSS_COST_PREM_CHANNEL;
			}
			else
			{
				amountDue = BUSS_BASIC_SERV_COST + BUSS_BILL_PROC_FEES + numOfPremChannels * BUSS_COST_PREM_CHANNEL + (numOfBasicServiceConn - 10)*BUSS_BASIC_CONN_COST;
			}

			break;
		}
		else
		{
			cout << "ERROR!! YOU ENTERED ÝNVALÝD CODE!!! TRY AGAÝN\n";
		}
	}

	cout << endl << endl << "Account number: " << accountNumber << endl;
	cout << "Bill: $ " << amountDue << endl << endl;

	system("pause");
	return 0;
}
