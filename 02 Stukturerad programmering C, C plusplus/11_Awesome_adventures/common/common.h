//
//  common/common.h
//  11_Awesome_adventures
//
//  Created by Daniel Eftodi on 2021-10-12.
//

#ifndef common_h
#define common_h

#include <stdio.h>
#include <iostream>
#include <climits>        // CHAR_BIT
#include <stdlib.h>       // rand

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>       // system(clear);
                          // sleep($SECS);
#endif

#include <random>         // random
#include <limits>         // This is important!
#include <string>         // stoi
#include <sstream>        // stringstream

#include "../menus/main_menu.h"     // main menu code
#include "../common/common_lib.h"   // common lib

#endif /* common_h */
