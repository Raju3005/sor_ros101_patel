#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32.h>
#include <geometry_msgs/Point32.h>
#include <turtlesim/Pose.h>
#include <iostream>
#include <string>
#include <cmath>

ros::Publisher guide_turtle_to_xy_pub;

std_msgs::Float64 pose_x;
std_msgs::Float64 pose_y;
std_msgs::Float64 pose_theta;

const float PI = 3.14159265;

float pos_x;
float pos_y;
float target_pos_x;
float target_pos_y;
float alpha;
float angle;

float i{0};

geometry_msgs::Twist msg;


void callback(const turtlesim::Pose &val){
    pose_x.data = val.x;
    pose_y.data = val.y;
    pose_theta.data = val.theta;
}

void turn_and_run_turtle(){

    alpha = atan((pos_y-pose_y.data)/(pos_x-pose_x.data));

    if(pos_x<pose_x.data && pos_y<pose_y.data)
    {
        alpha = (1*alpha)-PI;
    }
     else if(pos_x<pose_x.data && pos_y>pose_y.data)
    {
        alpha = alpha+(PI);
    }

    ros::param::get("/pos_x", pos_x);
    ros::param::get("/pos_y", pos_y);

    target_pos_x = pos_x + 0.1;
    target_pos_y = pos_y + 0.1;

    if((pose_theta.data<alpha && i==0) || (pose_theta.data>alpha && i==0))
    {           
        msg.angular.z = (alpha-pose_theta.data)*0.5;
        guide_turtle_to_xy_pub.publish(msg);
        ROS_INFO("Current angle is: %f ",pose_theta.data);
        ROS_INFO("Target angle is: %f ",alpha);
    }    
    if(pose_theta.data == alpha)
    {
        i=1;
        std::cout << "Rotation done." << "             " << i << std::endl;
    }
    
    if((pose_x.data<pos_x && i==1) || (pose_x.data>pos_x && i==1))
    {

        if(pos_x>pose_x.data)
        {
            msg.linear.x = (pos_x-pose_x.data)*0.3;
        }
        else if(pos_x<pose_x.data)
        {
            msg.linear.x = -(pos_x-pose_x.data)*0.3;
        }
        
        guide_turtle_to_xy_pub.publish(msg);
        ROS_INFO("Current position at X is: %f ",pose_x.data);
        ROS_INFO("Current position at Y is: %f ",pose_y.data);
    
        if(pose_x.data == pos_x)
        {
            i=0;
            //ros::Duration(1).sleep();
            std::cout << i << std::endl;
        }
    }
}

int main (int argc, char **argv){

    ros::init(argc, argv, "turtle_guide_to_xy");
    ros::NodeHandle nh;

    guide_turtle_to_xy_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);

    ros::Subscriber pose_sub = nh.subscribe("/turtle1/pose",10,callback);

    ros::Rate rate(10);

    while(ros::ok())
    {

        turn_and_run_turtle();
        ros::spinOnce();
        rate.sleep();
    }

return(0);
}