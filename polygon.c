#include "primlib.h"
#include <stdlib.h>
#include <math.h>

#define VERTEX_NO 4
#define FPS_RATE 120


int main(int argc, char* argv[])
{
	float alpha;
	int i, RADIUS, rotation = 0;
	float center_x, center_y, old_x, old_y, new_x, new_y;
        int isKeyDown(int key);
	
	if(initGraph())
	{
		exit(3);
	}

        
	center_x = screenWidth()/2;
	center_y = screenHeight()/2;
        
        
	if(VERTEX_NO < 3)
            {
                filledRect(0, 0, screenWidth() - 1, screenHeight() - 1, BLACK);
                textout(center_x - 50, center_y, "TOO LESS VERTICES", RED);
                getkey();
            }

        else{
                alpha = 2 * M_PI / VERTEX_NO;
            
                

                
                RADIUS = 100;
                
                
                while(1)
                {

                        filledRect(0, 0, screenWidth() - 1, screenHeight() - 1, BLACK);
                    
                        old_x = center_x + RADIUS * cos(rotation*M_PI/180);
                        old_y = center_y + RADIUS * sin(rotation*M_PI/180);
                        
                        for(i = 1; i <= VERTEX_NO; i++)
                        {
                        
                        new_x = center_x + RADIUS * cos(i * alpha + rotation*M_PI/180);
                        new_y = center_y + RADIUS * sin(i * alpha + rotation*M_PI/180);

                        line(old_x, old_y, new_x, new_y, RED);

                        old_x = new_x;
                        old_y = new_y;
                        }
                        
                        updateScreen();
                        
                        if(isKeyDown(SDLK_RIGHT))
                        {
                            rotation += 1;
                            if(rotation == 360)
                                rotation = 0;
                        }

                        
                        if(isKeyDown(SDLK_LEFT))
                        {
                            rotation -= 1;
                            if(rotation == 0)
                                rotation = 360;
                        }


                        if(isKeyDown(SDLK_UP))
                        {
                            RADIUS += 1;
                            if(RADIUS > 200)
                                RADIUS = 200;
                        }
                        

                        if(isKeyDown(SDLK_DOWN))
                        {
                            RADIUS -= 1;
                            if(RADIUS < 50)
                                RADIUS = 50;
                        }                
                            
                        
                        SDL_Delay(1000 / FPS_RATE);

                }
            }
        
	
	return 0;
}
