// External includes
#include <iterator>
#include <iostream>

// Internal includes
#include "place.h"

Place::Place(std::string id){
    this->_id = id;

    std::cout << "New Place " << id << std::endl;
}

Place::Place(std::string id, Place* sub_place){
    this->_id = id;
    this->_places.emplace_front(sub_place);

    std::cout << "New Place " << id << " that contains " << sub_place->get_id() << std::endl;
}

Place::Place(std::string id, std::forward_list<Place*> sub_places){
    this->_id = id;
    this->_places.splice_after(this->_places.before_begin(), sub_places);

    std::cout << "New Place " << id << " that contains a list sub_places" << std::endl;
}

// // ADD

void Place::add_place(Place* new_place){
    this->_places.emplace_front(new_place);
}

// // GETTERS

std::string Place::get_id() const{
    return this->_id;
}

Place* Place::get_place(int index) const{
    std::forward_list<Place*>::const_iterator iter = this->_places.begin();
    
    std::advance(iter, index);
    
    return *iter;
}

Place* Place::get_place(std::string id) const{
    for(std::forward_list<Place*>::const_iterator iter = this->_places.begin(); 
                                    iter != this->_places.end(); iter++){
        if((*iter)->get_id() == id) return *iter;
    }
}