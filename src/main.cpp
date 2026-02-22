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
        int tower_y=250;
        int tower_height=400;
        int tower_width=20;

        int first_x=tower_gap+75;
        int second_x=2*tower_gap+100;
        int third_x=3*tower_gap+125;

        DrawRectangle(first_x,tower_y,tower_width,tower_height,BLACK); //origin tower
        DrawRectangle(second_x,tower_y,tower_width,tower_height,BLACK); //mid tower
        DrawRectangle(third_x,tower_y,tower_width,tower_height,BLACK); //destination tower

        int disk_radius=100;
        Rectangle disk = {(float)(first_x - disk_radius + tower_width/2), 650-30 , (float)(2*disk_radius), 30.0f };
        DrawRectangleRounded(disk ,0.5f ,12 , BLUE);
        
        EndDrawing(); //after enddraing is executed then only all graphics is drawn 
    }

    CloseWindow();
}