/*
 * main file for testing GreedyArm function in Part 1 of
 * EAS 240 Multi-armed bandit project
 * EAS 240 Introduction to Probability for Engineers
 * Author: Nick Mastronarde
 *
 * Note: BanditArm member variables
 * are initialized randomly to test
 * the GreedyArm function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bandit.h"

int main() {
   const int numArms = 5;
   int chosenArm;
   int seed;
   BanditArm armArray[numArms];

   printf("Enter random seed:\n");
   scanf("%d", &seed);

   /* Seed the random number generator */
   srand(seed);

   /* Initialize member variables of each BanditArm in armArray randomly */
   for (int i = 0; i < numArms; i++) {
      armArray[i].value = rand() % 10;
      armArray[i].rewardStdDev = rand() % 10;
      armArray[i].count = rand() % 100;
      armArray[i].sumReward = rand() % 1000;
      armArray[i].avgReward = rand() % 100;
   }
   
   /* Print armArray[i].avgReward in a formatted table */
   printf("\nArm\tAvg. Reward\n");
   for (int i = 0; i < numArms; i++) {
      printf("%3d\t%11.2lf\n", i, armArray[i].avgReward);
   }
   printf("\n");
   
   chosenArm = GreedyArm(armArray, numArms);
   printf("Greedy arm: %d\n", chosenArm);
   
   return 0;
 }
