#include <iostream>
#include "classes.h"

void calculations(int &counter, skene skene, bool &running) {
    counter++;
        std::cout << counter << std::endl;
        if(counter == 10){
            std::cout << skene.objekti1.id << std::endl;
            std::cout << skene.objekti2.id << std::endl;
            running = false;
        }
}