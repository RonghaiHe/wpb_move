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
    
    vel_cmd.linear.z = 0;
    vel_cmd.angular.x = 0;
    vel_cmd.angular.y = 0;
    
    ros::NodeHandle n_param("~");
    int v_x, v_y, v_az;
    n_param.param<int>("v_x", v_x, 0);
    n_param.param<int>("v_y", v_y, 0);
    n_param.param<int>("v_az", v_az, 1);

    vel_cmd.linear.x = v_x;
    vel_cmd.linear.y = v_y;
    vel_cmd.angular.z = v_az;


    ros::Rate r(1.0);
    for(int i=0;i<4;++i)
        r.sleep();
    while(ros::ok()){
        velcmd_pub.publish(vel_cmd);
        r.sleep();

        // vel_cmd.linear.x = 0.5;
        // vel_cmd.angular.z = 0;
        // velcmd_pub.publish(vel_cmd);
        // for(int i=0;i<3;++i)
        //     r.sleep();
        // vel_cmd.linear.x = 0;
        // vel_cmd.angular.z = 1;
        // velcmd_pub.publish(vel_cmd);
        // for(int i=0;i<3;++i)
        //     r.sleep();
    }
    return 0;
}