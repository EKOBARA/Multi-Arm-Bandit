/*
 * Function definitions for multi-armed bandit project
 * Template provided to students for Part 1
 * EAS 240 Introduction to Probability for Engineers
 * Author: Nick Mastronarde
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bandit.h"

const double piVal = M_PI;

/* Selects the greedy arm with the maximum average reward */
int GreedyArm(const BanditArm armArray[], int numArms) {
   int num = 0;
   int idx;
   for (int i = 0; i < numArms; i++) {
      if (armArray[i].avgReward > num){
         idx = i;
         num = armArray[i].avgReward;
      } 
      else if (armArray[i].avgReward == num) {
         idx = idx;
      } 
   }
   return idx;
}


/* Selects an arm based on the epsilon-greedy action selection method */
int SelectArm(const BanditArm armArray[], double epsilon, int numArms) {
   // *** <COMPLETE ME> Complete this function definition ***
   
   // *** <COMPLETE ME> ***
   // Set rnum to the correct value so that 
   // the random action is taken with probability epsilon and
   // the greedy action is taken with probability 1-epsilon
   // Hint: See Drill 4 in Section 2.3 of the project description
   double rnum = 0; 
   
   if (rnum < epsilon) {
      /* <COMPLETE ME> Select a random arm */
      
   }
   else {
      /* <COMPLETE ME> Select the greedy arm */
      
   }

   return 0; // *** <COMPLETE ME> Replace with the correct return value ***
}


/* Prints the simulation statistics.
 * Statistics include:
 *      Total sum reward over the entire simulation
 *      Number of times each arm was selected
 *      Average reward obtained by each arm
 *      Expected reward (value) of each arm
 */
void PrintStatistics(const BanditArm armArray[], int numArms) {
   // *** <COMPLETE ME> Complete this function definition ***
}


/* ************************************
 * The functions below this comment
 * have already been completed for you.
 * Do not modify them.
 * ************************************/

/* Pulls the selected arm to receive the reward
 * The reward is generated from a Gaussian distribution
 * with mean (arm.value) and standard deviation
 * (arm.rewardStdDev).
 */
double ReceiveReward(BanditArm arm) {
   // *** This function is already completed for you ***
   double reward = arm.value + \
                   arm.rewardStdDev * GetNormalRV();

   return reward;
}


/* Generates a Gaussian random variable with 0 mean and
 * unit standard deviation
 */
double GetNormalRV() {
   // *** This function is already completed for you ***
   
   /* Get two uniform random variables */
   double randVar1 = (double) rand() / (double) RAND_MAX;
   double randVar2 = (double) rand() / (double) RAND_MAX;

   return sqrt(-2.0 * log(randVar1)) * cos(2.0 * piVal * randVar2);
}
