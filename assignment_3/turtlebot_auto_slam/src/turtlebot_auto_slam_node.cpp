#include "ros/ros.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>



int flag=0;
int pos;

 double pi=3.14285714285714;

void processLaserScan(const sensor_msgs::LaserScan::ConstPtr& scan){
     //scan->ranges[] are laser readings
    //int minIndex = ceil((MIN_SCAN_ANGLE_RAD - scan->angle_min) / scan->angle_increment);
    int minIndex=0;
    int maxIndex =sizeof(scan->ranges);
int j=0;
    float closestRange = scan->ranges[minIndex];


    for (int currIndex = minIndex + 1; currIndex <= (maxIndex/2); currIndex++)
    {
        if (scan->ranges[currIndex] < closestRange) {
            closestRange = scan->ranges[currIndex];
            j=currIndex;
        }
    }


    if (closestRange < 0.6) {

        flag=1;
        pos=2*j/maxIndex;
    }
    else
    {
closestRange = scan->ranges[(maxIndex/2)+ 1];
j=(maxIndex/2)+ 1;
    for (int currIndex = (maxIndex/2)+ 2; currIndex < (maxIndex); currIndex++)
    {
        if (scan->ranges[currIndex] < closestRange) {
            closestRange = scan->ranges[currIndex];
            j=currIndex;
        }
    }
    if (closestRange < 0.6) {

        flag=2;
        pos=(j-(maxIndex/2)+ 1)/(maxIndex/2);
    }

}


}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlebot_auto_slam_node");

  ros::NodeHandle nh;

  /*************************************
   *
   * FILL IN YOUR FUNCTIONALITY HERE.
   *
   *************************************/
  ros::Subscriber scanSub;
  scanSub=nh.subscribe<sensor_msgs::LaserScan>("/scan",10,processLaserScan);


  ros::Rate rate(1);

  ros::Publisher chatter_pub = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1000);
  geometry_msgs::Twist msg;

int c=0;

while (ros::ok())
{





   if(flag==0)
   {

       rate.sleep();

       msg.linear.x =0.2;
       msg.linear.y=0.0;
       msg.linear.z=0.0;
       msg.angular.x=0.0;
       msg.angular.y=0.0;
       msg.angular.z=0.0;
    chatter_pub.publish(msg);
    rate.sleep();



   }

   if(flag==1)
   {

       rate.sleep();
       msg.linear.x =-0.1;
       msg.linear.y=0.0;
       msg.linear.z=0.0;
       msg.angular.x=0.0;
       msg.angular.y=0.0;
       msg.angular.z=0.0;
    chatter_pub.publish(msg);
    rate.sleep();

       msg.linear.x =0.0;
       msg.linear.y=0.0;
       msg.linear.z=0.0;
       msg.angular.x=0.0;
       msg.angular.y=0.0;
       msg.angular.z=-(2*pi/3+pi/4);
    chatter_pub.publish(msg);
    rate.sleep();
    flag=0;

   }


   if(flag==2)
   {

       rate.sleep();
       msg.linear.x = -0.1;
       msg.linear.y=0.0;
       msg.linear.z=0.0;
       msg.angular.x=0.0;
       msg.angular.y=0.0;
       msg.angular.z=0.0;
    chatter_pub.publish(msg);
    rate.sleep();
       msg.linear.x = 0.0;
       msg.linear.y=0.0;
       msg.linear.z=0.0;
       msg.angular.x=0.0;
       msg.angular.y=0.0;
       msg.angular.z=(2*pi/3+pi/4);
    chatter_pub.publish(msg);
    rate.sleep();

flag=0;
   }
ros::spinOnce();
 rate.sleep();


  }

























  return 0;
}
