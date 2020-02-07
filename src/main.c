/*
 * main.c
 *
 *  Created on: Feb 7, 2020
 *      Author: doug
 */


#include <stdio.h>

#define Nsta    (3)
#define Mobs 	(4)


#include "tiny_ekf_struct.h"
#include "tiny_ekf.h"

#define NUM_STEPS  10

ekf_t EKF;

double Z[Mobs] = { 0, 0, 0, 0};

int main(void)
{
	int i;
	int result;

	printf("Test Tiny EKF - Extended Kalman Filter\n");

	ekf_init(&EKF, Nsta, Mobs);

	for (i= 0; i< NUM_STEPS; i++)
	{
		// fake data
		Z[0] = i+1;
		Z[2] = 20 - i;

		/**
		  * Runs one step of EKF prediction and update. Your code should first build a model, setting
		  * the contents of <tt>ekf.fx</tt>, <tt>ekf.F</tt>, <tt>ekf.hx</tt>, and <tt>ekf.H</tt> to appropriate values.
		  * @param ekf pointer to structure EKF
		  * @param z array of measurement (observation) values
		  * @return 0 on success, 1 on failure caused by non-positive-definite matrix.
		  */
		result = ekf_step(&EKF, Z);
		if (result == 1)
		{
			printf("Failure ekf_step(), iteration = %d\n", i);
			break;
		}
	}

	printf("All done\n");

	return 0;
}
