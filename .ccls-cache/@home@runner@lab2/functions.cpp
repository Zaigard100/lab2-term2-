#include <iostream>
#include <fstream>

using std::cout;

bool task(int a[],int b[], int* c, unsigned n){
  for(unsigned i=0;i<n;i++){
    if(i<30){
      if(a[i]<0){
        return false;
      }
    }
    if(i<40){
      if(b[i]<0){
        return false;
      }
     }
    if(c[i]<0){
      return true;
    }
  }
  cout<< "Отрицатеьных чисел не найдено.\n";
}
