#ifndef SCENE_H
#define SCENE_H

// External includes
#include <vector>
#include <string>
#include <variant>
#include <list>

// Internal includes
#include "all.h"

// Forward Declarations
class Character;
class Place;
class Relationship;
class Thought;
class Item;
class Conversation;

class Scene
{
/*
    The Scene class holds data for a scene, the actions taken by certain characters
    in some place at some time
*/

private:
    // The scene ID, should not be changed
    // Ideally, this id should be unique in the project
    std::string _id;
    // The paths to the images used to describe the scene
    std::vector<std::string> _images;
    // Descriptions to take note of whatever the writer
    // thinks is rellevant about this scene
    std::vector<std::string> _descriptions;
    // The list of Characters that will appear in this scene
    std::list<Character*> _characters;
    // The list of places this Scene takes place in
    std::list<Place*> _places;
    // The list of conversations that take place in this Scene
    std::list<Conversation*> _conversations;
    // The list of items that will be handed/used in this Scene
    std::list<Item*> _items;
    
    // Changes is a very important part of the class, it holds any change in the
    // items, places, characters... which will be hold for further scenes
    std::list<Character*> _character_changes; // std::variant<Character, Place, Relationship, Thought, Item>
    std::list<Place*> _place_changes;
    std::list<Relationship*> _relationship_changes;
    std::list<Thought*> _thought_changes;
    std::list<Item*> _item_changes;

public:
    explicit Scene();
    explicit Scene(std::string);
    explicit Scene(std::string, Character*);
    explicit Scene(std::string, std::list<Character*>);

    // ADD
    void add_image(std::string*);
    void add_character(Character*);
    void add_characters(std::list<Character*>);
    void add_place(Place*);
    void add_places(std::list<Place*>);
    void add_conversation(Conversation*);
    void add_conversations(std::list<Conversation*>);
    void add_item(Item*);
    void add_items(std::list<Item*>);
    //void add_change(); // I should meditate the structure of scenes over time

    // GETTERS
    std::string get_id() const;
    std::list<Character*> get_characters() const;

    // SETTERS
    void set_id(std::string);

};

#endif