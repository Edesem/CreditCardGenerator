#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
    // Declaring variables
    long long card;
    int sum;
	int input;
	int a;
	int tries = 0;

    //Position ...
    long p1 = 10;
    long p2 = pow(10, 3);
    long p3 = pow(10, 5);
    long p4 = pow(10, 7);
    long p5 = pow(10, 9);
    long p6 = pow(10, 11);
    long p7 = pow(10, 13);
    long p8 = pow(10, 15);

    //Position Remainder ...
    long pr2 = pow(10, 2);
    long pr3 = pow(10, 4);
    long pr4 = pow(10, 6);
    long pr5 = pow(10, 8);
    long pr6 = pow(10, 10);
    long pr7 = pow(10, 12);
    long pr8 = pow(10, 14);

    //Digit ...
    long d1, d2, d3, d4, d5, d6, d7, d8;

    //Digit remainder ...
    long dr1, dr2, dr3, dr4, dr5, dr6, dr7, dr8;

    //Digit Extra ...
    int de1, de2, de3, de4, de5, de6, de7, de8;

    //Digit Extra Pair ... PAIRED WITH ABOVE VARIABLE
    int dep1, dep2, dep3, dep4, dep5, dep6, dep7, dep8;

    //Ask for which card type it would like to generate
	do
	{
		input = get_int("AMEX, MASTERCARD, or VISA? (1, 2, 3)");
	}
	while(input < 0 || input > 3);


    //This is the rand() function seed, basically makes it generate a different random number each time
    srand(time(NULL));

    do
    {
        //This resets the variables for each loop, to make sure it doesnt affect calculations for the sum variable
        dep1 = dep2 = dep3 = dep4 = dep5 = dep6 = dep7 = dep8 = 0;
        de1 = de2 = de3 = de4 = de5 = de6 = de7 = de8 = 0;

        //Selection from user selecting either AMEX MASTERCARD or VISA
        //AMEX selection
        if (input == 1)
	    {

	        //This is setup as AMEX can begin with either 34 or 37 so it randomlly picks between the two
	        a = rand() % 2;
	        if (a == 1)
	        {
	            card = ((rand() % (349999999999999 - 340000000000000 + 1)) + 340000000000000);
	        }

	        else
	        {
	            card = ((rand() % (379999999999999 - 370000000000000 + 1)) + 370000000000000);
	        }

	    }

        // MASTERCARD selection
	    if (input == 2)
	    {
		    card = ((rand() % (5599999999999999 - 5100000000000000 + 1)) + 5100000000000000);
	    }

        // VISA selection
	    if (input == 3)
	    {
	        //Same thing as the amex one but instead for 13 or 16 digit numbers
		    a = rand() % 2;
	        if (a == 1)
	        {
	            card = ((rand() % (4999999999999 - 4000000000000 + 1)) + 4000000000000);
	        }

	        else
	        {
	            card = ((rand() % (4999999999999999 - 4000000000000000 + 1)) + 4000000000000000);
	        }
	    }

		//printf("\rRUN: %lli", run);

        //Luhn's algorithm
        //AMEX 15 digit
        if ((card >= 5100000000000000 && card <= 5599999999999999) ||
        (card >= 340000000000000 && card <= 349999999999999) ||
        (card >= 370000000000000 && card <= 379999999999999) ||
        (card >= 4000000000000 && card <= 4999999999999) ||
        (card >= 4000000000000000 && card <= 4999999999999999))
        {
            //Obtaining digit of each position
            d1 = card / p1;
            d1 = d1 % 10;

            d2 = card / p2;
            d2 = d2 % 10;

            d3 = card / p3;
            d3 = d3 % 10;

            d4 = card / p4;
            d4 = d4 % 10;

            d5 = card / p5;
            d5 = d5 % 10;

            d6 = card / p6;
            d6 = d6 % 10;

            d7 = card / p7;
            d7 = d7 % 10;

            d8 = card / p8;
            d8 = d8 % 10;

            //Same thing here except that this is the digits that won't be doubled
            dr1 = card % 10;

            dr2 = card / pr2;
            dr2 = dr2 % 10;

            dr3 = card / pr3;
            dr3 = dr3 % 10;

            dr4 = card / pr4;
            dr4 = dr4 % 10;

            dr5 = card / pr5;
            dr5 = dr5 % 10;

            dr6 = card / pr6;
            dr6 = dr6 % 10;

            dr7 = card / pr7;
            dr7 = dr7 % 10;

            dr8 = card / pr8;
            dr8 = dr8 % 10;

            //Doubling of the original digits
            d1 = 2 * d1;
            d2 = 2 * d2;
            d3 = 2 * d3;
            d4 = 2 * d4;
            d5 = 2 * d5;
            d6 = 2 * d6;
            d7 = 2 * d7;
            d8 = 2 * d8;

            //This section is to split apart digits that are >= 10
            if (d1 >= 10)
            {
                de1 = d1 % 10;
                d1 = d1 / 10;
                dep1 = d1 % 10;
                d1 = 0;
            }

            if (d2 >= 10)
            {
                de2 = d2 % 10;
                d2 = d2 / 10;
                dep2 = d2 % 10;
                d2 = 0;
            }

            if (d3 >= 10)
            {
                de3 = d3 % 10;
                d3 = d3 / 10;
                dep3 = d3 % 10;
                d3 = 0;
            }

            if (d4 >= 10)
            {
                de4 = d4 % 10;
                d4 = d4 / 10;
                dep4 = d4 % 10;
                d4 = 0;
            }

            if (d5 >= 10)
            {
                de5 = d5 % 10;
                d5 = d5 / 10;
                dep5 = d5 % 10;
                d5 = 0;
            }

            if (d6 >= 10)
            {
                de6 = d6 % 10;
                d6 = d6 / 10;
                dep6 = d6 % 10;
                d6 = 0;
            }

            if (d7 >= 10)
            {
                de7 = d7 % 10;
                d7 = d7 / 10;
                dep7 = d7 % 10;
                d7 = 0;
            }

            if (d8 >= 10)
            {
                de8 = d8 % 10;
                d8 = d8 / 10;
                dep8 = d8 % 10;
                d8 = 0;
            }

            // Final total count of everything
            sum = (d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 +
                de1 + de2 + de3 + de4 + de5 + de6 + de7 + de8 +
                dep1 + dep2 + dep3 + dep4 + dep5 + dep6 + dep7 + dep8 +
                dr1 + dr2 + dr3 + dr4 + dr5 + dr6 + dr7 + dr8);

            //Verification to see if the sum's last digit == 0
            if (sum % 10 == 0)
            {
                printf("CARD: %lli \nVALID\n", card);
            }
        }
        tries++;
    }
    while(sum % 10 != 0);

    // prints out total amount of attempts to generate
    printf("It took %i tries\n", tries);
}