// External includes
#include <iostream>

// Internal includes
#include "scene.h"

Scene::Scene(){
    this->_images = std::vector<std::string>();
    this->_descriptions = std::vector<std::string>();
    this->_characters = std::list<Character*>();
    this->_places = std::list<Place*>();
    this->_conversations = std::list<Conversation*>();

    std::cout << "Created new Scene" << std::endl;
}

Scene::Scene(std::string id){
    this->_id = id;
    
    this->_images = std::vector<std::string>();
    this->_descriptions = std::vector<std::string>();
    this->_characters = std::list<Character*>();
    this->_places = std::list<Place*>();
    this->_conversations = std::list<Conversation*>();

    std::cout << "Created new Scene with id: " << id << std::endl;
}

Scene::Scene(std::string id, Character* new_character){
    this->_id = id;
    
    this->_images = std::vector<std::string>();
    this->_descriptions = std::vector<std::string>();
    this->_characters = std::list<Character*>();
    this->_places = std::list<Place*>();
    this->_conversations = std::list<Conversation*>();

    this->_characters.push_back(new_character);

    std::cout << "Created new Scene with id: " << id << std::endl;
}

Scene::Scene(std::string id, std::list<Character*> new_characters){
    this->_id = id;
    this->_characters = new_characters;
    
    this->_images = std::vector<std::string>();
    this->_descriptions = std::vector<std::string>();
    this->_places = std::list<Place*>();
    this->_conversations = std::list<Conversation*>();

    std::cout << "Created new Scene with id: " << id << std::endl;
}

// // ADD

void Scene::add_character(Character* new_character){
    this->_characters.push_back(new_character);

    std::cout << "Added character " << new_character->get_id() << " to group " << this->get_id() << std::endl;
}

void Scene::add_characters(std::list<Character*> new_characters){
    this->_characters.insert(this->_characters.end(), new_characters.begin(), new_characters.end());

    std::cout << "Added to group " << this->get_id() << " " << new_characters.size() << " new characters" << std::endl;
}

void Scene::add_place(Place* new_place){
    this->_places.push_back(new_place);
}

void Scene::add_places(std::list<Place*> new_places){
    this->_places.insert(this->_places.end(), new_places.begin(), new_places.end());
}

void Scene::add_conversation(Conversation* new_conversation){
    this->_conversations.push_back(new_conversation);
}

void Scene::add_conversations(std::list<Conversation*> new_conversations){
    this->_conversations.insert(this->_conversations.end(), new_conversations.begin(), new_conversations.end());
}

void Scene::add_item(Item* new_item){
    this->_items.push_back(new_item);
}

void Scene::add_items(std::list<Item*> new_items){
    this->_items.insert(this->_items.end(), new_items.begin(), new_items.end());
}

// // GETTERS

std::string Scene::get_id() const{
    return this->_id;
}

std::list<Character*> Scene::get_characters() const{
    return this->_characters;
}

// // SETTERS

void Scene::set_id(std::string new_id){
    this->_id = new_id;
}