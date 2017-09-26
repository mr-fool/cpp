#include <iostream> 
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/hmac.h>

int main( int, char **)
{
   std::string key = "mySecret", data = "Stop being a pleb";

   unsigned char buff[EVP_MAX_MD_SIZE];
   unsigned int len = EVP_MAX_MD_SIZE;
   HMAC_CTX ctx;
   HMAC_CTX_init( & ctx);
   HMAC_Init_ex( & ctx, key.c_str(), key.length(), EVP_sha1(), 0);
   HMAC_Update( & ctx, reinterpret_cast<const unsigned char *> (data.c_str()), data.length());
   HMAC_Final( & ctx, buff, & len);
   HMAC_CTX_cleanup(&ctx);

   // format the binary hash to a nice hexadecimal string
   std::stringstream ss;
   for(unsigned int i = 0 ; i < len ; ++ i)
ss << std::hex << std::setw(2) << std::setfill('0') << (int) buff[i];
   std::cout << "hmac=" << ss.str() << "\n";
   return 0;
}
//g++ HMAC.cpp -l crypto -o HMAC.out
