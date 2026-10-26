#include <iostream>
#include "furl.hpp"

using namespace std;

int main() {
  cout << "Furl Test" << endl;

  Furl::Memory mem;
  Furl::VM vm(mem);

  Furl::Inst program[] = {
    { .opcode = OP_MOV, .dest = 0, .src = 0, .reserved = 0, .imm = 42 },
    { .opcode = OP_HALT }
  };

  vm.run(program, sizeof(program) / sizeof(program[0]));
  cout << "Furl program executed successfully!" << endl;
  cout << "R0: " << vm.get_reg(0) << endl;

  return 0;
}

