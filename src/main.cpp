
// #include <iostream>
#include <raylib.h>
#include <string>
#include "stack.hpp"

// using namespace std;  we dont have to use this as stack.hpp already uses them

int width=1280, height=800;

int platform_length=1080;
int tower_gap=platform_length/4;
int tower_y=250;
int tower_height=400;
int tower_width=20;

int first_x=tower_gap;
int second_x=2*tower_gap+100;
int third_x=3*tower_gap+200;



void drawDisks(stack temp, int tower_x)
{
    
    while(!temp.isEmpty())
    {  
        int disk_label[MAX];
        int count = 0;
        while(!temp.isEmpty())
        {
            disk_label[count++] = temp.pop();
        }

        // draw from bottom of array (largest disk) upward
        for(int i = count-1; i >= 0; i--)
        {
            int label = disk_label[i];
            int disk_radius = label * 30;
            // position based on slot index, not label value
            float y = 620 - (count - 1 - i) * 30;  
            Rectangle disk = {(float)(tower_x - disk_radius + tower_width/2),y, (float)(2*disk_radius), 30.0f};
            DrawRectangleRounded(disk, 0.5f, 12, BLUE);
            DrawText(to_string(label).c_str(), tower_x - disk_radius + tower_width/2,y, 20, BLACK);
        }
    }
}

int main() // codes inside main
{
    int no_disk;
    cout<<"Give numbers of disk on origin tower:";
    cin>>no_disk;

    // int max_radius=150;
    // int min_radius=30;

    // float diff_rad=(max_radius-min_radius)/no_disk-1;

    stack first(no_disk); // will automatically assign lables

    stack second;
    stack third;


    InitWindow(width, height, "Tower of Hanoi");
    SetTargetFPS(60);

    while(WindowShouldClose()==false)  //WindowShouldClose is an important function
    {
       
        BeginDrawing();
        ClearBackground(GREEN); // will clear everything drawin in previous loop
        //drawing part

        
        DrawRectangle(100,650,platform_length,40,BLACK); //rectangle for base

        
        DrawRectangle(first_x,tower_y,tower_width,tower_height,BLACK); //origin tower
        DrawRectangle(second_x,tower_y,tower_width,tower_height,BLACK); //mid tower
        DrawRectangle(third_x,tower_y,tower_width,tower_height,BLACK); //destination tower

        //drawing for first tower
        drawDisks(first,first_x);
        drawDisks(second,second_x);
        drawDisks(third,third_x);
        
        EndDrawing(); //after enddraing is executed then only all graphics is drawn 
        
    }
    CloseWindow();
}