#ifndef TRAIT_H
#define TRAIT_H

// External includes
#include <variant>
#include <string>

// Internal includes

// Forward Declarations
class Character;
class Group;
class Knowledge;

class Trait
{

private:
    // Who does this trait affect to?
    // Needed when sharing knowledge between characters
    std::variant<Character*, Group*, Knowledge*> _owner;

    // What does having this trait mean? EX. introvert
    std::string _content;

public:
    explicit Trait(Character*, std::string); // owner, content
    explicit Trait(Group*, std::string); // owner, content
    explicit Trait(Knowledge*, std::string); // owner, content

};

#endif