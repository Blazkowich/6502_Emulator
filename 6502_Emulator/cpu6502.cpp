#include <cstdint>
#include <stdexcept>

using namespace std;

class CPU6502 {
public:
    // Registers
    uint8_t A = 0;  // Accumulator
    uint8_t X = 0;  // Index register X
    uint8_t Y = 0;  // Index register Y
    uint8_t SP = 0xFD;  // Stack pointer
    uint16_t PC = 0;    // Program counter
    uint8_t P = 0x34;   // Status flag register

    // Processor memory (64 KB)
    uint8_t memory[65536] = { 0 };

    // Methods
    void reset() {
        // Set program counter from reset vector
        PC = (memory[0xFFFD] << 8) | memory[0xFFFC];
        SP = 0xFD;
        P = 0x34;
        A = X = Y = 0;
    }

    uint8_t fetchByte() {
        return memory[PC++];
    }

    uint16_t fetchWord() {
        uint16_t word = memory[PC] | (memory[PC + 1] << 8);
        PC += 2;
        return word;
    }

    void executeInstruction() {
        uint8_t opcode = fetchByte();
        switch (opcode) {
        case 0xEA: // NOP (No Operation)
            break;

        case 0xA9: { // LDA #immediate
            A = fetchByte();
            // Set Zero flag (Z) if accumulator is 0
            if (A == 0) {
                P |= 0x02;
            }
            else {
                P &= ~0x02;
            }

            // Set Negative flag (N) if the high bit (bit 7) of A is set
            if (A & 0x80) {
                P |= 0x80;
            }
            else {
                P &= ~0x80;
            }
            break;
        }

        default:
            throw runtime_error("Unknown instruction!");
        }
    }
};
