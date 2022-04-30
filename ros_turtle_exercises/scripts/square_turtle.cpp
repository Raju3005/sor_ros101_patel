/*#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32.h>
#include <geometry_msgs/Point32.h>
#include <turtlesim/Pose.h>
#include <iostream>

std_msgs::Float64 pos_x;
std_msgs::Float64 pos_y;
//geometry_msgs::Point pos_x;

ros::Publisher square_turtle_pub;
int i = 0;

void callback(const turtlesim::Pose &val){
    pos_x.data = val.x;
    pos_y.data = val.y;
    //std::cout << val.x << std::endl;

    geometry_msgs::Twist msg;
    //int i = 0;

    //ros::Rate loop_rate(100000000000000000);

    if(pos_x.data<=8.3 && i==0)
    {
        msg.linear.x = 0.3;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
        std::cout << val.x << std::endl;
        std::cout << i << std::endl;
        
        
            if(pos_x.data>8.0)
            {
                ros::Duration(50).sleep();
                msg.linear.x = 0.0;
                msg.angular.z = 1*(3.14/2);
                square_turtle_pub.publish(msg);
                i = 1;
                std::cout << val.y << std::endl;
                std::cout << i << std::endl;
                //ros::Duration(0.5).sleep();
            }
    }

    //loop_rate.sleep();
    

  if(pos_y.data<=8.3 && i==1)
    {
        msg.linear.y = 0.3;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
        std::cout << val.y << std::endl;
        std::cout << i << std::endl;
        
            if(pos_y.data>8.0)
            {
                msg.linear.y = 0.0;
                msg.angular.z = 1*(3.14/2);
                square_turtle_pub.publish(msg);
                i = 2;
                std::cout << val.y << std::endl;
                std::cout << i << std::endl;
            }
    }

    if(pos_x.data>=5.24 && i==2)
    {
        msg.linear.x = -0.3;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
        std::cout << val.y << std::endl;
        std::cout << i << std::endl;
        
            if(pos_x.data<5.54)
            {
                msg.linear.x = 0.0;
                msg.angular.z = 1*(3.14/2);
                square_turtle_pub.publish(msg);
                i = 3;
                std::cout << val.y << std::endl;
                std::cout << i << std::endl;
            }
    }

    //ros::Duration(0.5).sleep();

   /* else if(pos_x.data>8.0 && pos_x.data<=8.05)
    {
        msg.linear.x = 0.0;
        msg.angular.z = 1*(3.14/2);
        square_turtle_pub.publish(msg);
        std::cout << val.y << std::endl;
    }*/
    
    //pos_x.data = val->data;
    //std::cout << pos_x << std::endl;
//}

/*void move(){

    geometry_msgs::Twist msg;

    //std::cout << pos_x.data << std::endl;
    //std::cout << pos_y.data << std::endl;

    

    if (pos_x.data < 8.0 && pos_y.data==5.5444)
    {
        std::cout << pos_x.data << std::endl;
        std::cout << pos_y.data << std::endl;
        
        msg.linear.x = 0.3;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
    }
    /*else if(pos_x.data==8.0 && pos_y.data==5.5444)
    {
        msg.linear.x = 0.0;
        msg.angular.z = 1*(3.14/2);
        square_turtle_pub.publish(msg);
    }
    else if(pos_x.data==8.0 && pos_y.data<=8.0)
    {
        msg.linear.x = 0.3;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
    }
    else if(pos_x.data==8.0 && pos_y.data==8.0)
    {
        msg.linear.x = 0.0;
        msg.angular.z = 1*(3.14/2);
        square_turtle_pub.publish(msg);
    }
    else if(pos_x.data<=0.0 && pos_y.data==8.0)
    {
        msg.linear.x = 0.3;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
    }
    else if(pos_x.data==0.0 && pos_y.data==8.0)
    {
        msg.linear.x = 0.0;
        msg.angular.z = 1*(3.14/2);
        square_turtle_pub.publish(msg);
    }
    else if(pos_x.data==0.0 && pos_y.data<=8.0)
    {
        msg.linear.x = 0.3;
        msg.angular.z = 0;
        square_turtle_pub.publish(msg);
    }
    else if(pos_x.data==0.0 && pos_y.data==0.0)
    {
        msg.linear.x = 0.0;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
    }*/

