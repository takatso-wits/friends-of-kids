#include <iostream>
#include <thread>
#include <chrono>

#include "window.h"
#include "texture.h"
#include "tile.h"
#include "helpers.h"

using namespace std; 
int main()
{
    Texture myTexture;
    vector<Tile> testTiles = getTestTiles();
    Tile pm(0,0,{ {1,1},{1,2}, {1,1}, {1,3} }, Pacman, 1,1);
    int frame = 0;
    // SpriteSheet Filename
    string spriteFilename = SPRITEFILENAME; // Leave this line

    myTexture.loadFile(spriteFilename, 20, 20); 
    
    // Setup and Load Texture object here
    bool quit = false;

    while(!quit){
        // Handle any SDL Events
        SDL_Event e;
        while(SDL_PollEvent(&e)){
          if(e.type == SDL_QUIT){
          quit = true;
        }
      }
        // Set background to black
        SDL_SetRenderDrawColor(myTexture.myWin.sdlRenderer, 0, 0, 0, 0xFF);
        // Clear the renderer
        SDL_RenderClear(myTexture.myWin.sdlRenderer);
        // Render the tile
        
       //pm.render(&myTexture, frame);
       
      
       
      for(int i = 0; i < testTiles.size(); i++)
      {
        
        testTiles[i].render(&myTexture, frame);
         
      }

        SDL_RenderPresent(myTexture.myWin.sdlRenderer);
        frame++;
        this_thread::sleep_for(chrono::milliseconds(75));
    }
    
    return 0;
}
