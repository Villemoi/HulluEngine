#include <iostream>
#include "classes.h"

int loop(skene skene) {
    bool running = true;

    int counter = 0;

    while (running) {
        //inputit
        //peli laskut
        counter++;
        std::cout << counter << std::endl;
        if(counter == 10){
            std::cout << skene.objekti1.id << std::endl;
            std::cout << skene.objekti2.id << std::endl;
            running = false;
        }
        //kuvan renderöinti

    }
    return 0;
}