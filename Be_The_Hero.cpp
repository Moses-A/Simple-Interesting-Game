// Hero's Inventory 2.0
// Demonstrates vectors
// Written by Moses Arocha

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;

int main()
{

string OwnerName;
string StoreName;
string inventoryChange;
string inventoryReplace2;
string BirthPlace;
char userResponse;
char TeachStaff;
char serveCustomer;
char ownerResponse;
int score = 50;

// Beginning of Random Number Generator
int secretNumber = 0;
int secretNumbers = 0;

//Beginning of Vector
vector<string> inventory;
inventory.push_back("Espresso");
inventory.push_back("Espresso Macchiato");
inventory.push_back("Espresso con Panna");
inventory.push_back("Caffe Latte");
inventory.push_back("Flat White");
inventory.push_back("Cafe Breve");
inventory.push_back("Cappuccino");
inventory.push_back("Caffe Mocha");
inventory.push_back("Americano");

// Random Number Generator
	srand(static_cast<unsigned int>(time(0)));  //seed random number generator
	secretNumber = rand() % 10 + 1;         // random number between 1 and 10
	int tries = 0;
	int prediction;

	//Introduction of User and Store Name

	cout << "\t\t\tWelcome To The Coffee Shop Game!" << endl;
	cout << "\n\n Rules: Well, this is game. And in order for us to stay in business, each night    You need at least 50 points. Good Luck!" << endl;
	cout << "\n\n 'Oh thank goodness, I thought no one would purchase the store.' - Manager " << endl;
	cout << "\n Thankfully you are here, what is your name by the way? ";
	getline (cin, OwnerName);
	cout << "\n " << OwnerName << ", wow, what a nice name. Well you are our new owner, so welcome!" << endl;
	cout << "\n\n First things first, for the paper work, What is the stores new name? \n\t\t";
	getline (cin, StoreName);
	cout << "\n Sounds great, I think. Anyways here is the menu. " << endl;

	cout << "\n\n Your menu has " << inventory.size() << " items." << endl;;
	cout << "\n The items on the Menu are: \n";
	for (unsigned int i = 0; i < inventory.size(); ++i)
	{
		cout << "\t" << inventory[i] << endl;
	}

//Body of Game

int BriefReset;
do {
	cout << "\n I bet you know a thing or two. Would you like to teach us? [Y/N] ";
	cin >> TeachStaff;
	TeachStaff = toupper(TeachStaff);

		if ( TeachStaff == 'Y' )
		{
			BriefReset = 0;
			cout << "\n As you walk over to the counter, you see milk and cream.\n";

			cout << "\n Would You like to teach your crew about Iced Coffee? [Y/N] ";
			cin >> userResponse;
			userResponse = toupper(userResponse);
		
			if (userResponse == 'Y')
			{
				inventory.push_back("Iced coffee");
				cout << "\n\n Your New Menu Items:\n";
				score = score +50;
				 for (unsigned int i = 0; i < inventory.size(); ++i)
					{
						cout << "\t" << inventory[i] << endl;
					}
			}

			else if (userResponse == 'N')
			{
				cout << "\n You have choosen wrongly, you have lost 50 points.";
				cout << "\n You have passed on a very important technique." << endl;
				score = score -50;
			}
			else
			{
			cout << "\n This is not a proper choice. choose again. " << endl;
			}
			
		}

	else if (TeachStaff == 'N')
		{
			BriefReset = 0;
			cout << "\n You have choosen wrongly, you have lost 50 points.\n";
			cout << " You have passed on a very important learning method." << endl;
			score = score -50;
	
		}
	else
		{
			cout << "\n\n You did not choose a proper choice, try again." << endl;
			BriefReset = 1;
		}
		cout << "\n\n";

} while (BriefReset !=0);

int BriefReset2;
do {
	cin.ignore();
	cout << "\n\t Here comes our first customer prepare yourself!" << endl;
	cout << "\n Would you like to serve the customer? [Y/N] " ;
	cin >> serveCustomer;
	serveCustomer = toupper(serveCustomer);
	
	if ( serveCustomer == 'Y')
	{
		BriefReset2 = 0;
		if  ( userResponse == 'Y')
		{
			cout << "\n Amazingly, they ask for Iced Coffee!\n";
			cout << "\n You have made an amazing cup. They tipped you $1.00. " << endl;
			score = score + 1;
		}
			
		else if (userResponse == 'N')
		{
			cout << "\n Amzingly, they asked, for Iced Coffe. \n ";
			cout << "\n You have not made the cup, you have lost business. " << endl;
			score = score -3;
		}
		
		cout << "\n Even though you just started, another customer arrives. \n Do you continue? [Y/N] ";
		cin >> ownerResponse;
		ownerResponse = toupper(ownerResponse);

		if (ownerResponse == 'Y')
		{
			cout << "\n Great, let us continue. Guess a number between 1 and 10.\n" << endl;
		
			do
			{
				cout << "  Enter a prediction: ";
				cin >> prediction;
				++tries;

				if (prediction > secretNumber)
				{
					cout << "\t\t\t Too high!\n\n";
				}
				
				else if (prediction < secretNumber)
				{
					cout << "\t\t\t Too low!\n\n";
				}
				
				else
				{
					cout << "\n\t\tThat's it! " << endl;
					score = score + 10;
				}

			} while (prediction != secretNumber);

			cout << "\n You served " << tries << " customers, hopefully you can better later. " << endl;
			cin.ignore();

			cout << "\n 'Hmm. It seems our menu is lacking items, lets add more stuff! ' - Manager" << endl;
			cout << "\n What would you like to add? ";
			std:: getline (std:: cin, inventoryReplace2);
			inventory.push_back(inventoryReplace2);
			cout << "\n\n " << inventoryReplace2 <<  " has been added yeah!" << endl;
			score = score + 10;
			cout << "\n\n Your New Menu List:\n";
			score = score +5;
			 for (unsigned int i = 0; i < inventory.size(); ++i)
				{
					cout << "\t" << inventory[i] << endl;
				}
		}

			 else if (ownerResponse == 'N')
			{
				cout << "\n You have choosen wrongly, we have lost business.";
				cout << "\n You have passed on a very important business opportunities." << endl;
				score = score -20;
			}
	}

	else if (serveCustomer == 'N')
	{
		BriefReset2 = 0;
		cout << "\nYou have choosen wrongly, you have lost 25 points.\n";
		cout << " You have passed on a very important task." << endl;
		score = score -25;

	}
	
	else
	{
		cout << "\n\n You did not choose a proper choice, try again." << endl;
		BriefReset2 = 1;
	}
	
	cout << "\n";

} while (BriefReset2 !=0);

// Continuation of Game Play
	cin.ignore();
	cout << " 'Oh no, we are running out of coffee, quickly get rid of something!' - Manager " << endl;
	cout << "\n What would you like to replace with Espresso? ";
	getline (cin, inventoryChange);
	inventory[0] = (inventoryChange);

	cout << "\n Your New Menu Items: \n";
	for (unsigned int i = 0; i < inventory.size(); ++i)
	{
		cout << "\t" << inventory[i] << endl;
	}

	cout << "\n'Hopefully this new menu will due. Until we buy more coffee anyways.' - Manager " << endl;

	score = score + inventory[0].size();
	cout << " You are doing decent, you have a score of, " << score << endl;

	cout << "\n\n Let's continue with the story the next day..." << endl;
	score = score + inventory[3].size();;
	cin.ignore();

// Items in program disappear

	cout << "\n Many customers walk in throughout the day. Thankfully, you are in a great mood." << endl;
	cout << " However, a man by the name of " << OwnerName << " walks in and gets you angry. " << endl;
	cout << " You decided the best punishment would be to not make him coffee. " << endl;

	inventory.pop_back();
	cout << "\n You new list of items are:\n";
	for (unsigned int i = 0; i < inventory.size(); ++i)
	{
		cout << "\t" << inventory[i] << endl;
	}

	cout << "\n Soon more customers enter, before you know it, the time is: "; 
	auto t = time(nullptr); 
	auto tm = *localtime(&t); 
	cout << put_time(&tm, "%m/%d/%Y %H:%M") << endl;

	cout << "\n As you freak out how time has passed by so fast, you look up and see everyone   has left. \n" << endl;
	cout << "\n But then the manager walks up to you and starts a conversation. " << endl;
	cout << " 'Hey tell me about yourself? Are you from this area? ' - Manager  ";
	getline (cin, BirthPlace);

	cout << "\n\n But oh no wait! In the middle of your conversation, " << endl;
	cout << " A hoodied man holds up a gun and asks for all your money.";
	cout << "\n You give him all the money in the cash register, but he doesn't leave.";
	cout << "\n He demands all of your supplies, so you give it to him to save your life.";
	inventory.pop_back();

	cout << "\n\n You were robbed of all of your possessions by the hooded man.";
	inventory.clear();
	if (inventory.empty())
	{
		cout << "\n\n\n\t You have Nothing....\n\t Tomorrow we will start new. Good Luck!\n";
		score = score - 10;
		cout << "\n Your Final Score is ... " << score << " did you survive? \n\n" << endl;
	}
	else
	{
		cout << "\n\n You have at least one item.\n";
	}

return 0;
}
