#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>

class bank
{
char name[100],t;
int balance,amount;
int acno;
public:
void open_account();
void display_account();
void deposit_money();
void withdraw_money();
void create();
void dispfile();
void editrec();
void withd();
int retacno();
};


int bank::retacno()
{
return acno;
}
void bank::open_account()
{
cout<<"Enter the name of account holder: ";
cin.ignore();
cin.getline(name,100);
cout<<"enter acno";
cin>>acno;
cout<<"Do you want a savings or current account.Press s/c accordingly";
cin>>t;
cout<<"Enter your first deposit amount: ";
cin>>balance;
cout<<"Your account is created successfully" ;
}
void bank::display_account()
{
cout<<"Name of account holder: "<<name<<endl;
cout<<"Account ype: "<<t<<endl;
cout<<"Balance: "<<balance<<endl;
}
void bank::deposit_money()
{
int d;
cout<<"Enter the amount to be deposited: ";
cin>>d;
balance+=d;
cout<<"Total balance: "<<balance<<endl;
}
void bank::withdraw_money()
{
cout<<"Enter the amount to be withdrawed: ";
cin>>amount;
balance-=amount;
cout<<"Total Balance: "<<balance;
}
char rep;
bank b,b1;
fstream fs,temp;
void bank::create()
{
fs.open("acc.dat",ios::out|ios::binary);
do
{
b.open_account();
fs.write((char*)&b,sizeof(b));
cout<<"do you want to add more records";
cin>>rep;


}while(rep=='y'||rep=='Y');
fs.close();
}


void bank::dispfile()
{
fs.open("acc.dat",ios::in|ios::binary);
while(fs.read((char*)&b,sizeof(b)))
{
b.display_account();
}
fs.close();
}

void bank::editrec()
{
fs.open("acc.dat",ios::in|ios::binary);

int ac;
cout<<"enter account number";
cin>>ac;
while(fs.read((char*)&b1,sizeof(b1)))
{

if(b.retacno()==ac)
{
b.deposit_money();

}
}
fs.close();
}

void bank::withd()
{
fs.open("acc.dat",ios::in|ios::binary);

int a;
cout<<"enter account number";
cin>>a;
while(fs.read((char*)&b1,sizeof(b1)))
{

if(b.retacno()==a)
{
b.withdraw_money();

}
}
fs.close();
}
int main()
{
int choice,x,n;
bank obj;
do
{
clrscr();
cout<<"\t\t\t BANK MANAGEMENT SYSTEM";
cout<<"1.open_account"<<endl;
cout<<"2.display_account"<<endl;
cout<<"3.deposit_money"<<endl;
cout<<"4.withdraw_money"<<endl;
cout<<"5.Exit"<<endl;
cout<<"Please select an option from above";
cin>>choice;
switch(choice)
{
case 1:
cout<<"1.Open Account"<<endl;
obj.create();
break;
case 2:
cout<<"2.display_account"<<endl;
obj.dispfile();
break;
case 3:
cout<<"3.Deposit Money"<<endl;
obj.editrec();
break;
case 4:
cout<<"4.Withdraw Money"<<endl;
obj.withd();
break;
case 5:
cout<<"exit";
default:
cout<<"This is not exit.Please try again";
}
cout<<"Do you want to continue?Please type Y/N";
x=getch();
if(x=='n'||x=='N')
cout<<"exit";
}
while(x=='y'||x=='Y');
getch();
return 0;
}
