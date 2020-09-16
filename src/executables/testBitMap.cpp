/**
 * Test code for BitMap and (when uncommented) WorkingBitMap.
 *
 * BitMap is as unimplemented as possible so that when the test code is
 * run with it, the 1 test case fails with about 6 failed assertions; there
 * are loops with assertions and the first failure causes the test code to
 * abort the loop. There is therefore about one failure per SECTION.
 *
 * The assertions that DO pass for BitMap are checks that the code returns
 * a false Boolean value for "unset" bits; the BitMap code returns false no
 * matter what index is read.
 *
 *
 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
                           // - only do this in one cpp file
#include "catch.hpp"
#include "BitMap.h"
