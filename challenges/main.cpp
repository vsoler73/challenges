#include <iostream>
#include "bitstream.h"

int main(int argc, char *argv[])
{
    bitstream b;
    b.init_hex("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");
    std::cerr<<b.to_hex()<<"\n";

    bitstream c;
    c.init_random(48);
    std::cerr<<c.to_hex()<<"\n";

    bitstream d = b + c;
    std::cerr<<d.to_hex()<<"\n";

    std::cerr<<b.to_base64()<<"\n";

}

