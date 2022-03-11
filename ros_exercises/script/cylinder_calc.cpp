#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <ros_exercises/cylinder.h>

#include <iostream>


ros::Publisher cylinder_pub;

ros::Publisher cylinder_volume_pub;
std_msgs::Float64 volume;

//ros_exercises::cylinder msg;

std_msgs::Float64 radius;
std_msgs::Float64 squared_radius;
std_msgs::Float64 height;

void radius_callback(const std_msgs::Float64::ConstPtr &val){
    radius.data = val->data;
    //std::cout << radius << std::endl;
}

void height_callback(const std_msgs::Float64::ConstPtr &val){
    height.data = val->data;
} 

void squared_radius_callback(const std_msgs::Float64::ConstPtr &val){
    squared_radius.data = val->data;
}

void calculate(){
     
        ros_exercises::cylinder msg;

        msg.volume = 3.14*squared_radius.data*height.data;
        msg.surface_area = 2*3.14*squared_radius.data + 2*3.14*radius.data*height.data;
        cylinder_pub.publish(msg);

        volume.data = 3.14*squared_radius.data*height.data;
        cylinder_volume_pub.publish(volume);
}

int main (int argc, char **argv){

    ros::init(argc, argv, "cylinder_calc");
    ros::NodeHandle nh;

    cylinder_pub = nh.advertise<ros_exercises::cylinder>("/cylinder",10);

    cylinder_volume_pub = nh.advertise<std_msgs::Float64>("/volume",10);
 
    ros::Subscriber height_sub = nh.subscribe("/height",10,height_callback);
    //ros::spin();
    ros::Subscriber radius_sub = nh.subscribe("/radius",10,radius_callback);
    //ros::spinOnce();
    ros::Subscriber squared_radius_sub = nh.subscribe("/squared_radius",10,squared_radius_callback);
    //ros::spin();
    
    //cylinder_pub = nh.advertise<ros_exercises::cylinder>("/cylinder",10);

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        calculate();
        ros::spinOnce();
        loop_rate.sleep();
    }
return(0);
}