#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

// External includes
#include <tuple>
#include <variant>
#include <string>

// Internal includes
#include "trait.h"
#include "conversation.h"
#include "place.h"
#include "relationship.h"
#include "item.h"
#include "thought.h"

// Forward Declarations
class Character;
class Message;
class Scene;
class Group;

class Knowledge{
    // how to store knowledge?
    // a character knows:
    //  - another character
    //  - a trait from another character
    //  - a message someone said
    //  - a character has/owns some item/place
    //  - a place
    //  - two characters have a relationship (friends, couple...)

private:
    std::string _id;

    // Where whas first learnt from
    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> _from;
    // Who is this knowledge related to
    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> _towards;
    // The knowledge to store
    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> _knowledge;
    std::string _description;

    std::list<Trait*> _traits;

    // How many steps has the knowledge needed to end in this receiver
    int _steps = 0;

    // When it was learnt by the character. 
    Scene* _learnt; 
    // Whom was it learnt from. Only accessible by share
    Character* _told_by; 

public:
    explicit Knowledge(std::string,
                    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>); // Knowledge
    explicit Knowledge(std::string,
                    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>, // From
                    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>); // Knowledge
    explicit Knowledge(std::string,
                    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>, // From
                    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>, // Towards
                    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>); // Knowledge

    void share(Character*);
    void share(Group*);
    void share(Conversation*);

    // ADD
    void add_trait(Trait*);

    // GETTERS
    std::string get_id() const;
    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>
        get_from() const;
    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>
        get_towards() const;
    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>
        get_knowledge() const;

    // SETTERS
    void set_from(std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>);
    void set_towards(std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>);
    void set_knowledge(std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>);
};


#endif