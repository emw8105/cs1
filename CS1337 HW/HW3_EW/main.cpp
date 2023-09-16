/*Author: Evan Wright
Compiler: GNU GCC
Date: 3/3/2022
Purpose of program:
Program opens a file specified by a user that contains grocery product information.
The program removes all of the delimiting characters in each line of information and
evaluates whether an input is valid using the leftover token. It goes down the line
of data until it sorts each token into each of the 5 validation categories, if there
are more or less it will state the invalidity of the file's information, along with
any other errors in validation.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

/* Returns true if the string is a valid price, false otherwise
*/
bool isValidPrice(string);

/* Takes as reference parameter a string to be tokenized and returns the first token found
Returns the empty string if no token is found
The function deletes any leading delimiter and the first token found from the original string
Tokenization is based on a delimiter, where a delimiter is the '\t' (tab) , '  ' (space), '\n' (new line) or '\r' (carriage return)  character
Example: if the string s  is "\t abcd\t\t 345\t ^7$ ", the function returns "abcd" as the first token found, and modifies
the string s to become "\t\t 345\t ^7$ "
*/
string tokenize(string &);

int main()
{

    string fileName;
    cout << "Enter input file:";
    cin >> fileName;
    ifstream inFile;

    inFile.open(fileName); // open the file specified by the user
    if (inFile.fail()) // test for file open failure or empty file
    {
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl;
        inFile.close();
        exit(EXIT_FAILURE);
    }

    cout << endl << "Checking " << fileName << endl;
    cout << "---------";
    for (unsigned int i = 0; i < fileName.length(); i++) // output underline depending on fileName length
    {
        cout << "-";
    }
    cout << endl;

    string stringRead;
    bool isFileValid = true;

    while (getline(inFile, stringRead) && isFileValid == true) // loop while a new line can be read from the file and the file is valid
    {
        unsigned int i = 0;
        string token;
        char charAtIndex;
        while ((token = tokenize(stringRead)) != "" && isFileValid == true) // loop while there are tokens in the string and the file is valid
        {
            cout << endl << "Token #" << i+1 << " is " << token;
            if (i == 0) // 1st element should be the PLU, validate the PLU
            {
                if (token.length() == 4) // check if the PLU has 4 characters
                {
                    bool validPLU = true;
                    for (unsigned int j = 0; j < token.length(); j++) // loop through the PLU and check for the correct elements at each index
                    {
                        charAtIndex = token[j];
                        if (!(isupper(charAtIndex) || islower(charAtIndex) || isdigit(charAtIndex))) // if all 3 checks fail, index has no number or letter
                        {
                            cout << ", PLU is invalid";
                            validPLU = false;
                            isFileValid = false;
                        }
                    }
                    if (validPLU == true) // if none of the indexes were invalid
                    {
                        cout << ", PLU is valid";
                    }
                }
                else // the PLU had more or less than 4 characters
                {
                    cout << ", PLU is invalid";
                    isFileValid = false;
                }
            }
            else if (i == 1) // 2nd element should be product name, check first index for character
            {
                charAtIndex = token[0];
                if (isupper(charAtIndex) || islower(charAtIndex)) // check if the first index is a char
                {
                    cout << ", Product name is valid";
                }
                else
                {
                    cout << ", Product name is invalid";
                    isFileValid = false;


                }
            }
            else if (i == 2) // 3rd element should be sales type, only one character, either '0' or '1'
            {
                if (token.length() == 1) // check length
                {
                    charAtIndex = token[0];
                    if (charAtIndex == '0' || charAtIndex == '1') // check character itself
                    {
                        cout << ", Sales type is valid";
                    }
                    else
                    {
                        cout << ", Sales type is invalid";
                        isFileValid = false;
                    }
                }
                else
                {
                    cout << ", Sales type is invalid";
                    isFileValid = false;
                }

            }
            else if (i == 3) // 4th element should be unit price, see isValidPrice function for specifications on validity
            {
                if (isValidPrice(token)) // call isValidPrice function to determine if the token is valid
                {
                    cout << ", Price is valid";
                }
                else
                {
                    cout << ", Price is invalid";
                    isFileValid = false;
                }

            }
            else if (i == 4) // 5th element should be Inventory, should only be digits
            {
                bool validInven = true;
                for (unsigned int j = 0; j < token.length(); j++) //loop through the token
                {
                    charAtIndex = token[j];
                    if (!(isdigit(charAtIndex))) // check if any index isn't a digit
                    {
                        cout << ", Inventory is invalid";
                        isFileValid = false;
                        validInven = false;
                    }
                }
                if (validInven == true)
                {
                    cout << ", Inventory is valid";
                }
            }
            else
            {
                cout << ", Too many items in record";
                isFileValid = false;
            }

            i++;
        }
        if (isFileValid == true && i < 5) // check if the loop made it to the end and there are missing values
        {
            cout << endl;
            if (i == 0)
            {
                cout << "PLU";
            }
            else if (i == 1)
            {
                cout << "Product name";
            }
            else if (i == 2)
            {
                cout << "Sales type";
            }
            else if (i == 3)
            {
                cout << "Price";
            }
            else if (i == 4)
            {
                cout << "Inventory";
            }
            cout << " is invalid, record has missing items" << endl;
            isFileValid = false;
            break;
        }
        cout << endl;
    }
    if (isFileValid == true)
    {
        cout << endl << "######## " << fileName << " has valid content ########" << endl;
    }
    else
    {
        cout << endl << "######## " << fileName << " has invalid content ########" << endl;
    }

    return 0;
}

bool isValidPrice(string price)
{
    bool hasDot = false;
    int dotIndex = -1;

    for (unsigned int i = 0; i < price.length(); i++) // loop through the given string
    {
        char charAtIndex = price[i];
        if (!(isdigit(charAtIndex))) // check if the character isn't a digit
        {
            if (charAtIndex == '.' && hasDot == false) // check if the character at the index is a dot
            {
                hasDot = true; // there can only be one dot, so prevent this check in future loop iterations
                dotIndex = i;
            }
            else // if a second dot is found, return false
            {
                return false;
            }
        }
    }
    if (hasDot) // if the number has a decimal, make sure there are no more than 2 indexes after the decimal
    {
        if (price.length()-dotIndex-1 <= 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

string tokenize(string& inputString)
{
    char charAtIndex = inputString[0];
    string tempToken;
    unsigned int i = 0;

    while ((isspace(charAtIndex) && i < inputString.length())) // removes leading delimiters by looping until it encounters a non-space char
    {
        i++;
        charAtIndex = inputString[i];
    }
    inputString = inputString.substr(i, inputString.length()); // remove all specified delimiters from the string

    //reloop and grab the first token, end once delimiters begin again
    i = 0;
    while (!(isspace(charAtIndex)) && i < inputString.length())
    {
        tempToken+= inputString[i]; // store the token in tempToken and return it after the loop ends
        i++;
        charAtIndex = inputString[i];
    }
    inputString = inputString.substr(i, inputString.length()); // remove the token from the string

    return tempToken;
}
