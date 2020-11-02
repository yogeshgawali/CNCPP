// C++ program to Count set bits in an integer
#include <iostream>
using namespace std;

int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };
int BitsSetTable256[256];

unsigned int countSetBits1(long int);  //using loop
unsigned int countSetBits2(long int);  //recursive approach
unsigned int countSetBits3(long int);  //brian kernighan approach
unsigned int countSetBits4(long int);  //using built-in function
unsigned int countSetBits5(long int);  //nibble by nibble using recursion
unsigned int countSetBits6(long int);  //using lookup table

void initialize();

int main()
{
	unsigned int bitCount;
    long int i;

	cout << "Enter number: ";
	cin >> i;

	bitCount = countSetBits1(i);
	cout << "Approach 1: "<<bitCount<<endl;

	bitCount = countSetBits2(i);
	cout << "Approach 2: "<<bitCount<<endl;

	bitCount = countSetBits3(i);
	cout << "Approach 3: "<<bitCount<<endl;

	bitCount = countSetBits4(i);
	cout << "Approach 4: "<<bitCount<<endl;

	bitCount = countSetBits5(i);
	cout << "Approach 5: "<<bitCount<<endl;

	bitCount = countSetBits6(i);
	cout << "Approach 6: "<<bitCount<<endl;

	return 0;
}

unsigned int countSetBits1(long int n)
{
	unsigned int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}

unsigned int countSetBits2(long int n)
{
    if (n == 0)
        return 0;
    else
        return (n & 1) + countSetBits2(n >> 1);
}

unsigned int countSetBits3(long int n)
{
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

unsigned int countSetBits4(long int n)
{
	unsigned int count = 0;
	count = __builtin_popcount(n);
	return count;
}

unsigned int countSetBits5(long int num)
{
	int nibble = 0;
	if (0 == num)
		return num_to_bits[0];

	nibble = num & 0xf; // Find last nibble

	// Use pre-stored values to find count in last nibble plus recursively add remaining nibbles.
	return num_to_bits[nibble] + countSetBits5(num >> 4);
}

unsigned int countSetBits6(long int n)
{
    initialize();
    return (BitsSetTable256[n & 0xff] +
            BitsSetTable256[(n >> 8) & 0xff] +
            BitsSetTable256[(n >> 16) & 0xff] +
            BitsSetTable256[n >> 24]);
}

void initialize()
{

    // To initially generate the
    // table algorithmically
    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        BitsSetTable256[i] = (i & 1) +
        BitsSetTable256[i / 2];
    }
}
