/*
 * Program1.c
 *  Created on: Feb 9, 2023
 *      Author: c046k307
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	float arr[12];
	int lines = 12;
	FILE *file;
	char file_name[100];
	printf("Enter the file name: ");
	scanf("%s", file_name);
	file = fopen(file_name, "r");

	for (int x = 0; x < lines; x++) {
		fscanf(file, "%f", &arr[x]);
	}

	char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	printf("Monthly sales report for 2022:\n\n");
	printf("%-10sSales\n", "Month");
	for (int x = 0; x < lines; x++)
	{
		printf("%-10s$%.2f\n", months[x], arr[x]);
	}

	printf("\nSales summary:\n\n");
	float min = arr[0];
	float max = arr[0];
	char *min_month = months[0];
	char *max_month = months[0];
	float total = arr[0];
	for (int x = 1; x < lines; x++)
	{
		if (arr[x] > max)
		{
			max = arr[x];
			max_month = months[x];
		}
		if (arr[x] < min)
		{
			min = arr[x];
			min_month = months[x];
		}
		total += arr[x];
	}
	float avg = total / 12;
	printf("%-15s$%.2f (%s)\n", "Minimum sales:", min, min_month);
	printf("%-15s$%.2f (%s)\n", "Maximum sales:", max, max_month);
	printf("%-15s$%.2f\n", "Average sales:", avg);

	printf("\nSix-Month Moving Average Report:\n\n");
	for (int x = 0; x < 7; x++)
	{
		float temp_sum = 0;
		for (int y = x; y < x + 6; y++)
		{
			temp_sum += arr[y];
		}
		float average = temp_sum / 6;
		printf("%-10s - %-10s $%8.2f\n", months[x], months[x+5], average);
	}

	printf("\nSales Report (Highest to Lowest):\n\n");
	printf("%-10sSales\n", "Month");
	for (int x = 0; x < lines; x++)
	{
		for (int y = x+1; y < lines; y++)
		{
			if (arr[x] < arr[y]) {
				float temp_val = arr[x];
				arr[x] = arr[y];
				arr[y] = temp_val;
				char *temp_month = months[0];
				temp_month = months[x];
				months[x] = months[y];
				months[y] = temp_month;
			}
		}
	}
	for (int x = 0; x < lines; x++)
		{
			printf("%-10s$%.2f\n", months[x], arr[x]);
		}

	fclose(file);
	return 0;
}