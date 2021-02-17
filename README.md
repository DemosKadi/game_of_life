Game of Life
======
**Game of Life** is a cellular automaton, see [Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## Dependencies
```
cmake 3.14
Qt 5.10
gcc 7 or clang 4
```

## Installation
```
$ git clone https://github.com/DemosKadi/game_of_life.git
$ cd game_of_life
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
```

## Usage
```
Usage: ./game_of_life [options] input
A simple game of life simulator

Options:
  -h, --help               Displays help on commandline options.
  --help-all               Displays help including Qt specific options.
  -v, --version            Displays version information.
  -W, --width <width>      Set width of the simulation
  -H, --height <height>    Set height of the simulation
  -t, --time <time>        Time between simulation steps in ms
  -x, --xoffset <xoffset>  Input offset for x axis (starts top left)
  -y, --yoffset <yoffset>  Input offset for y axis (starts top left)

Arguments:
  input                    Initial setup of the simulation
```

## Example
```
$ ./game_of_life ../examples/glider
```
