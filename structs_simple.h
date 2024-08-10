#include <string>
struct Record {
    std::string name; // name is a member of Record (a string member)
// ...
};

// The only way to nake auto fct is to put full defenition in .h
Record fct(int arg);