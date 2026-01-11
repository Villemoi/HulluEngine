#ifndef CLASSES_H
#define CLASSES_H

struct objekti {
    int id;
};

struct skene {
    objekti objekti1;
    objekti objekti2;
};

// Declare the function so other files know it exists
skene start(); 

#endif