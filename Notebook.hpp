#include <system_error>
#include "Direction.hpp"
#include <string>

using namespace std;

namespace ariel{

    class Notebook{

    public:
        void write(int page, int row, int column, ariel::Direction direction, const std::string &str);

        const string& read(int page, int row, int column, ariel::Direction direction, int length);

        void erase(int page, int row, int column, Direction direction, int length);

        void show(int page);
    };
}



