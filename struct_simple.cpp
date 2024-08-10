#include <string>
#include "structs_simple.h"



Record fct(int arg) // fct is global (names a global function)
// arg is local (names an integer argument)
{
    
    std::string motto {"Who dares wins"}; // motto is local
    auto p = new Record{"Hume"}; // p points to an unnamed Record (created by new)
    return *p;
}

