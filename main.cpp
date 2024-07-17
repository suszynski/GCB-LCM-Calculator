#include <iostream>
#include <limits>


void ignoreLine() // Clears the buffer.
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearInput()  // Returns true if the wrong input is found; otherwise, it returns false.
{
	if (!std::cin)
	{
		std::cin.clear();
		ignoreLine();
		std::cout << "Wrong input, try again.\n";
		return true;
	}
	return false;
}

long getInput()
{
	long x{};
	while (true)
	{
		std::cout << "Enter a positive number: ";
		std::cin >> x;

		if (clearInput()) // If the wrong input is found, ask for it again.
		{
			continue;
		}

		else if (x <= 0) // Checks if the number is positive.
		{
			std::cout << "Wrong input, try again.\n";
			continue;
		}
		ignoreLine(); // Clears the buffer.
		return x;
	}

}



long calcGCD(std::pair<long, long> pair)
{
	while (pair.second != 0) // Using the Euclidean division algorithm to calculate the greatest common divisor.
	{
		int rem{ pair.first % pair.second };
		std::swap(pair.first, pair.second);
		pair.second = rem;
	}
	return pair.first;
}

long calcLCM(std::pair<long, long>& pair) // Using the least common multiple algorithm to calculate it.
{
	long GCD = calcGCD(pair);
	return (pair.first / GCD) * pair.second;
}


short getChoice()
{

	short input{};

	while (true)
	{
		std::cout << "What do you want to calculate?\n";
		std::cout << "1) GCD\n";
		std::cout << "2) LCM\n";
		std::cout << "3) Both\n";
		std::cout << "4) Quit\n";

		std::cin >> input;
		if (clearInput()) // If wrong input found.
		{
			continue;
		}

		if (input > 4 || input < 1) // If input is out of bounds.
		{
			std::cout << "Wrong input, try again.\n";
			continue;
		}
		ignoreLine(); // Clears the buffer.

		return input;

	}


}

bool printOutput(short choice, std::pair<long, long>& pair)
{
	switch (choice) // It returns false if the program should exit; otherwise, it returns true.
	{
	case 1: // GCD
		std::cout << "GCD = " << calcGCD(pair) << '\n';
		std::cout << '\n';
		return true;

	case 2: // LCM
		std::cout << "LCM = " << calcLCM(pair) << '\n';
		std::cout << '\n';
		return true;
	case 3: // Both
		std::cout << "GCD = " << calcGCD(pair) << '\n';
		std::cout << "LCM = " << calcLCM(pair) << '\n';
		std::cout << '\n';
		return true;
	default: // Unexpected error
		std::cout << "Uh Oh! Something went wrong!";
		return false;

	}
}



int main()
{
	while (true)
	{
		short choice{ getChoice() };
		if (choice == 4) // Quit
		{
			std::cout << "Leaving...\n";
			break;
		}

		std::pair<long, long> pair(getInput(), getInput());

		if (!printOutput(choice, pair))
		{
			break;
		}

	}

	return 0;

}