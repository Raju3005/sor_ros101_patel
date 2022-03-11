#include <ros/ros.h>
#include <std_msgs/Float64.h>

int main (int argc, char **argv){

    ros::init(argc, argv, "cylinder_input");
    ros::NodeHandle nh;
    ros::Publisher radius_pub = nh.advertise<std_msgs::Float64>("/radius",10);
    ros::Publisher height_pub = nh.advertise<std_msgs::Float64>("/height",10);
    ros::Publisher density_pub = nh.advertise<std_msgs::Float64>("/density",10);

    std_msgs::Float64 radius;
    std_msgs::Float64 height;
    std_msgs::Float64 density;

    ros::Rate loop_rate(10);

    std::cout << "Enter radius:" << std::endl;
    std::cin >> radius.data;

    std::cout << "Enter height:" << std::endl;
    std::cin >> height.data;

    std::cout << "Enter density:" << std::endl;
    std::cin >> density.data;

    while (ros::ok())
    {
        radius_pub.publish(radius);
        height_pub.publish(height);
        density_pub.publish(density);

        loop_rate.sleep();
    }

return(0);
}