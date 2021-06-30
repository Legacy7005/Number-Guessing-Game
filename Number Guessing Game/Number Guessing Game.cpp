// Mr. Roboto


#include <iostream>

#include <stdio.h>

int main()
{
	int low = 0;
	int high = 0;
	int middle;
	char answer;

	int tries = 0;
	int lowGuess = low;
	int highGuess = high;

	int guess[100];
	int guessN;
	int i = 0;


	printf("  Guessing Game!\n  Help me guess your number.\n\n");

	printf("  Please enter your low bound \n");
	scanf_s("  %d", &low);

	printf("  Please enter your high bound \n");
	scanf_s("  %d", &high);

	printf("  Your low is %d and your high is %d \n\n", low, high);




	// While or low and high are not the same value run this.
	while (tries <= 2)
	{

		if (low <= high || answer == 'n' && tries <= 3)
		{
			middle = (high + low) / 2;
			guess[i] = middle;
			tries = tries + 1;


			printf("\n  Please enter m if your number is equal to %d \n", middle);
			printf("  Please enter g if your number is greater than %d \n", middle);
			printf("  Please enter s if your number is smaller than %d \n", middle);

			scanf_s(" %c", &answer);

		}


		if (answer == 'g')
		{
			low = middle;
			printf("  tries %d?\n", tries);

			for (i = 0; i < guess[i]; i++)
			{
				printf("  %d, ", guess[i]);
			}
		}

		if (answer == 's')
		{
			high = middle;
			printf("  tries %d?\n", tries);

			for (i = 0; i < guess[i]; i++)
			{
				printf("  %d,", guess[i]);
			}
		}

		// Call this function after 3 tries or if number is not middle/guessed.
		if (tries == 3 && answer != 'm')
		{
			lowGuess = low += 1;
			highGuess = high -= 1;
			//Guess between two numbers that have not yet been called
			guessN = (rand() % (highGuess - lowGuess + 1)) + lowGuess;

			printf("  I your number %d?\n", guessN);
			printf("  Type 'y' for yes 'n' for no.\n");
			scanf_s(" %c", &answer);
			tries = 0;
		}

		if (low == high || answer == 'm' || answer == 'y')
		{
			printf("  Great! Your number is %d?\n", middle);
			return 0;
		}
	}
}