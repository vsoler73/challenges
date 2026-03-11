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
    void init_base64(const std::string& n);
    std::string to_base64() const;
    std::string to_hex()const;
    std::string to_string()const;
    void init_random(int n);
    int size()const { return data.size(); }

    bitstream operator +(const bitstream&)const;
    bitstream operator ^(const bitstream&)const;
    bitstream operator ^(uint8_t)const;
    uint8_t   operator [](int i)const{ return data[i]; }
    bool      operator ==(const bitstream&)const;

private:
    std::vector<uint8_t> data;
};

#endif // BITSTREAM_H
