#ifndef ITEM_H
#define ITEM_H

// External includes
#include <list>
#include <string>

// Internal includes

// Forward Declarations
class Character;
class Trait;

class Item
{

private:
    // The ID of the item, should not be changed
    // Ideally, it should be unique among other items
    std::string _id;
    // The name of the item for humans to identify it
    std::string _name;
    
    // The list of Characters that owns this item
    std::list<Character*> _owners;
    // The traits that describe this item
    std::list<Trait*> _traits;


public:
    explicit Item();
    explicit Item(std::string);
    explicit Item(std::string, Character*);
    explicit Item(std::string, std::list<Character*>);

    // ADD
    void add_owner(Character*);
    void add_trait(Trait*);

    // REMOVE
    void remove_owner(Character*);
    void remove_trait(Trait*);
    
    // GETTERS
    std::string get_id() const;

    // SETTERS
    void set_id(std::string);
    void set_name(std::string);
    void set_owners(std::list<Character*>);
    void set_traits(std::list<Trait*>);
};

#endif