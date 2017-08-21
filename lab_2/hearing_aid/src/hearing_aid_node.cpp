#include "ros/ros.h"
#include "std_msgs/String.h"
#include <algorithm>
#include <string>


/**************************************************
 *
 * NOTE THAT WE ADDED THE HEADERS THAT YOU NEED.
 *
 **************************************************/
#include "std_srvs/SetBool.h"
#include <queue>

// Global flag to know if power is on.
bool powerOn = false;
std::queue<std::string> chatterQueue;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	/*******************************************
	 *
	 * QUEUE THE MESSAGE FOR HANDLING.
	 * ONLY CAPITALIZE AND OUTPUT IF POWER ON.
	 *
	 *******************************************/
std::string input=msg->data.c_str();
transform(input.begin(), input.end(), input.begin(), ::toupper);

    chatterQueue.push(input);



    
}

/***************************************************
 *
 * ADD CALLBACK FOR HANDLING POWER ON SERVICE.
 *
 ***************************************************/
bool po(std_srvs::SetBool::Request  &req,
         std_srvs::SetBool::Response &res)
{
    powerOn=req.data;
    return true;
}



int main(int argc, char **argv)
{
	ros::init(argc, argv, "hearing_aid");

	ros::NodeHandle node;

	ros::Subscriber chatterSub = node.subscribe("chatter", 1000, chatterCallback);

	/*******************************************
	 *
	 * SETUP SERVICE TO TURN POWER ON.
	 * USE STANDARD SET_BOOL SERVICE MESSAGE.
	 *
	 *******************************************/
    ros::ServiceServer service = node.advertiseService("power",po);


	/**********************************************
	 *
	 * SETUP PUBLISHER FOR NEW "hearing_aid" TOPIC.
	 *
	 **********************************************/
    ros::Publisher chatter_pub = node.advertise<std_msgs::String>("hearing_aid", 1000);


	ros::Rate loop_rate(10);

	while (ros::ok())
	{
		/**********************************************
		 *
		 * HANDLE  QUEUE OF MESSAGES IF POWER IS ON.
		 * MAKE THEM ALL CAPS AND PUBLISH ON NEW TOPIC.
		 *
		 **********************************************/
if(powerOn==true)
{
    if(!chatterQueue.empty())
    {
        std::string s=chatterQueue.front();
        chatterQueue.pop();
        std_msgs::String publish_msg;
        publish_msg.data=s;
        chatter_pub.publish(publish_msg);
    }
}
		ros::spinOnce();

		loop_rate.sleep();
	}

	return 0;
}
