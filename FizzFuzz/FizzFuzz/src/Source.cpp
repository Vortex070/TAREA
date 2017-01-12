#include <iostream>

using namespace std;

int main()
{

	for (int i = 0; i < 101; ++i)
	{
		if ((i % 3) == 0 && (i % 5) == 0)
		{
			cout << "Fizz Fuzz ";
		}
		else if ((i%3) == 0)
		{
			cout << "Fizz ";
		}
		else if ((i%5) == 0)
		{
			cout << "Fuzz ";
		}
		
		cout << i << endl;
	}

	return 0;
}