
// #include <iostream>
#include <raylib.h>
#include <string>
#include "stack.hpp"
#include <vector>

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

int no_disk;


//we are storing moves in "move" sturcture so that we can show it later on the screen
struct Move   // dont use small move it is an default argument
{
    int from;
    int to;
};

vector<Move> moves; // we are creating a vector of objects from structure move

void hanoi(int n, int from , int to , int aux) //this recurtion will run and solve hanoi completely storing moves in moves vector
{
    if(n==0)
        return;
    hanoi(n-1, from, aux ,to );
    moves.push_back({from,to});
    hanoi(n-1,aux,to, from);
    
}


void drawDisks(stack temp, int tower_x)
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

            int scale;
            if (no_disk>=6)
                scale=20;
            else
                scale=30;
                
            int disk_radius = label * scale;
            // position based on slot index, not label value
            float y = 620 - (count - 1 - i) * 35;  
            Rectangle disk = {(float)(tower_x - disk_radius + tower_width/2),y, (float)(2*disk_radius), 40.0f};

            //shadow of rectangle
            Rectangle shadow = {disk.x + 3, disk.y + 3, disk.width, disk.height};
            DrawRectangleRounded(shadow, 1, 30, DARKGRAY);

            //actual rectangle
            DrawRectangleRounded(disk, 1, 30, BLUE);
            DrawRectangleRoundedLines(disk,0.99f,25,BLACK);
            DrawText(to_string(label).c_str(),tower_x+5,y+10, 20, BLACK);
        }
}

int main() // codes inside main
{
    
    cout<<"Give numbers of disk on origin tower:";
    cin>>no_disk;

    hanoi(no_disk,0,2,1); //original =0 , destination = 2, auxillary =1

    // int max_radius=150;
    // int min_radius=30;

    // float diff_rad=(max_radius-min_radius)/no_disk-1;

    stack tower[3];  //initialize three towers

    // 0 = first , 1 = second and 2 = third
    tower[0]=stack(no_disk); // use constructor function to initialize tower 0 with required no of disk
    tower[1]=stack(); // 0 no of disk
    tower[2]=stack();

    int move_counter=0;



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
        drawDisks(tower[0],first_x);
        drawDisks(tower[1],second_x);
        drawDisks(tower[2],third_x);

        //drwing moves


        if(IsKeyPressed(KEY_ENTER) && move_counter<(int)moves.size()) // move counter is one digit smaller then moves.size
        {
            Move m= moves[move_counter++]; //creating an Move structure object which will be assigned to a step from moves object
            int disk_number=tower[m.from].pop(); //obj.function();
            tower[m.to].push(disk_number);
        }

        //drawing no of moves
        DrawText(("Move: " + to_string(move_counter) + "/" + to_string(moves.size())).c_str(), 10, 10, 50, BLACK);
        DrawText(("Move: " + to_string(move_counter) + "/" + to_string(moves.size())).c_str(), 5, 5, 50, YELLOW);

        EndDrawing(); //after enddraing is executed then only all graphics is drawn 


        //drawing instructions
        DrawText("Press Enter to view the next move",280-2, 715-2, 40 , GRAY );
        DrawText("Press Enter to view the next move",280, 715, 40 , BLACK );
       
    }
    CloseWindow();
}