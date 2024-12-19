#pragma once
#include "Deque.h"
#include <iostream>  
#include <iomanip>

class stomach :
    public Deque
{
    private:
        Deque Q;

        int stomachSize = 11;
        int totalFood = 0;
    public:

        void eat(string name);
        bool vomit();
        bool excrete();
        bool clear();
        void status();

        void display();
};

