#include<iostream>
#include<string>
#include<vector>

using namespace std;

class use_transform{

  public:

   void toUpper(string &A){
       transform(A.begin(),  A.end(), A.begin(), [](char ch){return toupper(ch);});
   }


   void toLower(string &A){
       transform(A.begin(), A.end(), A.begin(), [](char ch){return tolower(ch);});
   }

   void toIncrement(vector<int> &A){
       transform(A.begin(), A.end(), A.begin(), [](int a){return ++a;});
   }

   

};


