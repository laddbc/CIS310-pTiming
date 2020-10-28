/**
 * Framework program for timing a function call
 *
 *
 */
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <vector>
using namespace std;

const int DEFAULT_LOOPS = 100000;

// just a stupid performance check.
int theNothingCounter = 0;
void almostNothing() {
  theNothingCounter++;
}

int main(int argc, char *argv[]) {
  vector<string> arguments; // command-line arguments translated to strings in a vector
  for (int aNdx = 0; aNdx < argc; ++aNdx)
    arguments.push_back(argv[aNdx]);

  // if there is a first argument, read it as an int, the number of loops
  int loops = (arguments.size() > 1) ? stoi(arguments[1]) : DEFAULT_LOOPS;

  // clock_t is the return type of clock(); returns a tick count
  // subtract and divide by CLOCKS_PER_SEC to get time (note: need to
  // convert to floating point)
  clock_t start = 0;
  clock_t end = 0;
  clock_t elapsed = 0;


  /*
    What to do:
      for (number of loops)
        time {
            call almostNothing
        }
        add time to elapsed
      Calculate and print microseconds per function call.
  */

  if (loops != theNothingCounter) {
    cout << "*** PROBLEM: function call count not equal to loops!" << endl;
  } else {
    double microseconds_per_action =  1.123456789;

    cout << loops << " function calls." << endl;
    cout << "elapsed time (ticks) / tick/second = elapsed time (seconds)" << endl
         << "    = " << elapsed << "/" << CLOCKS_PER_SEC << endl
         << "    = " << (double(elapsed) / CLOCKS_PER_SEC) << "s" << endl;
    cout << "microseconds / function call = " << fixed << setprecision(8) << microseconds_per_action << endl;
  }

  return 0;
}
