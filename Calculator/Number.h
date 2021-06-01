#include<iostream>
#include<string>
#include<stack>
#include<math.h>

using namespace std;


/// <summary>
/// Class "Number"
/// </summary>
class Number {
public:
	/// <summary>
	/// Class constructor
	/// </summary>
	Number();
	/// <summary>
	/// Class constructor
	/// </summary>
	/// <param name="str">- number as string </param>
	Number(string str);
	/// <summary>
	/// Class constructor
	/// </summary>
	/// <param name="str">- number as string </param>
	/// <param name="basis">- numerical system of this number </param>
	Number(string str, int bs);
	/// <summary>
	/// Class constructor
	/// </summary>
	/// <param name="str">- number as string </param>
	/// <param name="basis">- numerical system of this number </param>
	Number(double str, int bs);
	/// <summary>
	/// Class destructor
	/// </summary>
	~Number();
	/// <summary>
	/// Converting a number to another number system
	/// </summary>
	/// <param name="str">- number as string </param>
	/// <param name="basis">- numerical system of this number </param>
	/// <returns> null </returns>
	string get(int base);
private:
	/* Fields */
	string num;
	int base;
	/// <summary>
	/// Finding a number from the decimal system
	/// </summary>
	/// <param name="number">- the number to be translated </param>
	/// <param name="basis">- original number system </param>
	/// <param name="length">- is the number of decimal places </param>
	/// <returns> Returns a number in the specified number system </returns>
	string fromDecimal(string number, int base, int length);
	/// <summary>
	/// The known number in dozens of systems
	/// </summary>
	/// <param name="number">- the number to be translated </param>
	/// <param name="basis">- original number system </param>
	/// <param name="length">- is the number of decimal places </param>
	/// <returns> Returns a number in the 10th notation system </returns>
	string toDecimal(string number, int basis, int length);
};

