#include <fstream>
#include <iostream>
#include <istream>
#include <limits>
#include <string>

using std::cin;
using std::cout;
using std::string;

unsigned char read_0_1() {
  while (true) {
    std::string enter;
    cin >> enter;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "Ошибка ввода данных.\nПовторите ввод:";
      continue;
    }
    if (enter == "0" || enter == "1") {
      return enter[0];
    } else {
      cout << "Ошибка ввода.\nПовторите ввод: ";
    }
  }
}
unsigned read_uint(string data) {
  unsigned num;
  string enter;
  bool isnum = true;
  while (true) {
    if (data == "") {
      cin >> enter;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Ошибка ввода данных.\n";
        isnum = false;
      }
    } else {
      enter = data;
    }
    for (unsigned int i = 0; enter[i]; i++) {
      if (!isdigit(enter[i])) {
        isnum = false;
        cout << "Недопустимый символ: " << enter[i] << " (" << i << ")\n";
      }
    }
    if (isnum) {
      num = atoi(enter.c_str());
      return num;
    } else {
      cout << "При вводе допущена ошибка.\n";
      isnum = true;
    }
    if (data != "") {
      return 0;
    } else {
      cout << "Повторите ввод: ";
    }
  }
}
int *read_arr(unsigned n, string data) {
  string buf = "";
  string enter;
  bool seqense = true;
  int *arr = new int[n + 1];
  arr[0] = 1;
  unsigned iter = 0;
  while (true) {
    if (data == "") {
      cin >> enter;
    } else {
      enter = data;
    }
    for (unsigned int i = 0; enter[i]; i++) {
      if (enter[i] == '-') {
        if (buf == "") {
          buf += enter[i];
        } else {
          cout << "Недопустимый символ: " << enter[i] << '(' << i << ")\n";
          seqense = false;
        }
      } else if (isdigit(enter[i])) {
        if (buf != "0") {
          buf += enter[i];
        } else {
          cout << "Недопустимый символ: " << enter[i] << '(' << i << ")\n";
          seqense = false;
        }
      } else if (enter[i] == ',' || enter[i] == '\n') {
        iter++;
        if (iter > n) {
          enter = "";
          buf = "";
          break;
        }
        arr[iter + 1] = atoi(buf.c_str());
        buf = "";
      } else {
        cout << "Недопустимый символ: " << enter[i] << '(' << i << ")\n";
        seqense = false;
      }
      if (!seqense) {
        enter = "";
        buf = "";
        break;
      }
      if (iter > n + 1) {
        enter = "";
        buf = "";
        seqense = false;
        break;
      }
    }
    if (!seqense) {
      if (data == "") {
        cout << "Повторите ввод данных: ";
      }
      seqense = true;
      iter = 0;
      if (data != "") {
        arr[0] = -1;
        return arr;
      }
      continue;
    }
    if (buf != "") {
      iter++;
      if (iter > n) {
        enter = "";
        buf = "";
        break;
      }
      arr[iter + 1] = atoi(buf.c_str());
    }
    if (iter == n) {
      return arr;
    } else {
      cout << "Введенное кол-во данных не соответствует " << n << "\n";
      if (data == "") {
        cout << "Повторите ввод данных: ";
      }
      iter = 0;
    }
    if (data != "") {
      arr[0] = -1;
      return arr;
    }
  }
  return arr;
}