#include <cassert>
#include <iostream>
#include "bitstream.h"

bool challenge1()
{
    int result=0;

    for (int i=0; i<100; i++){
        bitstream a;
        a.init_random(lrand48()%100);
        std::string b=a.to_base64();
        bitstream c;
        c.init_base64(b);

        if (a.to_hex() == c.to_hex())
            result+=1;
    }
    return result==100;
}

bool challenge2()
{
    bitstream a;
    a.init_hex("1c0111001f010100061a024b53535009181c");
    bitstream b;
    b.init_hex("686974207468652062756c6c277320657965");
    bitstream c;
    c.init_hex("746865206b696420646f6e277420706c6179");
    return (a^b)==c;
}

int main(int argc, char *argv[])
{
    return challenge1() + challenge2();
}

