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
  bool rs = true;
  char t;
  while (true) {
    if (fin.is_open() && fout.is_open()) {
      cout << "Ввод с консоли (0) или с файл(1): ";
      inl = read_0_1();
      cout << "Вывод в консоли (0) или в файл(1): ";
      outl = read_0_1();
      if (inl == '0') {
        cout << "Введите n: ";
        n = read_uint("");
        c = new int[n];
        int *arr;
        cout << "Введите через запятую 30 чисел:\n";
        arr = read_arr(30, "");
        for (unsigned i = 1; i < 31; i++) {
          a[i - 1] = arr[i];
        }
        cout << "Введите через запятую 40 чисел:\n";
        arr = read_arr(40, "");
        for (unsigned i = 1; i < 41; i++) {
          b[i - 1] = arr[i];
        }
        cout << "Введите через запятую " << n << " чисел:\n";
        arr = read_arr(n, "");
        for (unsigned i = 1; i < n + 1; i++) {
          c[i - 1] = arr[i];
        }
        delete[] arr;
      } else if (inl == '1') {
        fin >> enter;
        n = read_uint(enter);
        int *farr;
        if (n != 0) {
          c = new int[n];
          fin >> enter;
          farr = read_arr(30, enter);
          if (farr[0] == 1) {
            for (unsigned i = 0; i < 30; i++) {
              a[i] = farr[i + 1];
            }
          } else {
            rs = false;
            break;
          }
          fin >> enter;
          farr = read_arr(40, enter);
          if (farr[0] == 1) {
            for (unsigned i = 0; i < 40; i++) {
              b[i] = farr[i + 1];
            }
          } else {
            rs = false;
            break;
          }
          fin >> enter;
          farr = read_arr(n, enter);
          if (farr[0] == 1) {
            for (unsigned i = 0; i < n; i++) {
              c[i] = farr[i + 1];
            }
          } else {
            rs = false;
            break;
          }
          delete[] farr;
        } else {
          cout << "Ошибка в введеных в файл данных.\n";
          rs = false;
        }
      }
      if (rs) {
        t = task(a, b, c, n);
        if (outl == '0') {
          if (t == 'c') {
            cout << "В последовательности с отрицательное число встречается "
                    "раньше.\n";
          } else if (t == 'a' || t == 'b') {
            cout << "В последовательности a,b отрицательное число встречается "
                    "раньше.\n";
          } else if (t == 'e') {
            cout << "Отрицательных чисел не найдено.\n";
          }
        } else if (outl == '1') {
          if (t == 'c') {
            fout << "В последовательности с отрицательное число встречается "
                    "раньше.\n";
          } else if (t == 'a' || t == 'b') {
            fout << "В последовательности a,b отрицательное число встречается "
                    "раньше.\n";
          } else if (t == 'e') {
            cout << "Отрицательных чисел не найдено.\n";
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
        break;
      }
    } else {
      cout << "Не удалось открыть файл(ы)!\n";
      break;
    }
  }
  delete[] c;
  fin.close();
  fout.close();
}