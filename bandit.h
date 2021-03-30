/*
 * Function declarations for multi-armed bandit project
 * Template provided to students for Part 1
 * EAS 240 Introduction to Probability for Engineers
 * Author: Nick Mastronarde
 */
 
#ifndef BANDIT_H_
#define BANDIT_H_

typedef struct BanditArm_struct {
   int      count;          // Number of times that this arm has been selected
   double   sumReward;      // Cumulative sum of rewards obtained by selecting this arm
   double   avgReward;      // Average reward obtained by selecting this arm
   double   value;          // Expected reward (value)
   double   rewardStdDev;   // Standard deviation of reward
} BanditArm;


/* Selects the greedy arm with the maximum average reward */
int GreedyArm(const BanditArm armArray[], int numArms);


/* Selects an arm based on the epsilon-greedy action selection method */
int SelectArm(const BanditArm armArray[], double epsilon, int numArms);


/* Prints the simulation statistics.
 * Statistics include:
 *      Total sum reward over the entire simulation
 *      Number of times each arm was selected
 *      Average reward obtained by each arm
 *      Expected reward (value) of each arm
 */
void PrintStatistics(const BanditArm armArray[], int numArms);


/* Pulls the selected arm to receive reward */
double ReceiveReward(BanditArm arm);


/* Generates a Gaussian random variable with 0 mean and
 * unit standard deviation
 */
double GetNormalRV();


#endif
