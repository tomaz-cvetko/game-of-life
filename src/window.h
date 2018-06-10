#ifndef WINDOW_HANDLER_H
#define WINDOW_HANDLER_H

class WindowHandler{
public:
    //Starts up SDL and creates window
    bool init();

    //Loads media
    bool loadMedia();

    //Frees media and shuts down SDL
    void close();
    
    //Loads individual image as texture
    SDL_Texture* loadTexture( std::string path );
    
private:
    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;
};

#endif
