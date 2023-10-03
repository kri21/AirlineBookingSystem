#include<iostream>
#include<fstream>
#include<process.h>
#include<conio.h>
using namespace std;

class Airline
{
	private:
		int pass,tamt,seatno,cseat;
		char seat[50],to[100],from[100],pname[100],date[100];
	public:
		void input()
		{
			cout<<"\nPassenger's name: ";
			cin>>pname;
			cout<<"\nDeparture city(Ahmedabad/Mumbai/Goa): ";
			cin>>from;
			cout<<"\nArrival city(Ahmedabad/Mumbai/Goa): ";
			cin>>to;
			cout<<"\nDate:";
			cin>>date;	
			cout<<"\nHow many no.of passengers?\n>>  ";
			cin>>pass;
			if(strcmpi(from,"Mumbai")==0)
			{
				if(strcmpi(to,"Goa")==0)
				{
					tamt=pass*9788;
				}
				else if(strcmpi(to,"Ahmedabad")==0)
				{
					tamt=pass*9121;
				}
			}
			else if(strcmpi(to,"Goa")==0)
			{
				if(strcmpi(to,"Ahmedabad")==0)
				{
					tamt=pass*9410;
				}
				else if(strcmpi(to,"Mumbai")==0)
				{
					tamt=pass*6729;
				}
			}
			else if(strcmpi(from,"Ahmedabad")==0)
			{
				if(strcmpi(to,"Mumbai")==0)
				{
					tamt=pass*4559;
				}
				else if(strcmpi(to,"Goa")==0)
				{
					tamt=pass*7894;
				}
			}
		}
		void display()
		{
			cout<<"\n\n****Successfully booked****";
			cout<<"Passenger's name: "<<pname;
			cout<<"\nDeparture city: "<<from;
			cout<<"\nArrival city: "<<to;
			cout<<"\nDeparture date: "<<date;
			cout<<"\nPassengers: "<<pass;
			cout<<"\n************************";
			cout<<"\nTotal amount: "<<tamt;
			cout<<"\n************************"; 
		}
		int getn(char searchn[])
		{
			if(strcmp(pname,searchn)==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
};

Airline ar;
fstream f;

void booking()
{
	f.open("AirlineBookingSystem.dat",ios::binary|ios::app);
	ar.input();
	f.write((char*)&ar,sizeof(ar));
	f.close();
}

void display1()
{
	f.open("AirlineBookingSystem.dat",ios::binary|ios::app);
	while(f.read((char*)&ar,sizeof(ar)))
	{
		ar.display();
	}
	f.close();
}

void cancellation()
{
	char searchn[100];
	fstream fout;
	cout<<"\nEnter name you want to search: ";
	cin>>searchn;
	f.open("AirlineBookingSystem.dat",ios::binary|ios::in);
	fout.open("Airline.dat",ios::binary|ios::app);
	while(f.read((char*)&ar,sizeof(ar)))
	{
		if(ar.getn(searchn)==1)
		{
			cout<<"\nTickets cancelled";
		}
		else
		{
			fout.write((char*)&ar,sizeof(ar));
		}
	}
	f.close();
	fout.close();
	remove("AirlineBookingSystem.dat");
	rename("Airline.dat","AirlineBookingSystem");
	
}

int main()
{
	system("cls");
	int ch;
	while(1)
	{
		cout<<"\n1.Booking";
		cout<<"\n2.Display";
		cout<<"\n3.Cancellation";
		cout<<"\n4.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: booking();break;
			case 2: display1();break;
			case 3: cancellation();break;
			case 4: exit(0);break;
		}
	}
}