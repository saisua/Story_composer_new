#ifndef PLACE_H
#define PLACE_H

// External includes
#include <list>
#include <forward_list>
#include <string>

// Internal includes

// Forward Declarations
class Character;
class Item;
class Trait;

class Place
{
/*
    The Place class holds data for a place where a scene takes action
*/

    // I should prlly setup some structure to create a graph-map

private:
    std::string _id;
    std::string name;

    std::forward_list<Character*> _owners;
    std::forward_list<Item*> _inventory;
    std::forward_list<Place*> _places;
    std::forward_list<Trait*> _traits;

public:
    explicit Place(std::string);
    explicit Place(std::string, Place*);
    explicit Place(std::string, std::forward_list<Place*>);

    // ADD
    void add_owner(Character*);
    void add_owner(std::forward_list<Character*>);
    void add_item(Item*);
    void add_items(std::forward_list<Item*>);
    void add_trait(Trait*);
    void add_traits(std::forward_list<Trait*>);
    void add_place(Place*);
    void add_places(std::forward_list<Place*>);

    // GETTERS
    std::string get_id() const;
    Place* get_place(int) const;
    Place* get_place(std::string) const;
};

#endif