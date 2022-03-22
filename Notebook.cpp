#include "Notebook.hpp"



void ariel::Notebook::write(int page, int row, int column, ariel::Direction direction, const std::string &str){

}

const string& ariel::Notebook::read(int page, int row, int column, ariel::Direction direction, int length){
    static string var;
    return var;
}

void ariel::Notebook::erase(int page, int row, int column, Direction direction, int length){

}

void ariel::Notebook::show(int page) {

}
