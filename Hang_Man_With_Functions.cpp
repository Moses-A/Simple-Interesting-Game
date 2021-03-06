// The classic game of hangman
// Hang Man with functions
// Author is Moses Arocha

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int wrong = 0;  

char guess;

int gamePoints = 100;

const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed

vector<string> execution; // collection of man who hanged vector

void bodyFunction(int wrong, vector<string> execution);

void Game(vector<string> words, string soFar, const string THE_WORD, string used);

void welcome();

int main()
{
	
	vector<string> words;  // collection of possible words to guess
	words.push_back("ELEPHANT");
	words.push_back("GORILLA");
	words.push_back("SHEPHERD");
	words.push_back("PENGUIN");
	words.push_back("TORTOISE");
	words.push_back("ABYSSINIAN");
	words.push_back("ALLIGATOR");
	words.push_back("ANGELFISH");
	words.push_back("ANTEATER");
	words.push_back("ARMADILLO");
	words.push_back("AXOLOTL");
	words.push_back("JELLYFISH");
	words.push_back("RHINOCEROS");
	words.push_back("MEERKAT");
	words.push_back("HIPPOPOTAMUS");

	
	execution.push_back(" ______ ");
	execution.push_back(" |    | ");
	execution.push_back(" |     ");
	execution.push_back(" |     ");
	execution.push_back(" |     ");
	execution.push_back(" |     ");
	execution.push_back("_|_    ");



	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];            // word to guess
	string soFar(THE_WORD.size(), '-');          // word guessed so far
	string used = "";  

	welcome();

	Game(words, soFar, THE_WORD, used);

		

}

void Game(vector<string> words, string soFar, const string THE_WORD, string used) 
{
	
    // main loop
    while (wrong != MAX_WRONG)
    {
		bodyFunction(wrong, execution);
        cout << "\n\n\t You have " << (MAX_WRONG - wrong);
		cout << " incorrect guesses left. Watch out! \n";
        cout << "\n Be Careful! You have already used these letters: \n" << used << endl;
        cout << "\n So far, the word is: \n" << soFar << endl;

		cout << "\n\n Please, Enter your guess: ";
		cin >> guess;
		guess = toupper(guess); //make uppercase since secret word in uppercase
		while (used.find(guess) != string::npos)
			{
				cout << "\n My fault, this was already a previous answer: " << guess << endl;
				cout << " Please Enter A Guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

		used += guess;

		if (THE_WORD.find(guess) != string::npos)
		{
			cout << " Great Job! " << guess << " is in the word.\n";

			// update soFar to include newly guessed letter
			for (unsigned int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}

		else
		{
			cout << " Sorry, " << guess << " isn't in the word.\n";
			++wrong;
				
		}

		if (soFar == THE_WORD)
		{
			cout << "\n\n\n" << endl;
			cout << " You are horrible." << endl;

			gamePoints += THE_WORD.length();
			cout << " Your score is, " << gamePoints << endl;

			break;
		}

		else if (wrong == MAX_WRONG)
		{
			cout << "\n\n\n" << endl;
			cout << " You have lost." << endl;
			cout << " Your score is, " << gamePoints << endl;

		}
	  
	}

}
				
//function of body
void bodyFunction(int wrong, vector<string> execution)
{


			 if (wrong == 1)
				{
					execution[2] = " |    O ";
				}
			else if (wrong == 2)
				{
					execution[2] = " |    O ";
					execution[3] = " |    | ";
				}
			else if (wrong == 3)
				{
					execution[2] = " |    O ";
					execution[3] = " |    | ";
					execution[4] = " |    | ";
				}
			else if (wrong == 4)
				{
					execution[2] = " |    O ";
					execution[4] = " |    | ";
					execution[3] = " |   \\| ";
				}
			else if (wrong == 5)
				{
					execution[2] = " |    O ";
					execution[4] = " |    | ";
					execution[3] = " |   \\|/ ";
				}
			else if (wrong == 6)
				{
					execution[2] = " |    O ";
					execution[4] = " |    | ";
					execution[3] = " |   \\|/ ";
					execution[5] = " |   /   ";
				}
			else if (wrong == 7)
				{
					execution[2] = " |    O ";
					execution[4] = " |    | ";
					execution[3] = " |   \\|/ ";
					execution[5] = " |   / \\";
				}
			else if (wrong == 8)
				{
					execution[2] = " |    O ";
					execution[4] = " |    | ";
					execution[3] = " |   \\|/ ";
					execution[5] = " |   / \\";
				}	
			
			for (unsigned int i = 0; i < execution.size(); ++i)
			{
				cout << "\n" << execution[i];
			}
}

void welcome()
{
   cout << "\t Welcome To Wonderful Game of Hangman, Animal Theme Edition! \n\n\n";
   cout << " Rules: Guess a series of letters in an attempt to guess the randomized animal. " << endl;
}
