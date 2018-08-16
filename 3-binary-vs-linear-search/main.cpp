/*************************************************

 *************************************************/

#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <set>
#include <iterator>
#include <math.h>

using namespace std;

void sieve ( set<int>& s, const int lower, const int upper )
{
    
    int i;
    
    //insert elements into set s up to upper bound
    for (i = lower; i < upper; i++)
    {
        s.insert(i);
    }
    
    //removes all non prime numbers
    for(int m = 2; m * m <= upper; m++)
    {
        //check if m is still in the set
        if(s.find(m) != s.end())
        {
            i = 2 * m;
            while(i <= upper)
            {
                s.erase(i);
                i += m;
            }
        }
    }
    
}

void print_primes( const set<int>& s, const int lower, const int upper)
{

    //const items for clean display
    const int NO_ITEMS = 6;
    const int ITEM_W = 4;
    
    set<int>::const_iterator itr;
    
    int primes = 0;
    
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        //used to find end of line with determining how many items printed
        primes++;
        
        //finds end of line and prints new line
        if (primes % NO_ITEMS == 0)
        {
            cout << endl;
        }
        
        //prints iterator address with constant spacing
        cout << *itr << setw(ITEM_W);
    }
    
    cout << endl << "There were " << primes << " primes found between " << lower << " and " << upper << ":" <<endl;

}

void run_game(set<int>& s)
{

    int lower, upper;
    
    char exit = NULL;
    
    do{
        do{
            cout << "Please Enter Lower Number : ";
            cin >> lower;
            cout << endl;
        
            if (lower < 2)
            {
            cout << "Please enter a number of 2 or higher: ";
            cin >> lower;
            }
        
            cout << "Please enter Higher Number: ";
            cin >> upper;
            cout << endl;
        
            if (upper < lower)
            {
            cout << "Please enter a number greater than lower number: ";
            cin >> upper;
            }
        }while( lower > upper);

        sieve(s, lower, upper);
        
        print_primes(s, lower, upper);
        
        cout << endl << "Would you like to exit? Enter Y for Yes or N for No: ";
        cin >> exit;
        cout << endl;
    }while( exit != 'Y');
        
}


int main() {
    set<int> s;
    run_game(s);
    return 0;
}

