#include "ros/ros.h"



/**************************************************
 *
 * NOTE THAT WE ADDED THE MESSAGE THAT YOU NEED.
 *
 **************************************************/
#include "std_srvs/SetBool.h"

/************************************************************
 *
 * MAKE SURE THAT THE CMAKELIST SETS UP THIS POWER NODE.
 *
 ************************************************************/

int main(int argc, char **argv)
{
	ros::init(argc, argv, "power");

	ros::NodeHandle node;
ros::ServiceClient client = node.serviceClient<std_srvs::SetBool>("power");
std_srvs::SetBool srv;
	/*******************************************
	 *
	 * SETUP CLIENT TO TURN POWER ON.
	 * USE STANDARD SET_BOOL SERVICE MESSAGE.
	 *
	 *******************************************/
	bool powerOn = false;

	ros::Rate loop_rate(10);

	while (ros::ok())
	{
		/******************************************************
		 *
		 * CHECK IF THE USER WOULD LIKE TO TURN POWER ON/OFF.
		 * USE THE USER INPUT WHEN IT COMES TO SEND A SERVICE.
		 *
		 *****************************************************/
        int input;
        ROS_INFO("Press 1 to power On, any other no to Power off");
        std::cin>>input;
        if(input==1)
        {
           powerOn=true;
        }
else
        {
            powerOn=false;
        }
        srv.request.data=powerOn;
        bool b  =client.call(srv);
		ros::spinOnce();

		loop_rate.sleep();
	}

	return 0;
}
