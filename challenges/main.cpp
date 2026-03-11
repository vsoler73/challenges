#include <cassert>
#include <cmath>
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

float distance(const bitstream& a){

    std::vector<double> english_freq;
    if (english_freq.empty())
    {
        english_freq.resize(256,0.0);
            // whitespace
            english_freq[' ']  = 0.1746;
            english_freq['\n'] = 0.0100;
            english_freq['\t'] = 0.0020;

            // lowercase letters
            english_freq['e']=0.0983; english_freq['t']=0.0710; english_freq['a']=0.0639;
            english_freq['o']=0.0574; english_freq['n']=0.0538; english_freq['h']=0.0510;
            english_freq['i']=0.0506; english_freq['s']=0.0484; english_freq['r']=0.0453;
            english_freq['d']=0.0376; english_freq['l']=0.0330; english_freq['u']=0.0223;
            english_freq['c']=0.0187; english_freq['m']=0.0186; english_freq['w']=0.0179;
            english_freq['g']=0.0170; english_freq['f']=0.0161; english_freq['y']=0.0148;
            english_freq['p']=0.0129; english_freq['b']=0.0125; english_freq['v']=0.0083;
            english_freq['k']=0.0054; english_freq['j']=0.0016; english_freq['x']=0.0014;
            english_freq['q']=0.0012; english_freq['z']=0.0009;

            // uppercase letters (roughly same distribution but rarer overall)
            english_freq['E']=0.0120; english_freq['T']=0.0090; english_freq['A']=0.0080;
            english_freq['O']=0.0075; english_freq['N']=0.0070; english_freq['H']=0.0065;
            english_freq['I']=0.0063; english_freq['S']=0.0060; english_freq['R']=0.0058;
            english_freq['D']=0.0045; english_freq['L']=0.0040; english_freq['U']=0.0028;
            english_freq['C']=0.0025; english_freq['M']=0.0024; english_freq['W']=0.0023;
            english_freq['G']=0.0021; english_freq['F']=0.0020; english_freq['Y']=0.0019;
            english_freq['P']=0.0016; english_freq['B']=0.0015; english_freq['V']=0.0010;
            english_freq['K']=0.0007; english_freq['J']=0.0002; english_freq['X']=0.0002;
            english_freq['Q']=0.0002; english_freq['Z']=0.0001;

            // digits
            english_freq['0']=0.0005; english_freq['1']=0.0005; english_freq['2']=0.0005;
            english_freq['3']=0.0005; english_freq['4']=0.0005; english_freq['5']=0.0005;
            english_freq['6']=0.0005; english_freq['7']=0.0005; english_freq['8']=0.0005;
            english_freq['9']=0.0005;

            // punctuation
            english_freq['.']=0.0065;
            english_freq[',']=0.0060;
            english_freq['\'']=0.0025;
            english_freq['"']=0.0025;
            english_freq['-']=0.0020;
            english_freq[':']=0.0003;
            english_freq[';']=0.0002;
            english_freq['!']=0.0003;
            english_freq['?']=0.0005;
            english_freq['(']=0.0002;
            english_freq[')']=0.0002;
            english_freq['[']=0.0001;
            english_freq[']']=0.0001;
            english_freq['{']=0.00005;
            english_freq['}']=0.00005;
            english_freq['/']=0.0001;
            english_freq['\\']=0.0001;
            english_freq['&']=0.0001;
            english_freq['@']=0.00005;
            english_freq['#']=0.00005;
            english_freq['$']=0.00005;
            english_freq['%']=0.00005;
            english_freq['*']=0.00005;
            english_freq['+']=0.0001;
            english_freq['=']=0.0001;
            english_freq['<']=0.00005;
            english_freq['>']=0.00005;
            english_freq['|']=0.00002;
            english_freq['^']=0.00002;
            english_freq['~']=0.00002;
            english_freq['`']=0.00002;

    }

    std::vector<float> proportion (256,0.0);
    for (int i=0; i<a.size(); i++){
        proportion[a[i]]+=1.0/(a.size());
    }

    float result=0;
    for (int i=0; i<256; i++){
        result += pow(proportion[i]-english_freq[i],2);
    }
    return result;
}

std::string decodage(const bitstream& a){
    float result=1;
    int best_i=0;
    for (int i=0; i<256; i++){
        float d = distance(a^i);
        std::cerr<<std::hex<<i<<std::dec<<" "<<d<<"\n";
        if (d<=result){
            result = d;
            best_i=i;
        }
    }
    return (a^best_i).to_string();
}

bool challenge3(){
    return true;
}

int main(int argc, char *argv[])
{
    bitstream a;
    a.init_hex("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
    std::cerr<<decodage(a)<<"\n";
    //return challenge1() + challenge2();
}

