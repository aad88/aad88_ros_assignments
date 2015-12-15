#include <as6/my_interesting_moves.h>


MyInterestingMoves::MyInterestingMoves(){
	nh_ = ros::NodeHandle();
}
MyInterestingMoves::MyInterestingMoves(ros::NodeHandle* nodehandle){
	nh_ = nodehandle;
}

void MyInterestingMoves::set_goal_horizontal(trajectory_msgs::JointTrajectory &des_trajectory){
	

	Baxter_traj_streamer baxter_traj_streamer(&nh_);

    //get right arm pos
    Vectorq7x1 q_vec_right_arm = baxter_traj_streamer.get_qvec_right_arm();

    std::vector<Eigen::VectorXd> qvecs;
    qvecs.push_back(q_vec_right_arm);

    Vectorq7x1 goal;

    //set goal vector
    goal<< 0, 0, 0, 0, 0, 0, 0;

    gvecs.push_back(goal);

    baxter_traj_streamer.stuff_trajectory(qvecs, des_trajectory);
}

void MyInterestingMoves::set_goal_salute(trajectory_msgs::JointTrajectory &des_trajectory){
	Baxter_traj_streamer baxter_traj_streamer(&nh_);

    //get right arm pos
    Vectorq7x1 q_vec_right_arm = baxter_traj_streamer.get_qvec_right_arm();

    std::vector<Eigen::VectorXd> qvecs;
    qvecs.push_back(q_vec_right_arm);

    Vectorq7x1 goal;

    //set goal vector
    goal<< 0, 0, 0, 0, 0, 0, 0;

    gvecs.push_back(goal);

    baxter_traj_streamer.stuff_trajectory(qvecs, des_trajectory);
}

void MyInterestingMoves::set_goal_raise_hand(trajectory_msgs::JointTrajectory &des_trajectory){
	Baxter_traj_streamer baxter_traj_streamer(&nh_);

    //get right arm pos
    Vectorq7x1 q_vec_right_arm = baxter_traj_streamer.get_qvec_right_arm();

    std::vector<Eigen::VectorXd> qvecs;
    qvecs.push_back(q_vec_right_arm);

    Vectorq7x1 goal;

    //set goal vector
    goal<< 0, 0, 0, 0, 0, 0, 0;

    gvecs.push_back(goal);

    baxter_traj_streamer.stuff_trajectory(qvecs, des_trajectory);
}