#include <iostream>
#include <thread>
#include <chrono>

#include "window.h"
#include "texture.h"
#include "tile.h"
#include "helpers.h"
#include "character.h"

using namespace std; 
int main()
{
    Texture myTexture;
    vector<Tile> m;
    m.push_back(makeTile(0 ,0,Pacman, Up));
    m.push_back(makeTile(20,0,Pacman, Down));
    m.push_back(makeTile(40,0,Pacman, Left));
    m.push_back(makeTile(60,0,Pacman, Right));
    //Tile pm(0,0,{ {1,1},{1,2}, {1,1}, {1,3} }, Pacman, 1,1);
    int frame = 0;
    Character myPacman(0,0,Pacman);
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
        
       myPacman.render(&myTexture, frame);
       
      
       
     /* for(int i = 0; i < m.size(); i++)
      {
        
        m[i].render(&myTexture, frame);
         
      }*/

        SDL_RenderPresent(myTexture.myWin.sdlRenderer);
        frame++;
        this_thread::sleep_for(chrono::milliseconds(75));
    }
    
    return 0;
}
