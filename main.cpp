#include <iostream>
#include <fstream>
#include<string>     
#include <time.h>  
#include <cmath>    
using namespace std;

int main () {
  int target;
  int domainSize;
  int consecGoal;
  int trialNum;
  long int seedUsed;
  bool seeOutput = false;

  cout << "Number of faces on dice: ";
  cin >> domainSize;
  cout << endl
  << "yahtzee requires this many rolls: ";
  cin >> consecGoal; 
  cout << endl
  << "number of trials : ";
  cin >> trialNum;
  
  cout <<"input seed or input 0 for seed relating to current time : ";
  cin >> seedUsed;
   /* initialize random seed: */
   if (seedUsed == 0) seedUsed = time(NULL);
  srand (seedUsed);

    target = rand() % domainSize + 1;
    cout << "The target value is : "  << target <<  
    endl <<" enter any input to continue"<<  endl; 
    int z =0;
    cin >> z; 

  ofstream myfile;
  myfile.open ("test.txt");
  myfile << "sample_size:" <<domainSize << 
  " " << "recurrence_goal:"<<consecGoal << endl;
  myfile << "trial-count iteration-count\n";

  for (int i = 0; trialNum > i; i++) {
    int iterations = 0;
    for (int j = 0; consecGoal > j; j++) {
      int test = rand() % domainSize + 1;
      iterations++;
      if (!seeOutput) cout << test << endl;
      if (target != test) j = -1; // to restart loop. Set to -1 because post-increment
    }
  myfile << to_string(i+1) << " " << to_string(iterations); 
  if (i == 0) myfile <<  " " << seedUsed;
  myfile << endl;
  }
  
  myfile.close();
  return 0;
}