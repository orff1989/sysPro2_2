
#include "Notebook.hpp"
#include <iostream>

using namespace std;
using namespace ariel;
using ariel::Direction;

//////////////////////// PAGE ////////////////////////////

void ariel::Page::showPage() {
    for (size_t i = 0; i < this->v.size(); i++){
        for (size_t j = 0; j < this->v[0].size(); j++)
            cout<<v[i][j];
        cout<<endl;
    }
    cout<<endl;
}

void ariel::Page::writeIn(size_t row, size_t column, ariel::Direction direction, const std::string &str) {
    if(direction==Direction::Horizontal) {
        for (size_t i = 0; i < str.size(); i++)
            this->v[row][column+i] = str.at(i);
    }
    else{
        for (size_t i = 0; i < str.size(); i++)
            this->v[row+i][column] = str.at(i);
    }
}

string ariel::Page::readIn(size_t row, size_t column, ariel::Direction direction, size_t len){
    std::string ans{""};

    if(direction==Direction::Horizontal) {
        for (size_t i = 0; i < len; i++)
            ans =ans + this->v[row][column+i];
    }
    else{
        for (size_t i = 0; i < len; i++)
            ans =ans + this->v[row+i][column];
    }
    return ans;
}

void ariel::Page::increase_Rows(size_t n) {
    this->v.resize(n+10, vector<char>(100,'_'));
}

/////////////// NOTEBOOK /////////////////////

void ariel::Notebook::increase_Pages(size_t num){
    for (int i = this->pages.size(); i < num; i++) {
        this->pages.push_back(Page(i));
    }
}

void ariel::Notebook::write(int page, int row, int column, ariel::Direction direction, const std::string &str){
    //checking the parameters
    if(page<0 || row<0 || column<0 || str.find("~")!=string::npos) {throw "the parameters are not valid";}
    else if(column+int(str.size())>99) {throw "there is not enough space in the line for this word";}

    // if we need to resize the number of pages
    if (page >= this->pages.size()){
        increase_Pages(size_t(page)+10);
    }
    //if we need to resize the number of rows
    if (row>=this->pages[size_t(page)].v.size()){
        this->pages[size_t(page)].increase_Rows(size_t(row)+10);
    }

    string str1 = this->pages[size_t(page)].readIn(size_t(row),size_t(column),direction,str.length());
    for (size_t i = 0; i < str1.size(); ++i) {
        if (str1.at(i) != '_') { throw "cant write on written space"; }
    }

    this->pages[size_t(page)].writeIn(size_t(row),size_t(column),direction,str);

}

const string& ariel::Notebook::read(int page, int row, int column, ariel::Direction direction, int length){
    if(page<0 || row<0 || column<0 || length<0 || column+length>99) {throw "the parameters are not valid";}
    static string * ans;
    ans = new string;
    *ans = this->pages[size_t(page)].readIn(size_t(row),size_t(column),direction,size_t(length));
    return *ans;
}

void ariel::Notebook::erase(int page, int row, int column, Direction direction, int length){
    if(page<0 || row<0 || column<0 || length<0 || column+length>99) {throw "the parameters are not valid";}

    std::string ans{""};
    ans.append(size_t(length),'~');

   this->pages[size_t(page)].writeIn(size_t(row),size_t(column),direction,ans);
}

void ariel::Notebook::show(int page) {
    if(page<0 || page>= this->pages.size()) {throw "the parameters are not valid";}
    this->pages[size_t(page)].showPage();
}

