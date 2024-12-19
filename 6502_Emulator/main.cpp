#include "cpu6502.cpp"
#include <iostream>

using namespace std;

int main() {
    CPU6502 cpu;
    cpu.memory[0xFFFC] = 0x00; // Initialising startup address
    cpu.memory[0xFFFD] = 0x80;

    // Program: LDA #$42, NOP
    cpu.memory[0x8000] = 0xA9; // LDA
    cpu.memory[0x8001] = 0x42; // #$42
    cpu.memory[0x8002] = 0xEA; // NOP

    cpu.reset();

    cpu.executeInstruction(); // Executing LDA
    cpu.executeInstruction(); // Executing NOP

    // Check
    if (cpu.A == 0x42) {
        cout << "Test was successful!" << endl;
    }
    else {
        cout << "Error!" << endl;
    }

    return 0;
}
