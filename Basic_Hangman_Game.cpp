// The classic game of hangman
// Written by Moses Arocha

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{

char guess;				     // the guess the user makes
srand(static_cast<unsigned int>(time(0)));   // seeds the generation of the random number based on time
const string THE_WORD = words[0];            // word to guess
int wrong = 0;                               // number of incorrect guesses
string soFar(THE_WORD.size(), '-');          // word guessed so far
string used = "";                            // letters already guessed

// set-up, using vectors
const int MAX_WRONG = 9;  // maximum number of incorrect guesses allowed

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

vector<string> execution; // collection of man who hanged vector
execution.push_back(" ______ ");
execution.push_back(" |    | ");
execution.push_back(" |     ");
execution.push_back(" |     ");
execution.push_back(" |     ");
execution.push_back(" |     ");
execution.push_back("_|_    ");

vector<string>::iterator myIterator;
vector<string>::const_iterator iter;

random_shuffle(words.begin(), words.end()); // randomly shuffles the words to guess

//the beginning of what the user sees is here, the game begins here
cout << "\t Welcome To Wonderful Game of Hangman, Animal Theme Edition! \n\n\n";
cout << " Rules: Guess a series of letters in an attempt to guess the randomized animal. " << endl;

// main loop
while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
{
	for (unsigned int i = 0; i < execution.size(); ++i)
		{
			cout << "\n" << execution[i];
		}

        cout << "\n\n\t You have " << (MAX_WRONG - wrong);
	cout << " incorrect guesses left. Watch out! \n";
        cout << "\n Be Careful! You have already used these letters: \n" << used << endl;
        cout << "\n So far, the word is: \n" << soFar << endl;

      if (wrong != 8)
	  {
		cout << "\n\n Please, Enter your guess: ";
		cin >> guess; // no check all function, guess has to be a value already predicted
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

			if (wrong == 1)
			{
				execution[2] = " |    O ";
			}
		else if (wrong == 2)
			{
				execution[3] = " |    | ";
			}
		else if (wrong == 3)
			{
				execution[4] = " |    | ";
			}
		else if (wrong == 4)
			{
				execution[3] = " |   \\| ";
			}
		else if (wrong == 5)
			{
				execution[3] = " |   \\|/ ";
			}
		else if (wrong == 6)
			{
				execution[5] = " |   /   ";
			}
		else if (wrong == 7)
			{
				execution[5] = " |   / \\";
			}
		else if (wrong == 8)
			{
				execution[2] = " |    | ";
				execution[3] = " |    O ";
				execution[4] = " |   \|// ";
				execution[5] = " |    | ";
				execution[6] = " |   / \\";
			}
		} // end of else statement

	 } //end of outer if statement

  else if (wrong == 8)
  {
	  wrong++;
  }

	// shut down
	if (wrong == MAX_WRONG)
		{
			cout << "\n You've been died!";
			cout << "\n\n" << endl;
		}
	else
		{
			cout << "\n You guessed correctly! Good Job! ";
			//cout << "\n The word was " << THE_WORD << endl;
			cout << "\n\n" << endl;
		}
	
}

    return 0;
}
