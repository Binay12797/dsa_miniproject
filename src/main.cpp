#include <iostream>
#include <raylib.h>

using namespace std;

int width=800, height=800;

int main() // codes inside main
{
    InitWindow(width, height, "Tower of Hanoi");
    SetTargetFPS(60);

    while(WindowShouldClose()==false)  //WindowShouldClose is an important function
    {
        BeginDrawing();
        ClearBackground(GREEN); // will clear background every frame and fill with give background colour
       
        
        EndDrawing(); //after enddraing is executed then only all graphics is drawn
    }

    CloseWindow();
}