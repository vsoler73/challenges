#include <cassert>
#include <iostream>
#include "bitstream.h"

int main(int argc, char *argv[])
{
    bitstream b;
    b.init_hex("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");
//    std::cerr<<b.to_hex()<<"\n";

    bitstream c;
    for (int i=0; i<100; i++){
    c.init_random(i);
    std::string d=c.to_base64();
    std::string e=c.to_hex();

    c.init_base64(c.to_base64());
    std::string f=c.to_base64();
    std::string g=c.to_hex();

    assert (d==f);
    assert (e==g);
    }
}

