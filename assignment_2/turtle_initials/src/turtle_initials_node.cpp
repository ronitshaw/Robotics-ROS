#include "ros/ros.h"
#include <string>
#include <geometry_msgs/Twist.h>
#include <turtlesim/SetPen.h>

/********************************
 *
 * ADD ADDITIONAL HEADERS HERE.
 *
 ********************************/

/***************************
 *
 * ADD ANY CALLBACKS HERE.
 *
 ***************************/


int main(int argc, char **argv)
{
	// Initialize the node.
	ros::init(argc, argv, "turtle_initials_node");
	ros::NodeHandle node;

	// Sleep on startup for 1 second.
    ros::Rate startup(1);
    startup.sleep();

	// Loop at 10Hz, publishing commands.
    ros::Rate rate(1);

	/***************************************
	 *
	 * SETUP TOPIC AND SERVICE CONNECTIONS.
	 *
	 ***************************************/

    ROS_INFO("STARTING TURTLE INITIALS CONTROL.");

    ros::Publisher chatter_pub = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
    geometry_msgs::Twist msg;
    ros::ServiceClient client = node.serviceClient<turtlesim::SetPen>("turtle1/set_pen");
    turtlesim::SetPen srv;
 double pi=3.14285714285714;
    ROS_INFO("STARTING TURTLE INITIALS CONTROL.");
int count=0;
while (ros::ok())
{
    while (count!=3) {
rate.sleep();
                srv.request.r=255;
                srv.request.g=255;
                srv.request.b=255;
                srv.request.width=0;
                srv.request.off=1;
                client.call(srv);
            rate.sleep();

   msg.linear.x = 0.0;
   msg.linear.y=0.0;
   msg.linear.z=0.0;
   msg.angular.x=0.0;
   msg.angular.y=0.0;
   msg.angular.z=-pi/2;
chatter_pub.publish(msg);
rate.sleep();

msg.linear.x = 3;
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
msg.angular.z=-pi/2;
chatter_pub.publish(msg);
rate.sleep();

msg.linear.x =4.0;
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
msg.angular.z=-pi/2;
chatter_pub.publish(msg);
rate.sleep();

            srv.request.r=255;
            srv.request.g=255;
            srv.request.b=255;
            srv.request.width=0;
            srv.request.off=0;
            client.call(srv);
            rate.sleep();

msg.linear.x = 7.0;
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
msg.angular.z=-1.57;
chatter_pub.publish(msg);
rate.sleep();


msg.linear.x = 3.0;
msg.linear.y=0.0;
msg.linear.z=0.0;
msg.angular.x=0.0;
msg.angular.y=0.0;
msg.angular.z=-1.4;
chatter_pub.publish(msg);
rate.sleep();

msg.linear.x = 3.0;
msg.linear.y=0.0;
msg.linear.z=0.0;
msg.angular.x=0.0;
msg.angular.y=0.0;
msg.angular.z=-1.4;
chatter_pub.publish(msg);
rate.sleep();


msg.linear.x = 0.7;
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
msg.angular.z=1.77;
chatter_pub.publish(msg);
rate.sleep();


msg.linear.x = 3;
msg.linear.y=0.0;
msg.linear.z=0.0;
msg.angular.x=0.0;
msg.angular.y=0.0;
msg.angular.z=0.0;
chatter_pub.publish(msg);
rate.sleep();

            srv.request.r=255;
            srv.request.g=255;
            srv.request.b=255;
            srv.request.width=0;
            srv.request.off=1;
            client.call(srv);
            rate.sleep();


  msg.linear.x = 0.0;
  msg.linear.y=0.0;
   msg.linear.z=0.0;
   msg.angular.x=0.0;
    msg.angular.y=0.0;
 msg.angular.z=1.03;
  chatter_pub.publish(msg);
  rate.sleep();


  msg.linear.x = 1.5;
  msg.linear.y=0.0;
  msg.linear.z=0.0;
  msg.angular.x=0.0;
  msg.angular.y=0.0;
  msg.angular.z=0.0;
  chatter_pub.publish(msg);
  rate.sleep();

                  srv.request.r=255;
                  srv.request.g=255;
                  srv.request.b=255;
                  srv.request.width=0;
                  srv.request.off=0;
                  client.call(srv);
                  rate.sleep();


  msg.linear.x = 0.1;
  msg.linear.y=0.0;
 msg.linear.z=0.0;
   msg.angular.x=0.0;
 msg.angular.y=0.0;
  msg.angular.z=3.14;
   chatter_pub.publish(msg);
    rate.sleep();

    msg.linear.x = 0.1;
    msg.linear.y=0.0;
   msg.linear.z=0.0;
     msg.angular.x=0.0;
   msg.angular.y=0.0;
    msg.angular.z=3.14;
     chatter_pub.publish(msg);
      rate.sleep();

      srv.request.r=255;
      srv.request.g=255;
      srv.request.b=255;
      srv.request.width=0;
      srv.request.off=1;
      client.call(srv);
      rate.sleep();



      msg.linear.x = 1.5;
      msg.linear.y=0.0;
      msg.linear.z=0.0;
      msg.angular.x=0.0;
      msg.angular.y=0.0;
      msg.angular.z=0.0;
      chatter_pub.publish(msg);
      rate.sleep();





      srv.request.r=255;
      srv.request.g=255;
      srv.request.b=255;
      srv.request.width=0;
      srv.request.off=0;
      client.call(srv);
      rate.sleep();


      msg.linear.x = 0.0;
      msg.linear.y=0.0;
      msg.linear.z=0.0;
      msg.angular.x=0.0;
      msg.angular.y=0.0;
      msg.angular.z=-0.4;
      chatter_pub.publish(msg);
      rate.sleep();

      /*msg.linear.x = 1.3;
      msg.linear.y=0.0;
      msg.linear.z=0.0;
      msg.angular.x=0.0;
      msg.angular.y=0.0;
      msg.angular.z=0.0;
      chatter_pub.publish(msg);
      rate.sleep();*/

      msg.linear.x =5;
      msg.linear.y=0.0;
      msg.linear.z=0.0;
      msg.angular.x=0.0;
      msg.angular.y=0.0;
      msg.angular.z=3.14;
      chatter_pub.publish(msg);
      rate.sleep();

      msg.linear.x = 0.5;
      msg.linear.y=0.0;
      msg.linear.z=0.0;
      msg.angular.x=0.0;
      msg.angular.y=0.0;
      msg.angular.z=0.2;
      chatter_pub.publish(msg);
      rate.sleep();


      msg.linear.x =6.2;
      msg.linear.y=0.0;
      msg.linear.z=0.0;
      msg.angular.x=0.0;
      msg.angular.y=0.0;
      msg.angular.z=-3.4;
      chatter_pub.publish(msg);
      rate.sleep();

   /*   msg.linear.x = 1;
      msg.linear.y=0.0;
      msg.linear.z=0.0;
      msg.angular.x=0.0;
      msg.angular.y=0.0;
      msg.angular.z=0.0;
      chatter_pub.publish(msg);
      rate.sleep();*/

      msg.linear.x = 0.0;
      msg.linear.y=0.0;
      msg.linear.z=0.0;
      msg.angular.x=0.0;
      msg.angular.y=0.0;
      msg.angular.z=0.36;
      chatter_pub.publish(msg);
      rate.sleep();

      srv.request.r=255;
      srv.request.g=255;
      srv.request.b=255;
      srv.request.width=0;
      srv.request.off=1;
      client.call(srv);
      rate.sleep();

      msg.linear.x = 1;
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
      msg.angular.z=-1.57;
      chatter_pub.publish(msg);
      rate.sleep();

      msg.linear.x =6.5;
      msg.linear.y=0.0;
      msg.linear.z=0.0;
      msg.angular.x=0.0;
      msg.angular.y=0.0;
      msg.angular.z=0.0;
      chatter_pub.publish(msg);
      rate.sleep();

      srv.request.r=255;
      srv.request.g=255;
      srv.request.b=255;
      srv.request.width=0;
      srv.request.off=0;
      client.call(srv);
      rate.sleep();

      msg.linear.x = 0.1;
      msg.linear.y=0.0;
     msg.linear.z=0.0;
       msg.angular.x=0.0;
     msg.angular.y=0.0;
      msg.angular.z=3.14;
       chatter_pub.publish(msg);
        rate.sleep();

        msg.linear.x = 0.1;
        msg.linear.y=0.0;
       msg.linear.z=0.0;
         msg.angular.x=0.0;
       msg.angular.y=0.0;
        msg.angular.z=3.14;
         chatter_pub.publish(msg);
          rate.sleep();

          srv.request.r=255;
          srv.request.g=255;
          srv.request.b=255;
          srv.request.width=0;
          srv.request.off=1;
          client.call(srv);
          rate.sleep();

          msg.linear.x = -1;
          msg.linear.y=0.0;
         msg.linear.z=0.0;
           msg.angular.x=0.0;
         msg.angular.y=0.0;
          msg.angular.z=-1.0;
           chatter_pub.publish(msg);
            rate.sleep();

 ros::spinOnce();
rate.sleep();
count =3;

    }





    msg.linear.x = 0.1;
    msg.linear.y=0.0;
   msg.linear.z=0.0;
     msg.angular.x=0.0;
   msg.angular.y=0.0;
    msg.angular.z=3.14;
     chatter_pub.publish(msg);
      rate.sleep();

ros::spinOnce();
rate.sleep();


}


    // Print the start of the control.

	// Loop while ROS is okay.
    /*while (ros::ok())
	{
		/*************************************************
		 *
		 * SET UP STATE MACHINE FOR CONTROLING TURTLESIM.
		 *
		 *************************************************/
/*
		// Allow for processing incoming messages.
		ros::spinOnce();

		// Sleep to control the rate of publishing.
		rate.sleep();
    }*/
}
