/*
 * mainPart1.c for multi-armed bandit project
 * Template provided to students for Part 1
 * EAS 240 Introduction to Probability for Engineers
 * Author: Nick Mastronarde
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bandit.h"

int main() {
   int numArms = 5;
   int numSteps = 100;
   double epsilon;
   int seed;
   BanditArm armArray[numArms];
   double payoffArray[numSteps];
   int selectionArray[numSteps];
   int *selection;
   double *payOff;
   BanditArm *arrArm; 
   char fileName[] = "stats.csv";

   printf("Enter the number of arms:\n");
   scanf("%d", &numArms);

   printf("Enter the number of simulation time steps:\n");
   scanf("%d", &numSteps);

   printf("Enter the value of epsilon in [0,1]:\n");
   scanf("%lf", &epsilon);

   printf("Enter random seed:\n");
   scanf("%d", &seed);

   selection = (int *)malloc(numSteps*sizeof(int));
   payOff = (double *)malloc(numSteps*sizeof(int));
   arrArm = (BanditArm *)malloc(numArms*sizeof(int));

   /* Seed the random number generator */
   srand(seed);

   for (int i = 0; i < numArms; i++) {

      armArray[i].count = 0;
      armArray[i].sumReward = 0.0;
      armArray[i].avgReward = 0.0;
      armArray[i].value = fabs(GetNormalRV());
      armArray[i].rewardStdDev = 1.0;

   }

   printf("\n***** Simulation Begins *****\n");

   for (int i = 0; i < numSteps; i++) {
      selectionArray[i] = SelectArm(armArray, epsilon, numArms);

      payoffArray[i] = ReceiveReward(armArray[selectionArray[i]]);

      armArray[selectionArray[i]].count += 1;
      armArray[selectionArray[i]].sumReward += payoffArray[i];
      armArray[selectionArray[i]].avgReward = armArray[selectionArray[i]].sumReward / armArray[selectionArray[i]].count;
      
      printf("t: %d\tArm: %d\tReward: %.2f\n", i, selectionArray[i], payoffArray[i]);
   }

   printf("***** Simulation Ends *****\n\n");

   PrintStatistics(armArray, numArms);

   free(selection);
   free(payOff);
   free(arrArm);

   WriteToFile(fileName, numSteps, selectionArray, payoffArray);

   return 0;
}