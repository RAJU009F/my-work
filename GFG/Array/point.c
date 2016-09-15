
// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: Dyanamic Progrming/ min Candis required
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

struct X
{

int x;
int y;
int z;

};

struct Point
{
struct X *p;

};


int main()
{

	typedef struct Point->p point;
	
	point pp;
	
	pp->x = 1;
	pp->y = 2;
	pp->z =4;
	
	printf("Size is: %d\n", sizeof(pp));
	printf("pp->x: %d", pp->x);
	printf("pp->y: %d", pp->y);
	printf("pp->z: %d", pp->z);


}