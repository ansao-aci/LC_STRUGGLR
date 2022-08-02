#include<vector>
#include<utility>
#include<string>
#include<algorithm>


/*
LAMBDA EXPRESSION to allow us write an inline function
 which can be used for short snippets of code that are not going to be REUSED and NOT WORTH NAMING. 

*/
using  namespace std;

class lambdaComparator{
    public:

    void sort(vector<pair<string,int>> &A);
};
class desiComparator{
    public:

    void sort(vector<pair<string,int>> &A);
};


void lambdaComparator::sort(vector<pair<string,int>> &A){
    std::sort(A.begin(), A.end(), [](auto &left, auto &right) { return  left.second < right.second;});
}

struct scomp{
    bool operator()  (const pair<string,int> &left, const pair<string,int> &right){
        return left.second < right.second;
    }
};

void desiComparator::sort(vector<pair<string,int>> &A){
    std::sort(A.begin(), A.end(), scomp());
}