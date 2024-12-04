/*!******************************************************************
 @author     HE Ronghai
 ********************************************************************/

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

using namespace std;



int main(int argc, char** argv)
{
    ros::init(argc, argv, "round");
    ros::NodeHandle n;
    ros::Publisher velcmd_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel",10);
    geometry_msgs::Twist vel_cmd;
    vel_cmd.linear.x = 0;
    vel_cmd.linear.y = 0;
    vel_cmd.linear.z = 0;
    vel_cmd.angular.x = 0;
    vel_cmd.angular.y = 0;

    ros::Rate r(10.0);
    while(ros::ok()){
        vel_cmd.angular.z = 1;
        velcmd_pub.publish(vel_cmd);
        r.sleep();
    }
    return 0;
}