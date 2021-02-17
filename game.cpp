#include "game.h"

#include <QTextStream>

Game::Game(std::size_t width,
    std::size_t height,
    const Field& initial,
    std::size_t xoffset,
    std::size_t yoffset) {

    if(height < initial.size() + yoffset) { height = initial.size() + yoffset; }
    if(initial.size() > 0 && width < initial[0].size() + xoffset) {
        width = initial[0].size() + xoffset;
    }

    Row row(width);
    this->field.fill(row, height);

    for(std::size_t h = 0; h < initial.size(); ++h) {
        for(std::size_t w = 0; w < initial[h].size(); ++w) {
            this->field.at(w + xoffset, h + yoffset) = initial.at(w, h);
        }
    }
}

bool Game::is_empty() const {
    for(const auto& row: this->field) {
        for(const bool current: row) {
            if(current) return false;
        }
    }

    return true;
}


void Game::tick() {
    if(this->is_empty()) { return; }

    Row row(this->field[0].size());
    Field new_field(this->field.size(), row);
    for(int y = 0; y < this->field.size(); ++y) {
        for(int x = 0; x < this->field[y].size(); ++x) {
            const bool cell = this->field.at(x, y);
            const auto neighbours = this->field.neighbours(x, y);

            new_field.at(x, y) =
                (cell && (neighbours == 2 || neighbours == 3)) ||
                neighbours == 3;
        }
    }

    this->field = new_field;
}

void Game::print() {
    QTextStream qout(stdout);

    qout << '+';
    for(int i = 0; i < this->field[0].size(); ++i) {
        qout << '-';
    }
    qout << '+' << '\n';

    for(const auto& row: this->field) {
        qout << '|';
        for(const bool cell: row) {
            qout << (cell ? '0' : ' ');
        }
        qout << '|' << '\n';
    }

    qout << '+';
    for(int i = 0; i < this->field[0].size(); ++i) {
        qout << '-';
    }
    qout << '+' << '\n';
}
