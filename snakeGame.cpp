#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

bool gameover;
const int width = 32;
const int height= 32;
int x,y,pointx, pointy,score=0;
enum edirection{STOP=0,LEFT,RIGHT,UP,DOWN};
edirection dir;

void setup()

    {
            gameover = false;
            dir=STOP;
            x=width/2;
            y=height/2;
            pointx= rand()%20;
            pointy= rand()%20;
            
    }
    
void draw()
    {
            system("cls");
           
            for(int i = 0;i<20;i++)
            cout<<"#";
            cout<<endl;
            
                    for(int i=0;i<20;i++)
                        {

                                for(int j=0; j<20;j++)
                                    {
                                        if(j==0)
                                            cout<<"#";
                                        if (i==y && j==x)
                                            cout<< "O";
                                        else if(i==pointy && j==pointx)
                                            cout<<"X";
                                        else
                                            cout<<" ";

                                        if (j==19)
                                            cout<<"#";    

                                    }
                            cout<<endl;        

                        }

            for(int k=0;k<20;k++)
            {
                cout<<"#";
            }
        cout<<endl<<"SCORE:   "<<score;
    } 
void input()

    {
            if(_kbhit())
            {
                    switch(_getch())
                    {

                        case 'a': 
                            dir=LEFT;
                            break;
                        case 'd':
                            dir=RIGHT;
                            break;
                        case 's':
                            dir=DOWN;
                            break;
                        case 'w':
                            dir=UP;
                            break;
                        case 'x':
                            gameover= true;
                            break;
                    }
            }

    }


void logic()
    {
        switch(dir)
        {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            default:
                break;
        }

        
            if (x==pointx && y==pointy)
            {
              score+=10; 
              pointx= rand()%20;
            pointy= rand()%20;
            }
            
        
        
        
        if(x>20 || x< 0 || y> 20 || y<0)
            gameover = true;

       
    }



int main()
    {
        setup();

        
       
         while(!gameover)
           {
                draw();
                input();
                logic(); 
               // Sleep(20);
           }

           if (gameover = true)
           {
               cout<<endl<<"\nGAME OVER"<<endl;
               
               cout<<"\nSCORE"<<score;
                    Sleep(5000);
           }
        
        return 0;
    
    }
