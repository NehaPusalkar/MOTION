#include "ros/ros.h"
#include "Herkulex.h"
#include "Herkulex.cpp"

////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int motor_id[10]={4, 2, 10, 5, 7, 12, 8, 1,11,6};
//int init[10]={0,7,-5,0,0,-5,-10,2,0,0};
int init[10]={-3,0,0,0,-3,3,0,0,0,3};

int main(int argc, char **argv)
{
 HerkulexClass hc;
  for (int i=0;i<10;i++)
  hc.torqueON(motor_id[i]);

    for (int num=0; num<10; num++)
    {
     float a = (init[num]+150);
     init[num] = round(21+(a/300)*981);
    }

    for (int i=0; i<10; i++)
      {
       hc.moveOne(motor_id[i], init[i] , 1000 , 2); //motor_id, motor_angles, goal_time(from 0 to 2856ms), led_color(1=green)
       sleep(0.0007);
      }
     sleep(2);
     std::cout<<"done"<<std::endl;

  
 hc.Close();
 return 0;
}


