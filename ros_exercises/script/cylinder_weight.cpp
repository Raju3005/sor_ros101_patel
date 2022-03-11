#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <ros_exercises/cylinder.h>
#include <iostream>

ros::Publisher cylinder_weight_pub;

//ros_exercises::cylinder msg;
std_msgs::Float64 weight;

std_msgs::Float64 volume;
std_msgs::Float64 density;

void volume_callback(const std_msgs::Float64::ConstPtr &val){
    volume.data = val->data;
} 

void density_callback(const std_msgs::Float64::ConstPtr &val){
    density.data = val->data;
} 

void weight_calc(){
    weight.data = volume.data*density.data;
    cylinder_weight_pub.publish(weight);
}

int main (int argc, char **argv){

    ros::init(argc, argv, "cylinder_weight");
    ros::NodeHandle nh;

    cylinder_weight_pub = nh.advertise<std_msgs::Float64>("/weight",10);

    ros::Subscriber volume_sub = nh.subscribe("/volume",10,volume_callback);
    ros::Subscriber density_sub = nh.subscribe("/density",10,density_callback);
    //ros::spin();

    ros::Rate loop_rate(10);
    
    while(ros::ok())
    {
        weight_calc();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return(0);
}

