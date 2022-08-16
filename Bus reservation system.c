#include <iostream>
#include <cctype>
#include <string.h>
#include <utility>
#include <queue>
#include <conio.h>

using namespace std;
static int p = 0;
class Bus_Reservation
{
  protected:
    char busn[5];
    char driver[10];
    char arrival[5];
    char depart[5];
    char from[10];
    char to[10];
    char seat[8][4][10];
    string naam[8][4];
    char gen[8][4];
    int age[8][4];
    char ph[10];
    int tickn;
    char date[10];
    int tp;
	queue<pair<string, pair<char, int>>> Q;
	int qk;

  public:
    void add_bus();
    void reserve_bus();
    void empty();
    void show_bus();
    void is_bus_available();
    void position(int i);
    void cancellation();
    int is_avl(int a);
	void passenger_details();
}bus[10];

void Bus_Reservation::add_bus()                 // O(1) - constant time
{
  cout<<"Enter bus number: ";
  cin>>bus[p].busn;

  cout<<"Enter Driver's name: ";
  cin>>bus[p].driver;

  cout<<"Arrival time: ";
  cin>>bus[p].arrival;

  cout<<"Departure: ";
  cin>>bus[p].depart;

  cout<<"From: ";
  cin>>bus[p].from;

  cout<<"To: ";
  cin>>bus[p].to;

  cout<<"Ticket fare: ";
  cin>>bus[p].tp;
  cout<<"Enter date (in dd.mm.yyyy format)"<<endl;
  cin>>bus[p].date;
  cout<<"\n Added Successfully....\n";

  bus[p].empty();
  p++;

  getch();
}

void Bus_Reservation::is_bus_available() // O(n)
{
	for (int n = 0; n < p; n++)
	{
		cout << "\n--------------------------------------------\n";
		cout << "Bus number: " << bus[n].busn << "\nDriver: " << bus[n].driver
			 << "\nArrival time: " << bus[n].arrival << "\nDeparture Time: "
			 << bus[n].depart << "\nFrom: " << bus[n].from << "\nTo: "
			 << bus[n].to;
		cout << "\n--------------------------------------------\n";
	}
	getch();
}

int Bus_Reservation::is_avl(int l)
{
	int k = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (strcmp(bus[l].seat[i][j], "AV") == 0)
				k++;
		}
	}
	return k;
}

void Bus_Reservation::reserve_bus()                   // O(m*n)
{
	int seat;
	char number[5];
	top:
	cout<<"Bus Number: ";
	cin>>number;
	cout<<"number of passengers: ";
	cin>>tickn;
	// cout<<"Phone number"<<endl;
	// cin>>ph;
	int n,temp;
	temp=tickn;
	bool found = false;
	for (n = 0; n <= p; n++)
	{
		if (strcmp(bus[n].busn, number) == 0) {
			found = true;
			break;
		}
	}
	
	if (found) {
		int a = bus[0].is_avl(n);

		if (a >= tickn)
		{
			while (temp--)
			{
				for (n = 0; n <= p; n++)
				{
					if (strcmp(bus[n].busn, number) == 0)
						break;
				}
				while (n <= p)
				{
					cout << "\nSeat Number: ";
					cin >> seat;
					if (seat > 32)
					{
						cout << "\nThere are only 32 seats available in this bus.";
					}
					else
					{
						if (strcmp(bus[n].seat[seat / 4][(seat % 4) - 1], "AV") == 0)
						{
							cout << "Enter passenger's name: ";
							cin >> bus[n].naam[seat / 4][(seat % 4) - 1];
							cout << "Gender (M/F): ";
							cin >> bus[n].gen[seat / 4][(seat % 4) - 1];

							cout << "Age: ";
							cin >> bus[n].age[seat / 4][(seat % 4) - 1];
							strcpy(bus[n].seat[seat / 4][(seat % 4) - 1], "NA");
							break;
						}
						else
							cout << "The seat is already reserved.\n";
					}
				}

				if (n > p)
				{
					cout << "Enter correct bus no.\n";
					goto top;
				}
			}
			cout << "Reservation done successfully. :)" << endl << endl;
			cout << "Price to be paid: Rs." << bus[n].tp*tickn << "/-" << endl << endl;
			cout << "**PLEASE REPORT 20 MINS BEFORE THE TIME OF ARRIVAL" << endl;
		}
		else
		{
			if (a)
			{
				cout << "This bus currently has only " << a << " seats left" << endl;
				goto top;
			}
			else
			{
				cout << endl << "This bus is currently full" << endl;
				cout << "Do you want to proceed for waiting list reservation ? (y/n)" << endl;
				char ch;
				cin >> ch;
				ch = tolower(ch);
				if (ch == 'y')
				{
					while (temp--)
					{
						pair<char, int> p2;
						pair<string, pair<char, int>> p1;
						string name, gender;
						int age;
						cout << "Enter passenger's name: ";
						cin >> p1.first;
						cout << "Gender (M/F): ";
						cin >> p2.first;
						cout << "Age: ";
						cin >> p2.second;
						p1.second = p2;
						bus[n].Q.push(p1);
					}
				}
			}
		}
	}
	else {
		cout << "Enter correct bus number" << endl;
		goto top;
	}
	
}

void Bus_Reservation::empty()                         // constant time - O(1)
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "AV");
    }
  }
}

