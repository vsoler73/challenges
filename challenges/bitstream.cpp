#include "bitstream.h"
#include <iostream>

bitstream::bitstream() {}

void bitstream::init_hex(const std::string& n){
    data.clear();
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

void bitstream::init_random(int n){
    data.clear();
    for (int i=0; i<n; i++)
        data.push_back(lrand48()&0xff);
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

std::string bitstream::to_base64() const{
    std::string Lbase64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string result64;
    for (int i=0; i<(data.size()/3); i++){
        uint32_t groupe3 = data[3*i];
        groupe3<<=8;
        groupe3 = groupe3 + data[3*i+1];
        groupe3<<=8;
        groupe3 = groupe3 + data[3*i+2];
        for (int j=3; j>-1; j--){
            result64.push_back(Lbase64[((groupe3>>(j*6))&63)]);
        }
    }
    if (data.size()%3==0)
        return result64;
    if (data.size()%3==1){
        uint32_t rest = data.back()<<4;
        for (int j=1; j>-1; j--)
            result64.push_back(Lbase64[((rest>>(j*6))&63)]);
        result64.push_back('=');
        result64.push_back('=');
    }
    if (data.size()%3==2){
        uint32_t rest = (data[data.size()-2]<<10) + (data.back()<<2);
        for (int j=2; j>-1; j--)
            result64.push_back(Lbase64[((rest>>(j*6))&63)]);
        result64.push_back('=');
    }
    return result64;
}

bitstream bitstream::operator +(const bitstream& a)const{
    bitstream result=*this;
    for (uint i=0; i<a.data.size(); i++)
        result.data.push_back(a.data[i]);
    return result;
}


































