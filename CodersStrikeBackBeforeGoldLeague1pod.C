#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{

    // game loop
      int once=0;
      int previousX=0;
      int previousY=0;
    while (1) {
        int x;
        int y;
        // x position of the next check point
        int next_checkpoint_x;
        // y position of the next check point
        int next_checkpoint_y;
        // distance to the next checkpoint
        int next_checkpoint_dist;
        // angle between your pod orientation and the direction of the next checkpoint
        int next_checkpoint_angle;
        scanf("%d%d%d%d%d%d", &x, &y, &next_checkpoint_x, &next_checkpoint_y, &next_checkpoint_dist, &next_checkpoint_angle);
        int opponent_x;
        int opponent_y;
        scanf("%d%d", &opponent_x, &opponent_y);
        int thrust;
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        if (next_checkpoint_angle>90||next_checkpoint_angle<-90){
           thrust = 0;}
        else {
        thrust=100;
        } 
        int velocity_x=x-previousX;
        int velocity_y=y-previousY;
        int factor=2;
            /*well, the first thing i'd suggest is to calculate your velocity
by storing your previous location
velocity_x = current_x - previous_x
same with y
then instead of targeting the checkpoint, target
checkpoint - velocity
this auto corrects for drift and turn.  It is part of a concept called "PID Controllers"
Here is an example of another game where steering is just based on target location (first link) and then corrected by subtracting speed (second link)

*/
        if ((once<1) && (next_checkpoint_dist>600 || next_checkpoint_angle==180)){
        printf("%d %d BOOST\n", (next_checkpoint_x-(factor*velocity_x)), (next_checkpoint_y-(factor*velocity_y)));
             once++;}
        else{printf("%d %d %d\n", (next_checkpoint_x-(factor*velocity_x)), (next_checkpoint_y-(factor*velocity_y)), thrust);}
        previousX=x;
        previousY=y;  
        

    }
    }
