#include <ros/ros.h>
#include <std_msgs/Float64.h>

ros::Publisher radius_squarer_pub;

void callback(std_msgs::Float64 data){

    std_msgs::Float64 radius;
    std_msgs::Float64 squared_radius;

    radius.data = data.data;
    squared_radius.data = radius.data*radius.data;

    radius_squarer_pub.publish(squared_radius);
}

int main (int argc, char **argv){

    ros::init(argc, argv, "radius_squarer");
    ros::NodeHandle nh;

    radius_squarer_pub = nh.advertise<std_msgs::Float64>("/squared_radius",10);

    ros::Subscriber radius_sub = nh.subscribe("/radius",10,callback);
    ros::spin();

    return(0);
}
