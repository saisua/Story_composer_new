// External includes
#include <iostream>
#include <string>

// Internal includes
#include <scene_box.h>

Scene_box::Scene_box()
{
    //this->_parent = parent;
    this->set_scene(new Scene());
    std::cout << "Created new Scene_box" << std::endl;
}

Scene_box::Scene_box(std::string id){
    this->set_id(id);
    this->set_scene(new Scene(id));
    std::cout << "Created new Scene_box with id: " << id << std::endl;
}

// // GETTERS

std::string Scene_box::get_id() const{
    std::cout << "Scene_box::get_id()" << std::endl;
    return this->_id;
}

Scene* Scene_box::get_scene() const{
    std::cout << "Scene_box::get_scene()" << std::endl;
    return this->_scene;
}

// // SETTERS

void Scene_box::set_id(std::string new_id){
    std::cout << "Scene_box::set_id(" << new_id << ")" << std::endl;
    this->_id = new_id;
}

void Scene_box::set_scene(Scene* new_scene)
{
    std::cout << "Scene_box::set_scene()" << std::endl;
    this->_scene = new_scene;
}


void Scene_box::show(){
    std::cout << "Scene_box::show()" << std::endl;
}
