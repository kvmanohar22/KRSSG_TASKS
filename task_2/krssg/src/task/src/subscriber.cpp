//subscriber node subscribed to two nodes
#include "ros/ros.h"
#include<iostream>
#include<fstream>
#include<array>
#include<iterator>
#include<algorithm>
#include<vector>
#include<std_msgs/Int32MultiArray.h>
using namespace std;
vector<int> vec_1;
vector<int> vec_2;
void sort();
 
void callback_1(const std_msgs::Int32MultiArray::ConstPtr& vec1)
{ 
  ROS_INFO("\nVector recieved over Topic_1 and contains following elements:\n");
  vector<int>::const_iterator itr = vec1->data.begin();

  for(;itr != vec1->data.end();++itr)
    {
      ROS_INFO("%d ",*itr);
      vec_1.push_back(*itr);
    }
  for(int j=0;j<10000;++j)
    ;
  // ros::spin();
}

void callback_2(const std_msgs::Int32MultiArray::ConstPtr& vec2)
{
  ROS_INFO("\nVector recieved over Topic_2 and contains following elements:\n");

 vector<int>::const_iterator itr = vec2->data.begin();

  for(;itr != vec2->data.end();++itr)
    {
      ROS_INFO("%d ",*itr);
      vec_2.push_back(*itr);
     
    }
  // ros::spin();
  sort();
}


int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ROS_INFO("\nReading the vectors from both the topics");

  ros::NodeHandle nh;

  ros::Subscriber sub_1 = nh.subscribe("Topic_1",1000,callback_1);
  ros::Subscriber sub_2 = nh.subscribe("Topic_2",1000,callback_2);

  ros::spin();
  return 0;
}


void sort()
{
  vector<int>::const_iterator itr = vec_1.begin();

  for(;itr!=vec_1.end();++itr)
    vec_2.push_back(*itr);

  sort(vec_2.begin(),vec_2.end());
  ROS_INFO("\nThe sorted array is written to file [sorted.txt]:\nand contains the following elements in sorted fashion:\n");

  fstream outfile("sorted.txt");

  for(itr = vec_2.begin();itr != vec_2.end();++itr)
    ROS_INFO("%4d ",*itr);

  return ;
}
