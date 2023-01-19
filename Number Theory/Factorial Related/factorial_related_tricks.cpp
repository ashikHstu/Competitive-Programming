
/*


_________________________________________________________________________
       19) Number of Digit of n! after converted to base b
_________________________________________________________________________

Complexity : O(n)
int NODigit(int n,int b)  /// number of digit of n! after converted to base b
       {
           double numberOfDigit = 0.0;
           for (int i = 2; i <= n; i++)
           {
               numberOfDigit += log10(i);
           }
           numberOfDigit /= log10(b);

           return floor(numberOfDigit + 1e-9) + 1;
       }
*/
