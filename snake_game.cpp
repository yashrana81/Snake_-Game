#include<bits/stdc++.h>
#include<time.h>
#include<conio.h>
using namespace std;
bool gameOver;
const int width = 20 ;
const int height = 20 ;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int nTail;
enum direction
{
	STOP = 0,LEFT,RIGHT,UP,DOWN
};
direction dir;
 // Initial setup for game 
void setup()
{
   gameOver = false;
   dir = STOP;
   x = width / 2;
   y = width / 2;
   srand(time(0));
   fruitX = rand() % width;
   fruitY = rand() % width;
   score = 0;
}
 // board for game 
void draw()
{
	system("cls"); // to clear screen 
	for(int i = 0 ;i<width + 4 ;i++)  //first horizontal wall for game 
	{
		cout  << '|';
	}
	cout << endl;
    
    for(int i = 0 ;i < height ;i++)          //side vertical wall for game 
    {
    	for(int j = 0;j<width;j++)
    	{
    		if(j == 0)  
    			cout << "||";
    			
    		if(i == y && j == x)
    		{
    			cout << "O";
			}
            else if(i == fruitX && j == fruitY)
            {
            	cout << "F";
			}
			else
    		    cout << " ";

    		if(j == width-1)
    		{
    			cout << "||";
    		}
    	}
    	cout << endl;
    }


    for(int i =0 ;i< width +4;i++)         //last horizontal wall for game 
    {
    	cout  << '|';
    }

    cout << endl;
    cout << "score = " << score << endl ;


}

void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
			    dir = LEFT;
			    break;
			case 'd' :
                dir = RIGHT;
                break;
            case 'w' :
                dir = UP;
                break;
            case 's' :
                dir = DOWN;
                break;
            default :
                gameOver = false;
                break;
		}
	}
}

void Logic()
{
	switch(dir)
	{
		/*case STOP: 

		    break;*/
		case UP :
		    y--;
		    break;
		case DOWN :
		    y++;
		    break;
		case RIGHT :
		    x++;
		    break;
		case LEFT :
		    x--;
		    break;
		default:
		  break;
	}
	if(x > width || x < 0 || y < 0 || y > height)
	{
		gameOver = true;
	}
	if(x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
int main()
{
  setup();
  while(!gameOver)
  {
  	draw();
  	input();
  	Logic();
  }

  return 0;
}
