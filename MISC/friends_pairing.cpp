// Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

#include<bits/stdc++.h>
using namespace std;

int countFriendsPairingRec(int n)
{
    if(n<=2)
    {
        return n;
    }
    // 1* => Person not paired , so only one choice
    // (n-1)* => Person is to be paired with someone which gives us (n-1) choices to pair
    // and we will be left with (n-2) persons.
    return 1*countFriendsPairingRec(n-1) + (n-1)*countFriendsPairingRec(n-2);
}

int main()
{
    int n = 10;
    cout<<"Number of ways to pair : "<<countFriendsPairingRec(n)<<endl;  
    return 0;
}