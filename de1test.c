#include "address_map_arm.h"	// base addresses from DE1-SOC Computer 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Point_3D.c"
#include "Vector_3D.c"

#define width 320
#define height 240
#define depth 100

void redrawScreen();

volatile int * KEY_ptr = (int *) KEY_BASE;
volatile int * SW_ptr = (int *) SW_BASE;
volatile int * DMA_CONTROL = (int *) PIXEL_BUF_CTRL_BASE;
volatile int * KB_ptr    =   (int *) PS2_BASE;
volatile int * LEDR_ptr  =   (int *) LEDR_BASE;

int main(void){
    struct Point pointArray[100];
    short image[height][width];

    int i = 0;
    while(i < point.Array.length){
        pointArray[i] = newPoint(rand() % width, rand() % height, rand() & depth);
        i++;
    }

    redrawScreen();
}

void redrawScreen(){
	int offset, row = 0, col = 0;
  	short * pixel_buffer = (short *) FPGA_ONCHIP_BASE;	// pixel buffer
	int beg_row, beg_col, end_row, end_col;

	//erase screen
	for (row = beg_row; row <= end_row; row++)
	{
		for (col = beg_col; col <= end_col; col++)
		{
			offset = (row << 9) + col;
			*(pixel_buffer + offset) = 0;	
		}
	}
}