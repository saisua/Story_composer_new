#ifndef GROUP_H
#define GROUP_H

// External includes
#include <list>
#include <unordered_map>

// Internal includes
#include "character.h"

// Forward Declarations
class Thought;
class Knowledge;
class Message;

class Group : public Character
{
/*
    This class holds data over a group of characters.
    The idea of a group revolves of the fact that people usually behaves
    differently when on a group or when alone.
*/

private:
    typedef Character super;

    // The ID of the group, should not be changed
    // Ideally this ID should be unique among other groups
    std::string _id;

    // The list of members (Characters) of the group
    std::list<Character*> _members;  // the user must be able to modify this list order,
                                    // to be able to form hierarchies or so

public:
    explicit Group(std::string);
    explicit Group(std::string, Character*);
    explicit Group(std::string, std::list<Character*>);

    void receive_members_message(Message*); // content
    void receive_members_message(Message*, Character*); // content, to
    void receive_members_message(Character*, Message*); // from, content
    void receive_members_message(Character*, Message*, Character*); // from, content, to
    Message* receive_members_message(Character*, std::string); // from, content
    Message* receive_members_message(Character*, std::string, Character*); // from, content, to

    bool has_member(Character*) const;

    // ADD
    void add_member(Character*);
    void add_members(std::list<Character*>);
    void add_members_relationship(std::string);
    void add_members_relationship(Character*, std::string);
    void add_members_thought(Thought*);
    void add_members_thought(std::string);
    void add_members_thought(std::string, Character*);
    void add_members_thought(std::string, std::list<Character*>);
    void add_members_knowledge(std::string, Knowledge*);
    void add_members_knowledge(std::unordered_map<std::string, Knowledge*>);


    // REMOVE
    Character* remove_member(std::string); 
    void remove_member(Character*);
    // Takes in accout members hierarchy
    Character* remove_member(Character*, std::string); // expeller, expelled
    // Takes in accout members hierarchy
    void remove_member(Character*, Character*); // expeller, expelled

    // GETTERS
    Character* get_member(std::string) const;
    std::list<Character*> get_members() const;

    // SETTERS
    void set_members(std::list<Character*>);

};

#endif