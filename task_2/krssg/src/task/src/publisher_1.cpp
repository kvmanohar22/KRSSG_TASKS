
//node 1 reading the array of integers and publish it to topic 1
#include<ros/ros.h>
#include<bits/stdc++.h>
#include<std_msgs/Int32MultiArray.h>

using namespace std;

int main(int argc, char **argv)
{
  int temp;

  ros::init(argc, argv, "Node_1");

  ros::NodeHandle nh;

  ros::Publisher publisher = nh.advertise<std_msgs::Int32MultiArray>("Topic_1",1000,true);
   

    std_msgs::Int32MultiArray vec;

    ROS_INFO("\nArray1 contains the following elements:\n");
 
  ifstream infile("array1.txt");

  while(infile >> temp)
    {
      ROS_INFO("%4d  ",temp);
      vec.data.push_back(temp);
    }

  publisher.publish(vec);
  ROS_INFO("\nArray elements from file [array1.txt] are published to Topic_1:\n");
  ros::spin();
  

 
  return 0;
}
