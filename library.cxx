#include <iostream>
#include<string>
using namespace std;
string name, state;
string voucher, phonenumber;
int age;
int i = 0;
int id = 100;
const int discount = 2;

bool check=true;
string Name[100];
int age_id[100][2];
string phone_state[100][2];
bool checker(string fname)
{
	bool exist = false;
	for (int j = 0; j <= i; j++)
	{
		if (fname == Name[j])
			exist = true;
	}
	return exist;
}
int calculatefee(string checkvoucher)
{
	double fee = 20.0;
	if (checkvoucher == "Y")
	{
		fee = 20 - discount;
	}
	return fee;
}
void message()
{
	if (checker(name) == false)
	{
		cout << "You are sucessfully Registred \n";
		cout << "Your membership fee is : \n"
			 << "$ " << calculatefee(voucher) << endl;
		cout << "Your membership ID : \n"
			 << id << "\n\n";
	}
	else
	{
		cout << "The name already exist try another name please \n\n";
	}
}

void storing_detail()
{
	double fee = calculatefee(voucher);

	if (((i >= 0) || (i <= 99)) && (checker(name) == false))
	{
		Name[i] = name;
		age_id[i][0] = age;
		age_id[i][1] = id;
		phone_state[i][0] = phonenumber;
		phone_state[i][1] = state;
		id += 1;
		i++;
	}
}

int main()
{
	cout << "\tWELCOME TO LIBRARY REGISTRATION  SYSTEM\n\n\n"
		 << endl;
		 string ntester;
	do
	{
		cout << "Please Enter Your Details\n\n";
		cout << "Name :  ";
		cin>>name;
		cin>>ntester;
	  // getline(cin, name);
		cout << "Age :  ";
		cin >> age;
		cout << "State :  ";
		cin >> state;
		cout << "Phone Number : ";
		cin >> phonenumber;
		cout << "Do you have voucher Y/N ? ";
		cin >> voucher;
		cout << "\n";
		checker(name);
		if (voucher == "Y" || voucher == "y")
			voucher = "Y";
		if (voucher == "N" || voucher == "n")
			voucher = "N";
		calculatefee(voucher);

		message();
		storing_detail();
		
		cin.ignore();

	} while (check == true);
}