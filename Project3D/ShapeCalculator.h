#pragma once

#include <stdio.h>

static void changeMatrixValues(float matrix[9], float x, float y, float z);

static void changeMatrixValues(float matrix[9], float x, float y, float z) {

	for (int x = 0; x < sizeof(*matrix) / sizeof(float); x += 3) {
		switch ((x + 1) % 3) {
			case 1: matrix[x] += x;
			case 2: matrix[x] += y;
			case 3: matrix[x] += z;
		}
	}
}