#include <iostream>
#include <raylib.h>

using namespace std;

int width=1280, height=800;

int main() // codes inside main
{
    InitWindow(width, height, "Tower of Hanoi");
    SetTargetFPS(60);

    while(WindowShouldClose()==false)  //WindowShouldClose is an important function
    {
        ClearBackground(GREEN); // will clear everything drawin in previous loop
        BeginDrawing();
        //drawing part

        int platform_length=1080;
        DrawRectangle(100,650,platform_length,40,BLACK); //rectangle for base

        int tower_gap=platform_length/4;
        int tower_x=250;
        int tower_height=400;
        DrawRectangle(tower_gap+75,tower_x,20,tower_height,BLACK); //origin tower
        DrawRectangle(2*tower_gap+100,tower_x,20,tower_height,BLACK); //mid tower
        DrawRectangle(3*tower_gap+125,tower_x,20,tower_height,BLACK); //destination tower
        
        EndDrawing(); //after enddraing is executed then only all graphics is drawn 
    }

    CloseWindow();
}