//OOP Mini Project : ONLINE VOTER MACHINE..!!
#include<iostream>
#include <unistd.h>
using namespace std;
#include<fstream>
int Candidate1=0,Candidate2=0,Candidate3=0,Candidate4=0,NOTA=0,j=0;
int VotedArray[100];
//To Store Eligible Voter's Details..
class VotingSystem
{
	public:
	int  var,Age,VoterID,ID,IDFlag;
	long long Aadhar;
	string FirstName,LastName,MiddleName,Birthdate,Address;
	VotingSystem()
	{
		var=0;
		VoterID=20220000;
	}
	//To Create Voter ID for New Voter and Details.
	int IDcreate();
	void NewVoter();
	//To Display Details of Deleted Voter.
	void DeleteVoter();
	//To display Details of All Eligible Voter.
	void DetailsDisplay();
	//To check ID present in system or not.
	int check(int ID);
};
int VotingSystem :: IDcreate()
{
	//"CreatID.txt" contains int var
	ifstream addID;
	addID.open("CreateID.txt");
	//read int var from "CreatID.txt"
	addID>>var;
	addID.close();
	ofstream AddID;
	AddID.open("CreateID.txt");
	//increament var and write in "CreatID.txt"
	var++;
	AddID<<var;
	AddID.close();
	return var;
}
void VotingSystem :: NewVoter()
{
	VoterID=20220000;
	cout<<"\n	Enter Details Of Voter : ";
	cout<<"\n	Enter Age Of New Voter : ";
	cin>>Age;
	//check Age
	if(Age>17)
	{
		//VoterID =20220000 + returned value from IDcreate();
		VoterID=VoterID+ IDcreate();
		cout<<"	\n	----------------------------------";
		cout<<"\n	Voter ID    : "<<VoterID;
		cout<<"\n	Aadhar No.  : ";
		cin>>Aadhar;
		cout<<"	First  Name : ";
		cin>>FirstName;
		cout<<"	Middle Name : ";
		cin>>MiddleName;
		cout<<"	Last   Name : ";
		cin>>LastName;
		cout<<"	Birth Date  : ";
		cin>>Birthdate;
		cout<<"	Address     : ";
		cin>>Address;
		cout<<"	----------------------------------\n";
		ofstream writefile;
		writefile.open("SystemFile.txt",ios::app);
		if(!writefile)
		{
			cout<<"\n					   ------------ File Not Found ----------------";
		}
		else
		{
			//Output/write data to "SystemFile.txt"
			writefile<<VoterID<<"\t";
			writefile<<Aadhar<<"\t";
			writefile<<Age<<"\t";
			writefile<<FirstName<<"\t";
			writefile<<MiddleName<<"\t";
			writefile<<LastName<<"\t";
			writefile<<Birthdate<<"\t";
			writefile<<Address<<endl;
		}
		writefile.close();
	}
	else
	{
		cout<<"\n						-|-|-|-|-|- Not Eligible -|-|-|-|-|- \n";
	}

}
void VotingSystem :: DeleteVoter()
{
	int Del=-1, DelFlag;
	//Delete Voter
	cout<<"\n	Enter Voter ID to delete Details : ";
	cin>>DelFlag;
	//To check ID entered to delete is present or not :
	ifstream FindID;
	FindID.open("SystemFile.txt",ios::in);
	if(!FindID)
	{
		cout<<"\n						   ------------ File Not Found ----------------";
	}
	ofstream Rearrange;
	Rearrange.open("NotToDelete.txt");
	if(!Rearrange)
	{
		cout<<"\n						   ------------ File Not Found ----------------";
	}
	while(!FindID.eof())
	{
		FindID>>VoterID;
		FindID>>Aadhar;
		FindID>>Age;
		FindID>>FirstName;
		FindID>>MiddleName;
		FindID>>LastName;
		FindID>>Birthdate;
		FindID>>Address;
		if(VoterID==DelFlag&&Del!=0)
		{
			//Deleted Voter Details.
			cout<<"\n	----------------------------------";
			cout<<"\n	Deleted Voter Details : ";
			cout<<"\n	Voter ID   : "<<VoterID;
			cout<<"\n	Name	   : "<<FirstName<<" "<<MiddleName<<" "<<LastName;
			cout<<"\n	Aadhar No. : "<<Aadhar;
			cout<<"\n	Birth Date : "<<Birthdate;
			cout<<"\n	Age 	   : "<<Age;
			cout<<"\n	----------------------------------\n";
			Del=0;
		}
		else
		{
			if(!FindID.eof())
			{
				Rearrange<<VoterID<<"\t";
				Rearrange<<Aadhar<<"\t";
				Rearrange<<Age<<"\t";
				Rearrange<<FirstName<<"\t";
				Rearrange<<MiddleName<<"\t";
				Rearrange<<LastName<<"\t";
				Rearrange<<Birthdate<<"\t";
				Rearrange<<Address<<endl;
			}
		}
	}
	//If ID Not found in System
	if(Del!=0)
	{
		cout<<"\n					-|-|-|-|-|- Voter ID Not Found..!! -|-|-|-|-|-";
		Del=-1;
	}
	FindID.close();
	Rearrange.close();
	remove("SystemFile.txt");
	rename("NotToDelete.txt","SystemFile.txt");
}
void VotingSystem :: DetailsDisplay()
{
	ifstream readfile;
	readfile.open("SystemFile.txt");
	if(!readfile)
	{
		cout<<"\n					   ******************* File Not Found *******************";
	}
	else
	{
		int d=3;
		cout<<"				   Please Wait ---\n				   Loading -----";
		while(d>0)
		{
			sleep(1);
			cout<<"---";
			sleep(1);
			cout<<"---";
			d--;
		}
		system("cls");
		cout<<"				******************* Details in File : *******************";
		while(!readfile.eof())
		{
			readfile>>VoterID;
			readfile>>Aadhar;
			readfile>>Age;
			readfile>>FirstName;
			readfile>>MiddleName;
			readfile>>LastName;
			readfile>>Birthdate;
			readfile>>Address;
			if(!readfile.eof())
			{
				//Details Of Voter.
				cout<<"\n				----------------------------------------";
				cout<<"\n					Voter ID   : "<<VoterID;
				cout<<"\n					Name	   : "<<FirstName<<" "<<MiddleName<<" "<<LastName;
				cout<<"\n					Aadhar No. : "<<Aadhar;
				cout<<"\n					Birth Date : "<<Birthdate;
				cout<<"\n					Age 	   : "<<Age;
				cout<<"\n				----------------------------------------\n";
			}
		}
	}
	readfile.close();
}
int VotingSystem :: check(int ID)
{
	int NoID=1;
	IDFlag=-1;
	this->ID=ID;
	//To check If ID is Present in System Or Not
	ifstream checkID;
	checkID.open("SystemFile.txt",ios::in);
	if(!checkID)
	{
		cout<<"\n				   ------------ File Not Found ----------------";
	}
	while(!checkID.eof())
	{
		checkID>>VoterID;
		checkID>>Aadhar;
		checkID>>Age;
		checkID>>FirstName;
		checkID>>MiddleName;
		checkID>>LastName;
		checkID>>Birthdate;
		checkID>>Address;
		if(VoterID==ID)
		{
			NoID=0;
		}
	}
	checkID.close();
	return NoID;
}
int System()
{
	string SystemPass,Password;
	char Choice;
	// System Password For Election Commission
	SystemPass="Admin";
	VotingSystem *ptr=new VotingSystem;
	cout<<"\n	Enter System Password : ";
	cin>>Password;
	//If Password Matched :
	if(SystemPass==Password)
	{
	    system("cls");
		cout<<"	\n			~~~~~~~~ Welcome To Dindory, Maharashtra Assembly Constituency ~~~~~~~~\n ";
		
		do{
			cout<<"\n	Press 1 : To ADD NEW Voter \n	Press 2 : Delete Voter \n	Press 3 : To Display Voter Info \n	Press 0 : Exit";
			cout<<"\n	Enter System Choice  : ";
			cin>>Choice;
			switch(Choice)
			{
				case '1' :
					//To ADD NEW Voter
					system("cls");
					ptr->NewVoter();
					break;
				case '2' :
					//To Delete perticular Voter Details.
					system("cls");
					ptr->DeleteVoter();
					break;
				case '3' :
					//To display Voters and Details
					system("cls");
					ptr->DetailsDisplay();
					break;
				case '0' : //To Exit
				    system("cls");
					break;
				default :
					cout<<"\n					   -|-|-|-|-|-INVALID CHOICE!!-|-|-|-|-|-\n";
					break;
			}
		}while(Choice!='0');
	}
	//If Password Not Matched :
	else
	{
		cout<<"\n					   -|-|-|-|-|-Wrong Password!-|-|-|-|-|-\n";
	}
	return 0;
}
//Voting System
void Voting()
{
	char Vote;
	cout<<"\n	----------------------------------";
	cout<<"\n		Press A : BJP\n		Press B : CONGRESS\n		Press C : SHIVSENA\n		Press D : MNS";
	cout<<"\n		Enter Your VOTE : ";
	cin>>Vote;
	switch(Vote)
	{
		case 'A' :
			Candidate1++;
			break;
		case 'B' :
			Candidate2++;
			break;
		case 'C' :
			Candidate3++;
			break;
		case 'D' :
			Candidate4++;
			break;
		default:
			NOTA++;
			break;
	}
	cout<<"	----------------------------------";
	cout<<"\n					-|-|-|-|- Thank You For Voting -|-|-|-|- ";
	sleep(3);
    system("cls");
}
int CheckToVote()
{
	VotingSystem *ptr=new VotingSystem;
	int revote=-1,NoID=-1,ID;
	cout<<"\n	Enter Your Voter ID : ";
	cin>>ID;
	//To check ID present in System
	NoID=ptr->check(ID);
	//If ID found in System
	if(NoID==0)
	{
		//To Check if ID Person Already Voted
		for(int i=0;i<j;i++)
		{
			if(ID==VotedArray[i])
			{
				revote=0;
			}
		}
		//If ID Person Not Voted before
		if(revote!=0)
		{
			VotedArray[j]=ID; //To Store ID of Person Who is Going To Vote.
			j++;
			Voting(); //call Voting() Function To Vote.
			NoID=-1;
		}
		//If ID Person Voted Before
		else
		{
			cout<<"\n					-|-|-|-|-|- Not Allowed...!!-|-|-|-|-|-\n				   -|-|-|-|-|- You Have Already Voted -|-|-|-|-|-\n";
			NoID=-1;
		}
	}
	//If ID is Not found in System
	else
	{
		cout<<"\n					   Voter ID Not Found..!!\n					      You Can't Vote";
	}
	return 0;
}
//Result Of Election
void Result()
{
	cout<<"\n		********************************* Leading Party *********************************";
	//To Find Leading Candidate
    if(Candidate1>Candidate2 && Candidate1>Candidate3 && Candidate1>Candidate4)
    {
		cout<<"\n			 **************************** BJP : "<<Candidate1<<"  ****************************";
	}
    else if(Candidate2>Candidate1 && Candidate2>Candidate3 && Candidate2>Candidate4)
    {
		cout<<"\n			 **************************** CONGRESS : "<<Candidate2<<" ****************************";
	}
    else if(Candidate3>Candidate1 && Candidate3>Candidate2 && Candidate3>Candidate4)
    {
		cout<<"\n			 **************************** SHIVSENA : "<<Candidate3<<" ****************************";
	}
    else if(Candidate4>Candidate1 && Candidate4>Candidate2 && Candidate4>Candidate3)
    {
		cout<<"\n			 **************************** MNS : "<<Candidate4<<" ****************************";
	}
    else
		cout<<"\n				  **************** No-win situation ****************";
	//Vote Count of All Candidates.
	cout<<"\n\n	\t\t\t\t*********************************\n	\t\t\t\t\t  VOTE Count  \n ";
	cout<<"\n 		 \t\t\t\tBJP         : "<<Candidate1;
	cout<<"\n 		 \t\t\t\tCONGRESS    : "<<Candidate2;
	cout<<"\n 		 \t\t\t\tSHIVSENA    : "<<Candidate3;
	cout<<"\n 		 \t\t\t\tMNS  	    : "<<Candidate4;
	cout<<"\n  		\t\t\t\tNOTA 	    : "<<NOTA;
	cout<<"\n\n	\t\t\t\t*********************************\n";
}
int main()
{

	int ch;
	do{
		cout<<"\n Menu : \n Press '1' : Election Commission   \n Press '2' : Voter  \n Press '3' : Result\n Press '0' : Exit";
		cout<<"\n	Enter Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
				System();
				break;
			case 2 :
				CheckToVote();
				break;
			case 3 :
			    system("cls");
				Result();
				break;
			case 0:
			    system("cls");
				break;//exit
			default:
				cout<<"\n 					   Error : INVALID CHOICE..!!\n";
				system("cls");

				break;
		}
	}while(ch!=0);
	//To Display Final Result :
	cout<<"	\n			~~~~~~~~ Dindory, Maharashtra Assembly Constituency ~~~~~~~~\n				~~~~~~~~ Year 2022 Election Result ~~~~~~~~  ";
	cout<<"\n						Voting Done  :  "<<j;
	Result();
	return 0;
}
