#pragma once
class LaserProjector
{
public:
	volatile char indexMirrow = 0;
	volatile char data[5] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	volatile int index = 0;

	volatile int indexCorrection = 0;

private:
	int sizeOfData;

public:
	const char mirrowPosition[8] = {4, 3, 2, 1, 0, 7, 6, 5};

public:
	const char mirrowBit[8] = {1, 2, 4, 8, 16, 32, 64, 128};

private:
	const char mirrowCorrection[8] = {0, 0, 0, 0, 0, 0, 0, 0};


public:
	void setData(char *data, int size) {
//		this->data = data;
		sizeOfData = size;
	}

};
