#include <iostream>
#include <math.h>

using namespace std;
long long unsigned int recursion (long long int z){
    //base case
    if (z == 0 || z == 1 )
    {
        return 1;
    }
    else{
        //f(z) = z^z * (z-1)^(z-1)
        return pow(z, z)*(pow(recursion(z-1), 1)); 
    }

}



int main()
{
    cout << "\nRecursion (2) = " << recursion (2) << endl;
    cout << "\nRecursion (4) = " << recursion (4) << endl;
    cout << "\nRecursion (6) = " << recursion (6) << endl << "\n";
}
