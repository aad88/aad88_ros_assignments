#include <as6/my_interesting_moves.h>
#include <iostream>
#include <std_msgs/Int32.h>
#include <baxter_traj_streamer/trajAction>
#include <actionlib/client/simple_action_client.h>
using namespace std;

void doneCb(const actionlib::SimpleClientGoalState& state, const baxter_traj_streamer::trajResultConstPtr& result){
	if(result->return_val){
		ROS_INFO("success\n");
	}
	else{
		ROS_INFO("failure\n");
	}
}

int main(int argc, char** argv){
	ros::init(argc, argv, "my_interesting_moves_test");
	ros::NodeHandle nh;
	MyInterestingMoves myInterestingMoves(&nh);

	actionlib::SimpleActionClient<baxter_traj_streamer::trajAction> action_client("trajActionServer", true);


	ROS_INFO("waiting for server: ");
  	bool server_exists = action_client.waitForServer(ros::Duration(5.0));//wait up to 5 seconds

    if(!server_exists) {
    	ROS_WARN("could not connect to server: halting");
    	return 0;//bail
  	}

	while(ros::ok()){
		int choice;
		cout<<endl;
		cout << "Enter movement choice: 1. Horizontal 2. Salute 3. Raise hand\n";
		cin >> choice;

		baxter_traj_streamer::trajGoal = goal;

		trajectory_msgs::JointTrajectory des_trajectory;

		if(choice==1){
			myInterestingMoves.set_goal_horizontal(&des_trajectory);
		}
		else if(choice == 2){
			myInterestingMoves.set_goal_salute(&des_trajectory);
		}
		else if(choice == 3){
			myInterestingMoves.set_goal_raise_hand(&des_trajectory);
		}
		else{
			cout<<endl;
			cout << "Invalid choice \n";

			ros::spinOnce();
			continue;
		}

		goal.trajectory = des_trajectory;

		ROS_INFO("Sending goal\n");
		action_client.sendGoal(goal, &doneCb);


		ros::spinOnce();
	}
}