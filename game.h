#ifndef GAME_H
#define GAME_H

#include "field.h"

class Game {
public:
    Game(std::size_t width,
        std::size_t height,
        const Field& initial,
        std::size_t xoffset,
        std::size_t yoffset);

    bool is_empty() const;

    void tick();
    void print();

private:
    Field field;
};

#endif
