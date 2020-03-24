#ifndef ACTION_H
#define ACTION_H

// External includes
#include <list>
#include <string>

// Internal includes

// Forward declarations
class Character;
class Trait;
class Place;

class Action
{

private:
    Character* _emitter;
    std::list<Character*> _intended_receivers;
    std::list<Character*> _receivers;

    std::string _action;

    std::string _description;
    std::list<Trait*> _traits;

    Place* _place = nullptr;

public:
    explicit Action(Character*, std::string);
    explicit Action(Character*, std::string, Character*);
    explicit Action(Character*, std::string, std::list<Character*>);

    // GETTERS
    Character* get_emitter() const;
};

#endif