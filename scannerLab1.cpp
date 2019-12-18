// Lab Scanner


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string GetToken();

int main() 
{
	string token;


	cout << "Please enter a declaration in format "
		<< "<type> <variable> [= number];" << endl;

	cout << "\nThe following are the tokens in the input:" << endl;

	token = GetToken();

	cout << endl;
	while (token != "") 
	{
		cout << token << endl;
		token = GetToken();
	}

	cout << "Done!" << endl;

	system("PAUSE");
	return 0;
}

string GetToken() 
{
	locale loc;
	string token;
	string error;
	bool goToken = true;
	char ch;

	// Read the next token and store it in variable "token".
	// The token must be read character by character. Use the regular expression
	// defined above to extract tokens from the input.
	//
	// To read a character from keyboard, use:
	//
	//       cin.get(ch);
	//
	// where "ch" is a character variable.

	while (goToken == true)
	{
		cin.get(ch);

		while (ch == ' ')
		{
			cin.get(ch);
		}
		//token = ch;
		if (isdigit(ch))
		{
			//token = token + ch;
			while (isdigit(ch))
			{
				//cout <<"digit"<< endl;
				token = token + ch;
				//cout << token << endl;
				cin.get(ch);
				//for decimals
				if (ch == '.')
				{
					token = token + ch;
					cin.get(ch);
				}
				//for semicolon
				if (ch == ';')
				{
					token = token + '\n' + ch;
					cin.get(ch);
					//goToken = false;
					//break;
				}
				if (ch == '#')
				{
					//error = token;
					token = token + '\n' + ch + ':' + " Error: Unrecognizable token";
					cin.get();
				}
				//GetToken();
				//goToken= false;
			}

			//token = token + ch;
			//cout << token << endl;
			//cout << "token" << endl;
			goToken = false;
		}
		else
		{
			token = token + ch;
			//type
			if (token == "i")
			{
				goToken = true;
			}
			else if (token == "in")
			{
				goToken = true;
			}
			else if (token == "int")
			{
				goToken = false;
			}
			else if (token == "f")
			{
				goToken = true;
			}
			else if (token == "fl")
			{
				goToken = true;
			}
			else if (token == "flo")
			{
				goToken = true;
			}
			else if (token == "floa")
			{
				goToken = true;
			}
			else if (token == "float")
			{
				goToken = false;
			}
			//variable
			else if (token == "A" || token == "B" || token == "C" || token == "D" || token == "E")
			{
				goToken = false;
			}
			//equal
			else if (token == "=")
			{
				goToken = false;
			}
			//semicolon
			else if (token == ";")
			{

				goToken = false;
			}
			//enter
			else if (token == "\n")
			{
				token = "";
				goToken = false;
			}
			else
			{
				//error = token;
				token = token + ':' + " Error: Unrecognizable token";
				cin.get();
			}
		}

	}

	return token;
}