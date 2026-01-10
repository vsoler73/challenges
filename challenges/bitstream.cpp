#include "bitstream.h"
#include <iostream>

bitstream::bitstream() {}

void bitstream::init_hex(const std::string& n){
    for (uint i=0; i<n.size(); i=i+2){
        int v1=0, v2=0;
        if (n[i]>='a' && n[i]<='f'){
            v1=n[i]-'a'+0x0a;
        }
        else if (n[i]<='9' && n[i]>='0')
            v1=n[i]-'0';
        else
            std::cerr<<"bad caractre in hex string : "<<(int)n[i]<<"\n" ;

        if (n[i+1]>='a' && n[i+1]<='f'){
            v2=n[i+1]-'a'+0x0a;
        }
        else if (n[i+1]<='9' && n[i+1]>='0')
            v2=n[i+1]-'0';
        else
            std::cerr<<"bad caractre in hex string : "<<(int)n[i+1]<<"\n" ;
        data.push_back(v2+v1*16);

    }
}
std::string bitstream::to_hex()const{
    std::string result;
    for (uint i=0; i<data.size(); ++i){
        int v1=data[i]>>4, v2=data[i]&15;
        if (v1>9)
            result.push_back(v1+'a'-0x0a);
        else
            result.push_back(v1+'0');
        if (v2>9)
            result.push_back(v2+'a'-0x0a);
        else
            result.push_back(v2+'0');
    }
    return result;
}
