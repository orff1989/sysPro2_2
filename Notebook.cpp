
#include "Notebook.hpp"
#include <iostream>

using namespace std;
using namespace ariel;
using ariel::Direction;


void ariel::Notebook::write(int page, int row, int column, ariel::Direction direction, const std::string &str){
    //checking the parameters
    if(page<0 || row<0 || column<0 || str.find("~")!=string::npos) {throw "the parameters are not valid";}
    else if(column+int(str.size())>99) {throw "there is not enough space in the line for this word";}
    Page p;



}

const string& ariel::Notebook::read(int page, int row, int column, ariel::Direction direction, int length){
    if(page<0 || row<0 || column<0 || length<0 || column+length>99) {throw "the parameters are not valid";}
    static string var;
    return var;
}

void ariel::Notebook::erase(int page, int row, int column, Direction direction, int length){
    if(page<0 || row<0 || column<0 || length<0 || column+length>99) {throw "the parameters are not valid";}
}

void ariel::Notebook::show(int page) {

}

