#include "Number_Array.h"
#include <iostream>
#include <iomanip>

using namespace std;


NumberArray::NumberArray(int size)
{
	a_size = size;

	data = nullptr;
	data = new double[size]; // Allocate memory for data

	// Set all values of the array to zero when starting out
	for (int i = 0; i < size; i++)
	{
		data[i] = 0.0;
	}

}

NumberArray::NumberArray(const NumberArray& other)
{
	//data = new double[NumberArray.a_size];
	a_size = other.a_size;
	data = new double[a_size];

	for (int count = 0; count < a_size; count++)
	{
		*(data + count) = *(other.data + count);
	}
}

NumberArray::~NumberArray()
{
	delete[] data; // Deallocate memory for array

	cout << "Memory has been deallocated" << endl;
}

const NumberArray NumberArray::operator=(const NumberArray& rhs)
{
	if (this != &rhs)
	{
		delete[] data;
		a_size = rhs.a_size;
		data = new double[a_size];
		for (int count = 0; count < a_size; count++)
		{
			*(data + count) = *(rhs.data + count);
		}
		return *this;
	}
}

void NumberArray::setNumber(int index, double value)
{
	// Validate if the index argument falls with in the bounds of the index
	if (index >= 0 && index < a_size)
	{
		data[index] = value;
	}

	// If the index argument value is not valid, show a message
	else
	{
		cout << "Invalid Index Input" << endl;
	}
}

double NumberArray::getNumber(int index) const
{
	// Validate if the index argument falls with in the bounds of the index
	if (index >= 0 && index < a_size)
	{
		return data[index];
	}

	// If the index argument value is not valid, show a message
	// and return a constant value 0.0
	else
	{
		cout << "Invalid Index Input" << endl;
		return 0.0;
	}
}


double NumberArray::getMin() const
{
	double min_val = data[0];

	// For loop detmining smallest value
	for (int i = 0; i < a_size; i++)
	{
		// If the current value in the array is smaller than the previous value
		// set the current value as the minimum value.
		if (data[i] < min_val)
		{
			min_val = data[i];
		}
	}

	return min_val;
}

double NumberArray::getMax() const
{
	double max_val = data[0];

	// For loop detmining largest value
	for (int i = 0; i < MAX_SIZE; i++)
	{
		// If the current value in the array is larger than the previous value
		// set the current value as the maximum value.
		if (data[i] > max_val)
		{
			max_val = data[i];
		}
	}

	return max_val;
}

double NumberArray::getAverage() const
{
	double sum = 0;
	double avg_val;

	//Add up all of the values in the array
	for (int i = 0; i < a_size; i++)
	{
		sum = sum + data[i];
	}

	// Divide by the size of the array
	avg_val = sum / a_size;

	return avg_val;

}

void NumberArray::Print() const
{
	for (int i = 0; i < a_size; i++)
	{
		cout << setprecision(3) << data[i] << endl;
	}
}