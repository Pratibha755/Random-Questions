#include<iostream>
#include<fstream>
#include <unistd.h>
using namespace std;
class System
{
	protected :
	string Password,SystemPass,Email,ManagerEmail,PassCompare,EmailCompare,name;
	int LoginSuccessful,choice,id,bill,upi,DeleteID,flag;
	long long phone,TotalBill;
	public:
	System()
	{
		//For Login
		Password="Admin123";
		ManagerEmail="Admin123@gmail.com";
		TotalBill=0;
	}
	//For login And to call Appropriate function.
	void Manager();
	void DisplayCustomer();
	void LoginFile();
	void check();
	void DeleteRecord();
};
void System :: DeleteRecord()
{
	flag=1;
	cout<<"			Enter Customer ID to Delete Record : ";
	cin>>DeleteID;
	ifstream ReadFromFile;
	ReadFromFile.open("CustomerRecords.txt");
	if(!ReadFromFile)
	{
		cout<<"\n			Sorry File Not Found ";
	}
	else
	{
		ofstream WriteToFile;
		WriteToFile.open("NotToDelete.txt",ios::app);
		while(!ReadFromFile.eof())
		{
			ReadFromFile>>id;
			ReadFromFile>>bill;
			ReadFromFile>>name;
			ReadFromFile>>upi;
			ReadFromFile>>phone;
			if(!ReadFromFile.eof())
			{
				if(id==DeleteID)
				{
					cout<<"\n			********************************************************";
					cout<<"\n				Deleted Record : ";
					cout<<"\n				----------------------------------------";
					cout<<"\n					Customer ID	: "<<id;
					cout<<"\n					Name		: "<<name;
					cout<<"\n					UPI ID		: "<<upi;
					cout<<"\n					Contact		: "<<phone;
					cout<<"\n					Total Bill	: "<<bill;
					cout<<"\n				----------------------------------------";
					flag=0;
				}
				else
				{
					WriteToFile<<id<<"\t";
					WriteToFile<<bill<<"\t";
					WriteToFile<<name<<"\t";
					WriteToFile<<upi<<"\t";
					WriteToFile<<phone<<endl;
				}
			}
		}
		WriteToFile.close();
		ReadFromFile.close();
		remove("CustomerRecords.txt");
		rename("NotToDelete.txt","CustomerRecords.txt");
	}
}
void System :: LoginFile()
{
	ofstream appendlogin;
	appendlogin.open("Login.txt",ios::app);
	if(!appendlogin)
	{
		//Noting here.
	}
	else
	{
		cout<<"\n			Enter Email	: ";
		cin>>Email;
		cout<<"			Enter Password	: ";
		cin>>SystemPass;
		appendlogin<<Email<<"\t";
		appendlogin<<SystemPass<<endl;
		appendlogin.close();
	}
	sleep(2);
}
void System :: check()
{
	ifstream ReadFromFile;
	ReadFromFile.open("CustomerRecords.txt");
	if(!ReadFromFile)
	{
		TotalBill=0;
	}
	else
	{
		TotalBill=0;
		while(!ReadFromFile.eof())
		{
			ReadFromFile>>id;
			ReadFromFile>>bill;
			ReadFromFile>>name;
			ReadFromFile>>upi;
			ReadFromFile>>phone;
			if(!ReadFromFile.eof())
			{
				TotalBill=TotalBill+bill;
			}
		}
		cout<<"\n\n				----------------------------------------";
		cout<<"\n					Amount  : Rs. "<<TotalBill;
		cout<<"\n					Profit  : Rs. "<<(TotalBill*7)/100;
		cout<<"\n				----------------------------------------\n\n";
	}
	ReadFromFile.close();
}
void System :: DisplayCustomer()
{
	ifstream ReadFromFile;
	ReadFromFile.open("CustomerRecords.txt");
	if(!ReadFromFile)
	{
		cout<<"				Sorry No Records Found ";
	}
	else
	{
		cout<<"\n			   ***************************************************";
		cout<<"\n						Customer Records";
		cout<<"\n			   ***************************************************";
		while(!ReadFromFile.eof())
		{
			ReadFromFile>>id;
			ReadFromFile>>bill;
			ReadFromFile>>name;
			ReadFromFile>>upi;
			ReadFromFile>>phone;
			if(!ReadFromFile.eof())
			{
				cout<<"\n\n				----------------------------------------";
				cout<<"\n					Customer ID	: "<<id;
				cout<<"\n					Name		: "<<name;
				cout<<"\n					UPI ID		: "<<upi;
				cout<<"\n					Contact		: "<<phone;
				cout<<"\n					Total Bill	: "<<bill;
				cout<<"\n				----------------------------------------";
			}
		}
	}
	ReadFromFile.close();
	
}
void System :: Manager()
{
	LoginSuccessful=0;
	cout<<"		Enter Email ID : ";
	cin>>Email;
	cout<<"		Enter Password : ";
	cin>>SystemPass;
	ifstream login;
	login.open("Login.txt");
	if(!login)
	{
		LoginSuccessful=0;
	}
	else
	{
		while(!login.eof())
		{
			login>>EmailCompare;
			login>>PassCompare;
			if(Email==EmailCompare&&SystemPass==PassCompare)
			{
				LoginSuccessful=1;
			}
		}
		login.close();
	}
	int d=4;
	cout<<"				   -----";
	while(d>0)
	{
		sleep(1);
		cout<<"---";
		d--;
	}
	if(LoginSuccessful==1||(Email==ManagerEmail&&Password==SystemPass))
	{
		cout<<"\n					Login Successul... ";
		sleep(2);
		do{
			cout<<"\n			Press 1. Customer Details Display.\n			Press 2. Add Login Details \n			Press 3. Check Profit.\n			Press 4. Delete Customer Record\n			Press 0. Exit.\n";
			cout<<"\n			Enter Your Choice : ";
			cin>>choice;
			switch(choice)
			{
				case 1 :
					system("cls");
					DisplayCustomer();
					break;
				case 2:
					system("cls");
					LoginFile();
					break;
				case 3:
					system("cls");
					check();
					break;
				case 4:
					system("cls");
					DeleteRecord();
					break;
				case 0 :
					system("cls");
					//Exit
					break;
				default:
					system("cls");
					cout<<"\n					Please Enter Valid Choice....";
					
			}
		}while(choice!=0);
	}
	else
	{
		cout<<"\n						Invalid Email or Wrong Password...";
	}
		
	
}
class Menu : public System
{
	public:
	int MeduVada,VadaRassa,Dosa,MasalaDosa,Pohe,Samosa,Chai,Idli,Bhel;
	Menu()
	{
		MeduVada=25;
		VadaRassa=30;
		Dosa=40;
		MasalaDosa=45;
		Pohe=15;
		Samosa=15;
		Chai=10;
		Idli=35;
		Bhel=20;
	}
	void Display()
	{
		cout<<"\n		1.  Medu Vada	: Rs. 25/-";  
		cout<<"\n		2.  Vada Rassa	: Rs. 30/-";
		cout<<"\n		3.  Dosa	: Rs. 40/-";
		cout<<"\n		4.  Masala Dosa	: Rs. 45/-";
		cout<<"\n		5.  Pohe	: Rs. 15/-";
		cout<<"\n		6.  Samosa	: Rs. 15/-";
		cout<<"\n		7.  Chai	: Rs. 10/-";
		cout<<"\n		8.  Idli	: Rs. 35/-";
		cout<<"\n		9.  Bhel	: Rs. 20/-";
		cout<<endl;
	}
};
class Customer : public Menu
{
	public:
	int Bill,choice,choiceNo,Quantity,i,ID,total,UPI,payment;
	float discount;
	long long Phone;
	string BillOrder[20],Name;
	int BillQuantity[20];
	Customer()
	{
		Bill=0;
		ID=20230000;
		discount=0;
		i=0;
		total=0;
		payment=0;
	}
	void Order();
};

