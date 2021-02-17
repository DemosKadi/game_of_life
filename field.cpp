#include "field.h"

bool Row::at(int x) const {
    if(x < 0 || x >= this->size()) {
        return false;
    } else {
        return QVector<bool>::at(x);
    }
}

bool Field::at(int x, int y) const {
    if(y < 0 || y >= this->size()) { return false; }

    return QVector<Row>::at(y).at(x);
}

bool& Field::at(int x, int y) {
    return (*this)[y][x];
}

std::size_t Field::neighbours(int x, int y) const {
    y %= this->size();
    if(this->size() > 0) { x %= (*this)[0].size(); }

    std::size_t neighbours{};
    for(int sx = x - 1; sx <= x + 1; ++sx) {
        for(int sy = y - 1; sy <= y + 1; ++sy) {
            if(sx == x && sy == y) { continue; }
            if(this->at(sx, sy)) { ++neighbours; }
        }
    }

    return neighbours;
}
