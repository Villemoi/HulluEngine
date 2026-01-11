#include <iostream>
#include "classes.h"
#include "inputs.cpp"
#include "calculations.cpp"

int loop(skene skene) {
    bool running = true;

    int counter = 0;

    while (running) {
        //inputit
        inputs();
        //peli laskut
        calculations(counter, skene, running);

        //kuvan renderöinti

    }
    return 0;
}