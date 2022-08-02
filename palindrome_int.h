#include <iostream>

using namespace std;

/*

1221
1  122
12  12

1221
1 122
12 12

121

1 12
12321
1 1232
12 123
123 12
1221

1221
21 21  
12  12
rev(one-half) == (another half)

solution is to create reverse of the number till
reversed number is less than original number.

now, rev number contains rev of first-half.
remaining number contains  second-half. 
if number originally had even no of digits, rev == rem.
else rev/10 == rem
handle 0 , negative, and number ending with 0 saparately. 

*/
bool isPalindrome(int x){
    if (x<0 || (x!=0 && x%10==0)) return false;
        
    int sum  = 0;
        
    while (sum < x){
        sum = sum*10 + x%10;
        x /= 10;
    }
    return sum==x || x == sum/10;
}

