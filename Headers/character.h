#ifndef CHARACTER_H
#define CHARACTER_H

// External includes
#include <forward_list>
#include <list>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

// Internal includes
#include "knowledge.h"

// Forward Declarations
class Trait;
class Relationship;
class Thought;
class Item;
class Thought;

class Character // or Personage?
{
/*
    The Character class holds data for a character who makes actions and relationates
    with the places and other characters, building relations with them.
*/

    // Joan presi idea: revisar manera de parlar personatges per si una frase no cuadra

private:
    // The Character ID, should not change
    // Ideally it should be unique
    std::string _id; 
    // The Character's name.
    // It can change over the scenes
    std::string _name; 
    // The alias the Character can be known for
    // It can change over the scenes
    std::string _alias;
    // The description of the Character.
    // The writter will put what it thinks is useful
    std::string _description;
    
    // The inventory of Items the character has
    std::forward_list<Item*> _inventory; 

    // The list of Traits that define how the character is and behaves
    std::forward_list<Trait*> _traits;
    // The relationships the caracter has
    std::forward_list<Relationship*> _relationships;
    // The thoughts the character has had
    std::forward_list<Thought*> _thoughts;

    // Should I store a list of groups?
    
    // how to store knowledge?
    // a character knows:
    //  - another character
    //  - a trait from another character
    //  - a message someone said
    //  - a character has/owns some item/place
    //  - a place
    //  - two characters have a relationship (friends, couple...)
    
    // The knowledge the Character has gathered
    std::unordered_map<std::string, Knowledge*> _knowledge;

    // The paths to the images that are used as reference for this character
    std::vector<std::string> _images;

public:
    explicit Character(std::string);

    void give_item(Item*, Character*); // Must update knowledge
    void give_item(std::string, Character*); // Must update knowledge

    void receive_message(Message*); // message
    void receive_message(Message*, Character*); // message, from
    //void receive_message(Message*, std::string); // Must update knowledge

    Message* say(Character*, std::string); // to, content
    Message* say(Group*, std::string); // in, content (to all)
    Message* say(Group*, std::string, Character*); // in, content, to
    Message* say(Conversation*, std::string); // in, content, (to all)
    Message* say(Conversation*, std::string, Character*); // in, content, to

    Message* say_anonymous(Character*, std::string); // to, content
    Message* say_anonymous(Group*, std::string); // in, content (to all)
    Message* say_anonymous(Group*, std::string, Character*); // in, content, to


    // ADD
    void add_item(Item*); // Must add knowledge
    void add_items(std::forward_list<Item*>); // Must add knowledge
    void add_trait(Trait*);
    void add_traits(std::forward_list<Trait*>);
    void add_relationship(Relationship*); // Must add knowledge
    void add_relationships(std::forward_list<Relationship*>); // Must add knowledge
    void add_thought(Thought*);
    void add_thought(std::string);
    void add_thought(std::string, Character*);
    void add_thought(std::string, std::list<Character*>);
    void add_thoughts(std::forward_list<Thought*>);
    void add_knowledge(std::string, Knowledge*);
    void add_knowledge(std::unordered_map<std::string, Knowledge*>);

    void add_to_group(Character*, Group*);

    // REMOVE
    void remove_self_group(Group*);
    void remove_from_group(Character*, Group*);
    void remove_item(Item*);
    Item* remove_item(std::string);

    // GETTERS
    std::string get_id() const;
    std::string get_name() const;
    std::string get_alias() const;

    // SETTERS
    void set_name(std::string);
    void set_alias(std::string);

    // STATIC
};

#endif