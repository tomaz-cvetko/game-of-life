#include "board.h"
#include <iostream>

GameOfLife::GameOfLife(int a, int b, int sc): scaling(sc), width(a/sc), height(b/sc),
    cells1(height, std::vector<bool>(width, false)), cells2(height, std::vector<bool>(width, false))
{
    
    current = &cells1;
    next = &cells2;
    
    //populate(living_cells);
//     std::srand(25);
//     if (living_cells == 0){
//         living_cells = width*height; 
//     }
//     
//     for (int i = 0; i < living_cells; ++i){
//         int xrand = std::rand()%width;
//         int yrand = std::rand()%height;
//         
//         cells1[yrand][xrand] = true;
//     }
}

void GameOfLife::populate(int living_cells)
{
    std::srand(25);
    if (living_cells == 0){
        living_cells = width*height; 
    }
    
    for (int i = 0; i < living_cells; ++i){
        int xrand = std::rand()%width;
        int yrand = std::rand()%height;
        
        cells1[yrand][xrand] = true;
    }
}

void GameOfLife::change(int x, int y)
{
    if(current == &cells1)
    {
        cells1[y/scaling][x/scaling] = (cells1[y/scaling][x/scaling]) ? false:true;
    }
    else
    {
        cells2[y/scaling][x/scaling] = (cells2[y/scaling][x/scaling]) ? false:true;
    }
}


void GameOfLife::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            if ((*current)[i][j]) {
                SDL_Rect cell = {scaling*j, scaling*i, scaling, scaling};
                SDL_RenderDrawRect(renderer, &cell);
                //SDL_RenderDrawPoint( renderer, j, i);
            }
        }
    }
}

void GameOfLife::next_generation(){
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            if ((*current)[i][j]){
                switch (living_neighbours(i, j)){
                    case 2:
                    case 3:
                        (*next)[i][j] = true;
                        break;
                    default:
                        (*next)[i][j] = false;
                }
            }
            else {
                if (living_neighbours(i, j) == 3){
                    (*next)[i][j] = true;
                }
                else {
                    (*next)[i][j] = false;
                }
            }
        }
    }
    
    std::vector<std::vector<bool> >* temp = current;
    current = next;
    next = temp;
}

int GameOfLife::living_neighbours(int i, int j){
    int count = 0;
    for (int di = -1; di < 2; ++di){
        for (int dj = -1; dj < 2; ++dj){
            try{
                if (current->at(i+di).at(j+dj)){
                    ++count;
                }
            }
            catch(std::exception){
                continue;
            }
        }
    }
    
    // if the cell itself is alive, then we counted one too many
    if (current->at(i).at(j)){
        --count;
    }
    return count;
}
