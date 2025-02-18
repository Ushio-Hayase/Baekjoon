#include <iostream>
#include <string>
using namespace std;

void print(int N)
{
	if (N % 3 == 0 && N % 5 == 0)
	{
		cout << "FizzBuzz" << "\n";
	}
	else if (N % 3 == 0)
	{
		cout << "Fizz" << "\n";
	}
	else if (N % 5 == 0)
	{
		cout << "Buzz" << "\n";
	}
	else
	{
		cout << N << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str1, str2, str3;
	cin >> str1;
	cin >> str2;
	cin >> str3;
	if (str3 != "FizzBuzz" && str3 != "Fizz" && str3 != "Buzz")
	{
		print(stoi(str3) + 1);
	}
	else if (str2 != "FizzBuzz" && str2 != "Fizz" && str2 != "Buzz")
	{
		print(stoi(str2) + 2);
	}
	else
	{
		print(stoi(str1) + 3);
	}
	return 0;
}