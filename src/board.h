#ifndef GAMEOFLIFE_BOARD_H
#define GAMEOFLIFE_BOARD_H

#include <vector>
#include <cstdlib>
#include <exception>

#include <SDL.h>

class GameOfLife {
public:
    GameOfLife(int a, int b, int scaling = 1);
    
    void populate(int living_cells = 0);
    
    void draw(SDL_Renderer* renderer);
    
    void next_generation();
    
    void change(int x, int y);
    
private:
    int living_neighbours(int i, int j);
    
    const int scaling;
    const int width;
    const int height;
    std::vector<std::vector<bool> > cells1;    
    std::vector<std::vector<bool> > cells2;
    std::vector<std::vector<bool> > * current = nullptr;
    std::vector<std::vector<bool> >* next = nullptr;
};

#endif
