#include <iostream>
#include <limits>

using ll = long long;

void ignoreLine() // Clears the input buffer.
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Clears bad input and returns true if the input was invalid.
bool clearInput()
{
	if (!std::cin)
	{
		std::cin.clear();
		ignoreLine();
		return true;
	}
	return false;
}

// Prompts the user to enter a positive number and validates the input.
ll getInput()
{
	ll x{};
	while (true)
	{
		std::cout << "Enter a positive number: ";
		std::cin >> x;

		if (clearInput() || x <= 0) // If the wrong input is found, ask for it again.
		{
			std::cerr << "Wrong input, try again.\n";
			continue;
		}

		ignoreLine();
		return x;
	}

}


// Calculates the Greatest Common Divisor (GCD) using the Euclidean algorithm.
ll calcGCD(std::pair< ll, ll > pair)
{
	while ( pair.second != 0 )
	{
		ll rem{ pair.first % pair.second };
		std::swap( pair.first, pair.second );
		pair.second = rem;
	}
	return pair.first;
}


// Calculates the Least Common Multiple (LCM).
ll calcLCM(std::pair< ll, ll >& pair)
{
	return (pair.first * pair.second) / calcGCD(pair);
}


char getChoice()
{

	char input{};

	while (true)
	{
		std::cout << "What do you want to calculate?\n";
		std::cout << "1) GCD\n";
		std::cout << "2) LCM\n";
		std::cout << "3) Both\n";
		std::cout << "4) Quit\n";

		std::cin >> input;
		if (clearInput() || input > '4' || input < '1') // If wrong input found.
		{
			std::cerr << "Wrong input, try again.\n";
			continue;
		}

		ignoreLine(); // Clears the buffer.

		return input;

	}


}

bool printOutput(char choice, std::pair< ll, ll >& pair)
{
	switch (choice) // It returns false if the program should exit; otherwise, it returns true.
	{
	case '1': // GCD
		std::cout << "GCD = " << calcGCD(pair) << '\n';
		std::cout << '\n';
		return true;

	case '2': // LCM
		std::cout << "LCM = " << calcLCM(pair) << '\n';
		std::cout << '\n';
		return true;
	case '3': // Both
	{
		ll gcd{ calcGCD(pair) };

		std::cout << "GCD = " << gcd << '\n';
		std::cout << "LCM = " << (pair.first * pair.second) / gcd << '\n'; // Reuse gcd to avoid recalculating
		std::cout << '\n';
		return true;
	}
	default: // Unexpected error
		std::cerr << "Unexpected error occurred.\n";
		return false;

	}
}



int main()
{
	while (true)
	{
		char choice{ getChoice() };
		if (choice == '4') // Quit
		{
			std::cout << "Exiting...\n";
			break;
		}

		std::pair< ll, ll > pair(getInput(), getInput());

		if (!printOutput(choice, pair))
		{
			break;
		}

	}

	return 0;

}
