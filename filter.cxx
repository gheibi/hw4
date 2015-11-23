//This program was written at 12 pm on 23d November 2015 by "Ali Gheibi"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void reading_data( double*const, const int, const string);
void average( double*x, const int N, const int optimized_num );
void print(double* p, const int N);

int main(void){
  const int N=237;
  const int optimized_num=100;  // optimized_num is the number of optimization
                               // of local average by repeatation of loop
  const string filename="noisy.txt";
  double*p= new double [N];
  
  reading_data(p,N,filename);
  average (p,N, optimized_num);
  print(p,N);
  
  delete [] p;
 return 0;
}

void reading_data( double*const p, const int N, const string fname){
  
  ifstream in(fname.c_str());
    
  for(int i=0; i<N; i++)
    in >> p[i];
 
    in.close();
}

void average( double*p, const int N, const int optimized_num ){
 // first loop optimizes the data by repeating the loop
 // second loop calculetes the local average
  for(int i=0; i< optimized_num; i++){
    
  double b=0, a=0; 
  for(int i=0; i<N; i++){
    a=p[i];
    p[i]=(p[i+1]+a+b)/3.0;
    b=a;
   }
  }
}
  
void print(double* p, const int N){
  ofstream out("filtered.txt");
   for(int i=0; i<N; i++)
       out << p[i] << endl;

  out.close();
}

