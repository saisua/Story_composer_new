#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H

// External includes
#include <variant>
#include <string>

// Internal includes

// Forward Declarations
class Character;
class Item;
class Trait;
class Place;

class Relationship
{
/*
    The Relationship class holds data for a relation from a
    character, item, trait or place to another
*/

private:
    std::variant<Character*, Item*, Trait*, Place*> _other_party;

    std::string _type;
    std::string _description;

public:
    explicit Relationship();
    explicit Relationship(std::variant<Character*, Item*, Trait*, Place*>, std::string);

    // SETTERS
    void set_other_party(std::variant<Character*, Item*, Trait*, Place*>);
    void set_type(std::string);
    void set_description(std::string);

    // GETTERS
    std::variant<Character*, Item*, Trait*, Place*> get_other_party() const;
    std::string get_type() const;
    std::string get_description() const;
};

#endif