#include <cstdint>

class Memory {
private:
    uint8_t data[65536] = { 0 };
public:
    uint8_t read(uint16_t address) const {
        return data[address];
    }

    void write(uint16_t address, uint8_t value) {
        data[address] = value;
    }
};
