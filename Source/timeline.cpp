// External includes
#include <vector>
#include <algorithm>
#include <iostream>

// Internal includes
#include "timeline.h"

TimeLine::TimeLine(){
    //this->_parent = parent;
    this->rows = new std::vector<std::vector<Scene_box*>>();
    this->rows->push_back(std::vector<Scene_box*>());
    this->_last_row = 0;

    //this->_scroll_bar = new QScrollBar(this);
    //this->_scroll_area = new QScrollArea(this);

    std::cout << "Created new TimeLine" << std::endl;
}

// Show this and all children
void TimeLine::show(){
    std::cout << "TimeLine::show()" << std::endl;
    //this->_scroll_bar->show();
    //this->_scroll_area->show();

    for(std::vector<Scene_box*> row : *this->rows){
        for(Scene_box* scene : row){
            scene->show();
        }
    }
}

size_t TimeLine::size(){
    std::cout << "TimeLine::size()" << std::endl;
    return this->rows->size();
}

// // ADD

// Add a new scene_box object
Scene_box* TimeLine::new_scene(){
    std::cout << "TimeLine::new_scene()" << std::endl;
    Scene_box* new_box = new Scene_box();

    this->rows->at(this->_last_row).push_back(new_box);

    this->scenes_num++;

    return new_box;
}

Scene_box* TimeLine::new_scene(std::string id){
    std::cout << "TimeLine::new_scene(" << id << ")" << std::endl;
    Scene_box* new_box = new Scene_box(id);

    this->rows->at(this->_last_row).push_back(new_box);
    
    this->scenes_num++;

    return new_box;
}

// Add a new row to itself
void TimeLine::new_row(){
    std::cout << "TimeLine::new_row()" << std::endl;
    this->_last_row = this->rows->size();
    this->rows->push_back(std::vector<Scene_box*>());
    //this->_scroll_bar->setMaximum(static_cast<int>(this->_last_row));
}

// // REMOVE

// Remove an already existing row
void TimeLine::remove_row(std::vector<Scene_box*>* to_remove){
    std::cout << "TimeLine::remove_row(std::vector<Scene_box*>*)" << std::endl;

    for(std::vector<std::vector<Scene_box*>>::const_iterator iter = this->rows->begin(); 
                                                        iter != this->rows->end(); iter++){
        if(*iter == *to_remove){
            this->rows->erase(iter);
            return;
        }
    }
}

void TimeLine::remove_row(int row_num){
    std::cout << "TimeLine::remove_row(" << row_num << ")" << std::endl;
    this->rows->erase((this->rows->begin() + row_num));
}

void TimeLine::remove_row(size_t row_num){
    std::cout << "TimeLine::remove_row(size_t)" << std::endl;
    this->rows->erase((this->rows->begin() + static_cast<int>(row_num)));
}

// Remove an already existing scene
void TimeLine::remove_scene(Scene_box* to_remove){
    std::cout << "TimeLine::remove_scene(Scene_box*)" << std::endl;
    std::vector<Scene_box*> row = this->rows->at(this->_last_row);

    for(std::vector<Scene_box*>::const_iterator iter = row.begin(); iter != row.end(); iter++){
        if(*iter == to_remove){
            this->rows->at(this->_last_row).erase(iter); // does this work as intended?
            this->scenes_num--;
            return;
        }
    }
}

Scene_box* TimeLine::remove_scene(std::string remove_by_string){
    std::cout << "TimeLine::remove_scene(" << remove_by_string << ")" << std::endl;
    std::vector<Scene_box*> row = this->rows->at(this->_last_row);

    for(std::vector<Scene_box*>::const_iterator iter = row.begin(); iter != row.end(); iter++){
        if((*iter)->get_id() == remove_by_string){
            this->rows->at(this->_last_row).erase(iter); // does this work as intended?
            this->scenes_num--;
            return *iter;
        }
    }
}

// // GETTERS

std::vector<Scene_box*> TimeLine::get_row(size_t row_index) const{
    std::cout << "TimeLine::get_row()" << std::endl;
    return this->rows->at(row_index);
}

std::vector<Scene_box*> TimeLine::get_row(int row_index) const{
    std::cout << "TimeLine::get_row()" << std::endl;
    return this->rows->at(row_index);
};

int TimeLine::get_scenes_num() const{
    std::cout << "TimeLine::get_scenes_num()" << std::endl;
    return this->scenes_num;
}

// // SETTERS
void TimeLine::set_last_row(size_t new_last_row){
    std::cout << "TimeLine::set_last_row(size_t)" << std::endl;
    this->_last_row = new_last_row;
}

void TimeLine::set_last_row(int new_last_row){
    std::cout << "TimeLine::set_last_row(" << new_last_row << ")" << std::endl;
    this->_last_row = static_cast<size_t>(new_last_row);
}