//}
/*

int main (int argc, char **argv){

    ros::init(argc, argv, "square_turtle");
    ros::NodeHandle nh;

    square_turtle_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);

    //ros::Rate loop_rate(10);
    ros::Rate loop_rate(100000000000000000);

    ros::Subscriber pos_sub = nh.subscribe("/turtle1/pose",10,callback);
    ros::spin();
    loop_rate.sleep();
    ros::Duration(0.5).sleep();


   // geometry_msgs::Twist msg;

    //msg.linear.x = 0.3;
    //msg.angular.z = 0.0;

    //ros::Rate loop_rate(10);

    /*while(ros::ok())
    {
        //square_turtle_pub.publish(msg);
        //move();
        ros::spinOnce();
        loop_rate.sleep();
    }*/
//return(0);
//}



#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32.h>
#include <geometry_msgs/Point32.h>
#include <turtlesim/Pose.h>
#include <iostream>

std_msgs::Float64 pos_x;
std_msgs::Float64 pos_y;
//geometry_msgs::Point pos_x;

ros::Publisher square_turtle_pub;
int i = 0;

void callback(const turtlesim::Pose &val){
    pos_x.data = val.x;
    pos_y.data = val.y;
}

void run()
{  

    geometry_msgs::Twist msg;

    if(pos_x.data<=8.3 && i==0)
    {
        msg.linear.x = 0.3;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
        std::cout << pos_x.data << std::endl;
        std::cout << i << std::endl;
        
        
            if(pos_x.data>8.0)
            {
                //ros::Duration(50).sleep();
                msg.linear.x = 0.0;
                msg.angular.z = 1*(3.14/2);
                square_turtle_pub.publish(msg);
                i = 1;
                std::cout << pos_y.data << std::endl;
                std::cout << i << std::endl;
                ros::Duration(1).sleep();
            }
    }  

    if(pos_y.data<=8.3 && i==1)
    {
        msg.linear.x = 0.3;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
        std::cout << pos_y.data << std::endl;
        std::cout << i << std::endl;
        
            if(pos_y.data>8.0)
            {
                msg.linear.x = 0.0;
                msg.angular.z = 1*(3.14/2);
                square_turtle_pub.publish(msg);
                i = 2;
                std::cout << pos_y.data << std::endl;
                std::cout << i << std::endl;
                ros::Duration(1).sleep();
            }
    }

    if(pos_x.data>=5.24 && i==2)
    {
        msg.linear.x = 0.3;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
        std::cout << pos_y.data << std::endl;
        std::cout << i << std::endl;
        
            if(pos_x.data<5.54)
            {
                msg.linear.x = 0.0;
                msg.angular.z = 1*(3.14/2);
                square_turtle_pub.publish(msg);
                i = 3;
                std::cout << pos_y.data << std::endl;
                std::cout << i << std::endl;
                ros::Duration(1).sleep();
            }
    }

    if(pos_y.data>=5.24 && i==3)
    {
        msg.linear.x = 0.3;
        msg.angular.z = 0.0;
        square_turtle_pub.publish(msg);
        std::cout << pos_y.data << std::endl;
        std::cout << i << std::endl;
        
            if(pos_y.data<5.54)
            {
                msg.linear.x = 0.0;
                msg.angular.z = 1*(3.14/2);
                square_turtle_pub.publish(msg);
                i = 0;
                std::cout << pos_y.data << std::endl;
                std::cout << i << std::endl;
                ros::Duration(1).sleep();
            }
    }
}


int main (int argc, char **argv){

    ros::init(argc, argv, "square_turtle");
    ros::NodeHandle nh;

    square_turtle_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);

    ros::Subscriber pos_sub = nh.subscribe("/turtle1/pose",10,callback);
    //ros::spin();

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        //square_turtle_pub.publish(msg);
        run();
        ros::spinOnce();
        loop_rate.sleep();
    }
return(0);
}
    
