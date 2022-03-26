#include <system_error>
#include "Direction.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

namespace ariel{
    class Page{
    public:
        vector<vector<char>> v;
        int num;
        Page() {
            cout<<"creating page";
            v.resize(10);
//            for (int i = 0; i <10 ; ++i) {
//                v[i].resize(10);
//                for (int j = 0; j < 10; ++j){
//                    v[i][j]='b';
//                }
//            }
        }
    };

    class Notebook {
    public:
        list<int> pages;
        Notebook() {
            for (int i = 0; i < 10; ++i)
                pages.push_front(i);
        }

        void write(int page, int row, int column, ariel::Direction direction, const std::string &str);

        const string &read(int page, int row, int column, ariel::Direction direction, int length);

        void erase(int page, int row, int column, Direction direction, int length);

        void show(int page);

    };
}







