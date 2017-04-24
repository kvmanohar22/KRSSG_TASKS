//node 2 reading the array of integers and publish it to topic 1
#include<ros/ros.h>
#include<bits/stdc++.h>
#include<fstream>
#include<std_msgs/Int32MultiArray.h>

using namespace std;

int main(int argc, char **argv)
{
  int temp;

  ros::init(argc, argv, "Node_2");

  ros::NodeHandle nh;

  ros::Publisher publisher = nh.advertise<std_msgs::Int32MultiArray>("Topic_2",1000,true);
   
     std_msgs::Int32MultiArray vec2;


  ifstream infile("array2.txt");

  ROS_INFO("\nArray2 contains the following elements:\n");

  while(infile >> temp)
    {
      ROS_INFO("%4d  ",temp);
      vec2.data.push_back(temp);
    }
 
  publisher.publish(vec2);
  ROS_INFO("\nArray elements from file [array2.txt] are published to Topic_2:\n");
  ros::spin();

  return 0;
}
