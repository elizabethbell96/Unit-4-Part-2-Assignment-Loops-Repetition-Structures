#include <iostream> // provides cin
#include <string> // for string manupulation
#include <ios> //provides ios_base::failure
#include <sstream> //for string manipulation and comparison
using namespace std;


// This is a function that tells the program the correct ordinal suffix to apply to a number.
string getOrdinalSuffix (int num)
{
  if (num % 100 >= 11 && num % 100 <= 13) //applying corect ordinals for anomoly numbers 11-13
  {
    return "th";
  } 
    else if (num % 10 == 1)
   {
    return "st";
   }
    else if (num % 10 == 2)
    {
      return "nd";
    }
    else if (num % 10 == 3)
    {
      return "rd";
    }
  else
    {
      return "th";
    }
}

template <typename T>
T getValidatedInput()
{
  T result;
  cin >> result;


  if (cin.fail() || cin.get() != '\n') // This is checking that the failbit has been set and that the result is the only thing in the input stream.
  {
    cin.clear();

    while (cin.get() != '\n'); // This is clearing the input stream with an empty while loop so that the user can try again.

    throw ios_base::failure("Invalid input. Please enter a valid number."); //This prompts the user to try again.
  }
  return result;
}



int main() 
{
  while (true)
    {
  int N;

  // Validate and get input for the stopping point
  while (true) 
  {
      cout << "\nEnter the stopping point (-1 to exit): ";
      try
        {
          N = getValidatedInput<int>();
          if (N == -1)
          {
            return 0; //exits the program if -1 is entered
          }
          break;
          if (N <= 0) {
              throw ios_base::failure("Invalid input. Please enter a positive integer.");
          }
      } 
      catch (exception& e) 
        {
          cerr << e.what() << endl;
      }
  }

  // Print the first N ordinals followed by "Hello"
  for (int i = 1; i <= N; ++i) 
  {
      string ordinalSuffix = getOrdinalSuffix(i);
      cout << i << ordinalSuffix << " Hello" << endl;
  }
    }
  return 0;
}