void Customer :: Order()
{
	do{
		Display();
		cout<<"\n\n	Enter Order Number	: ";
		cin>>choiceNo;
		cout<<"	Enter Quantity		: ";
		cin>>Quantity;
		switch(choiceNo)
		{
			case 1 :
				Bill+=MeduVada*Quantity;
				BillQuantity[i]=Quantity;
				BillOrder[i]=" Medu Vada	";
				i++;
				break;
			case 2 :
				Bill+=VadaRassa*Quantity;
				BillQuantity[i]=Quantity;
				BillOrder[i]=" Vada Rassa	";
				i++;
				break;
			case 3 :
				Bill+=Dosa*Quantity;
				BillQuantity[i]=Quantity;
				BillOrder[i]=" Dosa	";
				i++;
				break;
			case 4 :
				Bill+=MasalaDosa*Quantity;
				BillQuantity[i]=Quantity;
				BillOrder[i]=" Masala Dosa ";
				i++;
				break;
			case 5 :
				Bill+=Pohe*Quantity;
				BillQuantity[i]=Quantity;
				BillOrder[i]=" Pohe	";
				i++;
				break;
			case 6 :
				Bill+=Samosa*Quantity;
				BillQuantity[i]=Quantity;
				BillOrder[i]=" Samosa	";
				i++;
				break;
			case 7 :
				Bill+=Chai*Quantity;
				BillQuantity[i]=Quantity;
				BillOrder[i]=" Chai	";
				i++;
				break;
			case 8 :
				Bill+=Idli*Quantity;
				BillQuantity[i]=Quantity;
				BillOrder[i]=" Idli	";
				i++;
				break;
			case 9 :
				Bill+=Bhel*Quantity;
				BillQuantity[i]=Quantity;
				BillOrder[i]=" Bhel	";
				i++;
				break;
			default:
				cout<<"			Sorry Wrong Choice...\n			Please Enter Valid Order Number. ";
				break;
		}
		cout<<"\n	Anything Else ? \n	Press 0 to Exit \n	Press 1 to continue : ";
		cin>>choice;
	}while(choice!=0);
	ifstream idcreate;
	idcreate.open("CustomerID.txt");
	idcreate>>ID;
	ID++;
	idcreate.close();
	ofstream createID;
	createID.open("CustomerID.txt");
	createID<<ID;
	createID.close();
	cout<<"\n		************************************************";
	cout<<"\n			Customer ID 		: "<<ID<<endl;
	for(int j=0;j<i;j++)
	{
		cout<<"			"<<j+1<<". "<<BillOrder[j]<<"	: "<<BillQuantity[j]<<endl;
		total=total+BillQuantity[j];
	}
	cout<<"		________________________________________________";
	cout<<"\n			Total Quantities	: "<<total;
	discount=(Bill*8)/100;
	cout<<"\n			Total Bill  		: "<<Bill<<" Rs.";
	cout<<"\n			Discount 		: "<<discount<<" Rs. ";
	cout<<"\n			Final Bill		: "<<Bill-discount<<" Rs.";
	cout<<"\n		************************************************"<<endl;
	if(Bill-discount>0)
	{
		cout<<"			Please Press 1 for the payment : ";
		cin>>payment;
		if(payment==1)
		{
			cout<<"			Enter Your Name : ";
			cin>>Name;
			cout<<"			Enter UPI ID    : ";
			cin>>UPI;
			cout<<"			Enter Mobile No.: ";
			cin>>Phone;
			ofstream WriteToFile;
			WriteToFile.open("CustomerRecords.txt",ios::app);
			WriteToFile<<ID<<"\t";
			WriteToFile<<Bill-discount<<"\t";
			WriteToFile<<Name<<"\t";
			WriteToFile<<UPI<<"\t";
			WriteToFile<<Phone<<"\n";
			WriteToFile.close();
		}
	}
	cout<<"					Thank You for visiting.. ";
	sleep(3);
	system("cls");
	
}
int main()
{
	int ch;
	cout<<"\n	**************************************************************";
	cout<<"\n		================ SUMIT CANTEEN ================";
	cout<<"\n			Address : Shinde Complex, \n 		   	          Nashik Road, \n				  Manmad (423104) ";
	cout<<"\n	**************************************************************";
	
	cout<<"\n\n	******* WELCOME TO SUMIT CANTEEN *******";
	cout<<"\n\n	  ************ Rate Card ************ ";
	Menu *Mptr= new Menu();
	Customer *Cptr= new Customer();
	System *Sptr= new System();
	Mptr->Display();
	do{
		cout<<"\n		Press 1. Log in (Manager) \n		Press 2. Customer \n		Press 0. Exit";
		cout<<"\n		Enter Your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				system("cls");
				Sptr->Manager();
				break;
			case 2:
				system("cls");
				cout<<"\n\n		************* Rate Card ************** ";
				Cptr->Order();
				break;
			case 0:
				//exit
				cout<<"					Thank You for visiting.. ";
				sleep(3);
				break;
			default:
				cout<<"		Invalid Choice.. ";
		}
	}while(ch!=0);
}