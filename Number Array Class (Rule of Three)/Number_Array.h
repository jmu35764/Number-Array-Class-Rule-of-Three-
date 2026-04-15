
#ifndef NUM_ARRAY_H
#define NUM_ARRAY_H

class NumberArray
{
private:

	int a_size; // Array size variable
	double* data = nullptr;
	static const int MAX_SIZE = 12; // Default array size

public:

	// The constructor defaults to the value of MAX_SIZE (12) if no values
	// are added to the object

	NumberArray(int size = MAX_SIZE);

	// Copy Constructor
	NumberArray(const NumberArray&);

	// Overloaded Assignment Operator
	const NumberArray operator=(const NumberArray& rhs);

	~NumberArray();

	void setNumber(int index, double value);

	double getNumber(int index) const;

	double getMin() const;

	double getMax() const;

	double getAverage() const;

	void Print() const;
};

#endif
