#include "dataio.h"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::ifstream;
using std::string;

int main() {
  std::ifstream fin("in.txt");
  std::ofstream fout("out.txt");
  string enter = "";
  unsigned char inl;
  unsigned char outl;
  unsigned n{0};
  int a[30];
  int b[40];
  int *c;
  bool t;
  while (true) {
    if (fin.is_open() && fout.is_open()) {
      cout << "Ввод с консоли (0) или с файл(1): ";
      inl = read_0_1();
      cout << "Вывод в консоли (0) или в файл(1): ";
      outl = read_0_1();

      if (inl == '0') {
        cout << "Введите n: ";
        n = read_uint("");
        int *arr;
        cout << "Введите через запятую 30 чисел:\n";
        arr = read_arr(30, "");
        for (unsigned i = 0; i < 30; i++) {
          a[i] = arr[i];
        }

        cout << "Введите через запятую 40 чисел:\n";
        arr = read_arr(40, "");
        for (unsigned i = 0; i < 40; i++) {
          b[i] = arr[i];
        }
        delete[] arr;
        cout << "Введите через запятую " << n << " чисел:\n";
        c = read_arr(n, "");

      } else if (inl == '1') {
        fin >> enter;
        n = read_uint(enter);
        int *farr;
        if (n != 0) {
          fin >> enter;
          farr = read_arr(30, enter);
          for (unsigned i = 0; i < 30; i++) {
            a[i] = farr[i];
          }
          fin >> enter;
          farr = read_arr(40, enter);
          for (unsigned i = 0; i < 40; i++) {
            b[i] = farr[i];
          }
          fin >> enter;
          farr = read_arr(n, enter);
          for (unsigned i = 0; i < n; i++) {
            a[i] = farr[i];
          }
          delete[] farr;
        }
      }
      t = task(a, b, c, n);
      if (outl == '0') {
        if (t) {
          cout << "В последовательности с отрицательное число встречается "
                  "раньше.\n";
        } else {
          cout << "В последовательности a,b отрицательное число встречается "
                  "раньше.\n";
        }
      } else if (outl == '1') {
        if (t) {
          fout << "В последовательности с отрицательное число встречается "
                  "раньше.\n";
        } else {
          fout << "В последовательности a,b отрицательное число встречается "
                  "раньше.\n";
        }
      }
      if (inl == '0') {
        cout << "Хотите продолжить(0/1): ";
        inl = read_0_1();
        if (inl == '0') {
          break;
        }
      } else if (inl == '1') {
        break;
      }
    } else {
      cout << "Не удалось открыть файл(ы)!\n";
      break;
    }
  }
  delete[] c;
}
