#ifndef THOUGHT_H
#define THOUGHT_H

// External includes
#include <string>
#include <list>

// Internal includes
#include <action.h>

// Forward Declarations
class Character;
class Trait;

class Thought : public Action
{
    typedef Action super;

private:
    std::string _action = "think";
    std::string _content;

public:
    explicit Thought(Character*, std::string);
    explicit Thought(Character*, std::string, Character*);
    explicit Thought(Character*, std::string, std::list<Character*>);
};

#endif