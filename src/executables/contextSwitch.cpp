/**
 * Framework program for timing a context switch.
 *
 *
 */
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <vector>
using namespace std;

const int DEFAULT_LOOPS = 10000;

int main(int argc, char *argv[]) {
  vector<string> arguments; // command-line arguments translated to strings in a vector
  for (int aNdx = 0; aNdx < argc; ++aNdx)
    arguments.push_back(argv[aNdx]);

  // if there is a first argument, read it as an int, the number of loops
  int loops = (arguments.size() > 1) ? stoi(arguments[1]) : DEFAULT_LOOPS;

  // clock_t is the return type of clock(); returns a tick count
  // subtract and divide by CLOCKS_PER_SEC to get time (note: need to
  // convert to floating point)
  clock_t start;
  clock_t end;
  clock_t elapsed;

  // make it easier to remember which end is which
  const int WRITE_END_OF_PIPE = 1;
  const int READ_END_OF_PIPE = 0;

  // A bitmap representing the set of CPU/Cores on this computer
  cpu_set_t my_set;
  CPU_ZERO(&my_set);   // Zero (unset) the bitmap
  CPU_SET(0, &my_set); // set the given bit (index 0) in the bitmap
  // w/ pid=0: set affinity of current thread/process
  sched_setaffinity(0, sizeof(cpu_set_t), &my_set);
  // **AFTER A FORK** Must set affinity for child process (new pid)

  /*
    What to do:
      create parentToChild pipe
      create childToParent pipe
      fork
      if (fork failed)
        exit with error code and message
      child:
        for (loops)
          read one char from parentToChild pipe
          write one char to childToParent pipe
      parent:
        zero elapsed time
        for (loops)
          time {
            write one char to parentToChild pipe
            read one char from childToParent pipe
          }
          add time to elapsed

        Calculate and print seconds/context switch
  */

  return 0;
}
