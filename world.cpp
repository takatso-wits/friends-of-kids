#include "world.h"
#include "helpers.h"
#include "character.h"

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <iostream>

using namespace std;
/**
 * Constructs the World object loading a maze from the supplied file.
 * It should initialise the \ref{map} array with the relevant tiles as well
 * as the pacman and ghost objects.
 *
 * @param filename - File from which the maze should be read.
 * @param tileWidth - Width of each tile
 * @param tileHeight - Height of each tile
 */
World::World(string filename, int tileWidth, int tileHeight)
    : food(0), points(0), ready(true), pacman(5*20,9*20,Pacman)
{
    ifstream f(filename);
    if(!f.is_open())
        throw runtime_error("Couldn't open maze file " + filename);
    else
    {
      // Code to read in the file...
      f>>rows;
      f>>cols;
      string mazeLine;
      getline(f, mazeLine);
      
      for(int i = 0; i < rows; i++){
        
        getline(f,mazeLine);
        vector<Tile> tiles;
        
        for(int j = 0; j < cols; j++){
          
          switch(mazeLine[j]){
          	case 'x':
       			tiles.push_back( makeTile(j*20,i*20,Wall,Right)); 
          		break;
          
          	case ' ':
            		tiles.push_back(makeTile(j*20,i*20,Blank,Right)); 
            		break;
            
          	case '.':
            		tiles.push_back(makeTile(j*20,i*20,Food,Right));
            		food++;
           	break;
          	case '0':
            		tiles.push_back(makeTile(j*20,i*20,Blank,Right)); 
            		break;            
          	case '1':
            		tiles.push_back(makeTile(j*20,i*20,Blank,Right)); 
            		break;
            
          	case '2':
            		tiles.push_back(makeTile(j*20,i*20,Blank,Right)); 
            		break;
            
          	case '3':
            		tiles.push_back(makeTile(j*20,i*20,Blank,Right)); 
            		break;
            
          	case '4':
            		tiles.push_back(makeTile(j*20,i*20,Blank,Right)); 
            		break;
          }
        }
        maze.push_back(tiles);
        
      }
    }
 }

/**
 * Renders the World to the ::sdlRenderer buffer.
 * It calls the respective render functions on each tile first.
 * Following this, it calls the pacman and ghost objects to render
 * them above the background.
 * @param frame [optional] An optional frame number to pass to the objects to handle animation.
 */
void World::render(Texture *t, int frame)
{
	for(int i = 0; i < rows; i++){
    		for(int j = 0; j < cols; j++){
      		maze[i][j].render(t, frame);
    		}
    	}
  pacman.render(t, frame);

}

/**
 * This function is responsible for advancing the game state.
 * Pacman and the ghosts should be moved (if possible). If pacman is
 * captured by a ghost pacman.dead should be set to true. If pacman eats
 * a food pellet the relevant totals should be updated.
 *
 * @return The same value as World::ready, indicating whether the game is finished.
 */
bool World::UpdateWorld()
{
	SDL_Rect A = pacman.getNextPosition();
	
	pacman.x = A.x;
	pacman.y = A.y;
	(pacman.uTile).x = A.x;
	(pacman.uTile).x = A.x;
	(pacman.dTile).x = A.x;
	(pacman.dTile).x = A.x;
	(pacman.rTile).x = A.x;
	(pacman.rTile).x = A.x;
	(pacman.lTile).x = A.x;
	(pacman.lTile).x = A.x;
	

}
