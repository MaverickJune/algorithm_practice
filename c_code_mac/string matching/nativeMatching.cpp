#include <vector>
#include <iostream>
#include <string>
using namespace std;

void NaiveMatching(string A, string P)
{
    int n = A.size();
    int m = P.size();

    for(int i=0; i<n-m+1; i++){
        string sub_A = A.substr(i,m);
        if(sub_A == P)
        {
            cout << "substring matched!";
            return;
        }
    }

    cout << "There is no matching substring!";
}

int main()
{
    string origin = "tiger is good and fast";
    string sub = "tiger";

    NaiveMatching(origin, sub);
    return 0;
}

