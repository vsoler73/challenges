#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <cstdint>
#include <string>
#include <vector>

class bitstream
{
public:
    bitstream();
    void init_hex(const std::string& n);
    std::string to_base64() const{
        return std::string();
    };
    std::string to_hex()const;
private:
    std::vector<uint8_t> data;
};

#endif // BITSTREAM_H
