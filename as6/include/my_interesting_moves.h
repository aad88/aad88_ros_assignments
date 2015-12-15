///aad88: Dec 2015
///Include this file in any file that needs this library
///This class provides three arm movement methods for Baxter
///


#ifndef MY_INTERESTING_MOVES_H
#define MY_INTERESTING_MOVES_H

#include <ros/ros.h>

#include <Eigen/Eigen>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/Eigenvalues>
#include <baxter_traj_streamer/baxter_traj_streamer.h>


class MyInterestingMoves{
public:
	MyInterestingMoves();
	MyInterestingMoves(ros::NodeHandle* nodehandle);

	/**method to set Baxter right arm into salute
	*
	*@param des_trajectory 
	*/
	void set_goal_salute(trajectory_msgs::JointTrajectory &des_trajectory);

	/**method to set Baxter right arm horizontally straight
	*
	*@param des_trajectory
	*/
	void set_goal_horizontal(trajectory_msgs::JointTrajectory &des_trajectory);

	/**method to set Baxter arm in a raising hand motion
	*
	*@param des_trajectory
	*/
	void set_goal_raise_hand(trajectory_msgs::JointTrajectory &des_trajectory);	

private:

	ros::NodeHandle nh_;
};




#endif