void Bus_Reservation::show_bus()                      // O(n)
{
	int n;
  	char number[5];
  	cout<<"Enter bus number: ";
  	cin>>number;
  	for(n=0;n<=p;n++)
  	{
    	if(strcmp(bus[n].busn, number)==0)
    	break;
  	}
  	while(n<=p)
  	{
		  cout << "\n--------------------------------------------\n";
		  cout << "Bus no: " << bus[n].busn << endl;
		  cout << "Driver: " << bus[n].driver << endl;
		  cout << "Arrival time: " << bus[n].arrival;
		  cout << "\nDeparture time: " << bus[n].depart;
		  cout << "\nFrom: " << bus[n].from;
		  cout << "\nTo: " << bus[n].to << "\n";
		  cout << "\n--------------------------------------------\n";
		  bus[0].position(n);
    break;
	}

	if(n>p)
    cout<<"Enter correct bus no: ";

	getch();
}

void Bus_Reservation::position(int l)               // O(1)
{
  int s=0, pp=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0; j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j],"AV")==0)
      {
        cout.width(5);
        cout.fill(' ');
        if(s>9)
          cout << "|" << s << "|" << ".";
        else
          cout << "|" << s << "_|" << ".";
        cout.width(5);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        pp++;
      }
      else
      {
        cout.width(5);
        cout.fill(' ');
		if (s > 9)
			cout << "|" << s << "|" << ".";
		else
			cout << "|" << s << "_|" << ".";
		cout.width(5);
        cout.fill(' ');
        cout<<"NA";
      }
    }
  }
  cout << "\n*AV means available" << endl << "*NA means not available" << endl;
  cout << "\n\nThere are "<< pp << " seats empty in Bus Number: " << bus[l].busn;
}

void Bus_Reservation::passenger_details()
{
	int seat;
	char number[5];
	cout << "Bus Number: ";
	cin >> number;
	int n;
	bool found = false;
	for (n = 0; n <= p; n++)
	{
		if (strcmp(bus[n].busn, number) == 0) {
			found = true;
			break;
		}
	}

	if (found) {
		cout << "\n--Seat No.--\t--Name--\t--Gender--\t--Age--\n";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (strcmp(bus[n].seat[i][j], "AV") != 0)
					cout << "    " << (4 * i + j + 1) << "\t\t" << bus[n].naam[i][j] << "\t\t    " << bus[n].gen[i][j] << "\t\t   " << bus[n].age[i][j] << endl;
			}
		}

		queue<pair<string, pair<char, int>>> tmp_q = bus[n].Q;
		int k = 0;
		if (!tmp_q.empty()) {
			while (!tmp_q.empty())
			{
				cout << "Waiting-" << ++k << "\t" << tmp_q.front().first << "\t\t    " << tmp_q.front().second.first << "\t\t   " << tmp_q.front().second.second << "\n";
				tmp_q.pop();
			}
		}
	}
	else {
		cout << "This bus number does not exist" << endl;
	}
}

void Bus_Reservation::cancellation() {
	int seat;
	char number[5];
	cout << "Bus Number: ";
	cin >> number;
	cout << "No. of tickets to be cancelled: ";
	cin >> tickn;
	int n, temp = tickn;
	for (n = 0; n <= p; n++)
	{
		if (strcmp(bus[n].busn, number) == 0)
			break;
	}
		while (temp--) {
			top1:
			cout << "\nEnter seat number to be cancelled: ";
			cin >> seat;
			if (seat > 32)
			{
				cout << "\nThere are only 32 seats available in this bus.";
			}
			else
			{
				if (strcmp(bus[n].seat[seat / 4][(seat % 4) - 1], "NA") == 0)
				{
					cout << "The seat number to be deleted is: " << seat << endl;
					cout << "Passenger: " << bus[n].naam[seat / 4][(seat % 4) - 1] << ", " << bus[n].gen[seat / 4][(seat % 4) - 1] << ", " << bus[n].age[seat / 4][(seat % 4) - 1] << endl;
					cout << "Do you want to proceed ? [y/n]" << endl;
					char ch1;
					cin >> ch1;
					ch1 = tolower(ch1);
					if (ch1 == 'y')
					{
						if (!bus[n].Q.empty()) {
							string namee = bus[n].Q.front().first;
							char gender = bus[n].Q.front().second.first;
							int agee = bus[n].Q.front().second.second;
							bus[n].naam[seat / 4][(seat % 4) - 1] = namee;
							bus[n].gen[seat / 4][(seat % 4) - 1] = gender;
							bus[n].age[seat / 4][(seat % 4) - 1] = agee;
							bus[n].Q.pop();
						}
						else {
							strcpy(bus[n].seat[seat / 4][(seat % 4) - 1], "AV");
							bus[n].naam[seat / 4][(seat % 4) - 1] = "";
							bus[n].gen[seat / 4][(seat % 4) - 1] = ' ';
							bus[n].age[seat / 4][(seat % 4) - 1] = -1;
						}
						
						cout << "Ticket cancelled successfully :)" << endl;
					}
					else {
						goto top1;
					}
				}
				else {
					cout << "This seat is unreserved so far.\n";
					goto top1;
				}
			}
		}
}

int main() {
	Bus_Reservation ob;
	int w;

	cout<<"Welcome to Simulation of bus reservation system...\n";
	do{
		cout << "\n1. Add Bus\n";
		cout << "2. Buses Available\n";
		cout << "3. Check seat availability\n";
		cout << "4. Reservation \n";
		cout << "5. Passenger Details \n";
		cout << "6. Cancellation \n";
		cout << "7. Exit";

		cout << "\n\n\tEnter your choice:-> ";
		cin >> w;
		switch (w)
		{
			case 1: bus[p].add_bus();
					break;
			case 3:	bus[0].show_bus();
					break;
			case 2:	bus[0].is_bus_available();
					break;
			case 4:	bus[p].reserve_bus();
					break;
			case 5:	bus[0].passenger_details();
					break;
			case 6:	bus[0].cancellation();
					break;
			case 7:	cout << "exiting......\n";
					break;
		}
	} while (w != 7);
	getch();
	return 0;
}