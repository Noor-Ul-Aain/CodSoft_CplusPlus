#include<iostream>
using namespace std;

void numberGuesser();

int main()
{
	char choice = ' ';

	while (1)
	{
		numberGuesser();
		cout << "Do you want to play again?\nPress 'y' or 'Y' for YES and 'n' or 'N' for NO" << endl;
		cin >> choice;
		cout << endl;

		if (choice == 'y' || choice == 'Y')
		{
			system("cls");
			continue;
		}

		if (choice == 'n' || choice == 'N')
		{
			break;
		}

		else
		{
			cout << "Wrong input!!!\nEnter again" << endl;
			cin >> choice;
			cout << endl;
			system("cls");
		}
	}

	return 0;
}

void numberGuesser()
{

	cout << "________________________ Welcome to the Number Guessing Game ________________________\n\n";

	int randomNumber = 0, guessNumber = 0, guessAttempts = 1, count = 0;

	cout << "Specify the maximum number for your guessing game: ";
	cin >> count;

	srand(time(0));
	randomNumber = (rand() % count) + 1;
	while (guessNumber != randomNumber)
	{
		cout << "Enter your guessed number: ";
		cin >> guessNumber;

		if (guessNumber > randomNumber)
		{
			guessAttempts++;
			cout << "The guessed number exceeds the actual number!!!\nTry guessing a lower number!!!" << endl << endl;
		}

		else if (guessNumber < randomNumber)
		{
			guessAttempts++;
			cout << "The guessed number is below the actual number!!!\nTry guessing a higher number!!!" << endl << endl;
		}
		else
			cout << "Congatulations!!!\nYou guessed the correct number on " << guessAttempts << "th attempts!" << endl << endl;
	}
}
