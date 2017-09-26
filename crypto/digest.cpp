#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <openssl/evp.h>

std::string hashString(const std::string & str);

int main(int, char**)
{
   std::cout << "Hello! --> " << hashString( "Hello!") << "\n";
   std::cout << "Hello. --> " << hashString( "Hello.") << "\n";
   return 0;
}

std::string hashString(const std::string & str)
{
   // initialize OpenSSL's EVP digest context
   EVP_MD_CTX * context = EVP_MD_CTX_create();
   if( ! context) throw "EVP_MD_CTX_create() failed";
   // set the digest type to SHA256 
   if( ! EVP_DigestInit_ex(context, EVP_sha256(), NULL))
       throw "EVP_DigestInit_ex() failed";

   // feed the data to the hash function
   if( ! EVP_DigestUpdate(context, str.c_str(), str.length()))
       throw "EVP_DigestUpdate() failed";

   // extract the result into hashBuff
   unsigned char hashBuff[EVP_MAX_MD_SIZE];
   unsigned int hashLen = 0;
   if(! EVP_DigestFinal_ex(context, hashBuff, & hashLen))
       throw "EVP_DigestFinal_ex() failed";

   // format the binary hash to a nice hexadecimal string
   std::stringstream ss;
   for(unsigned int i = 0 ; i < hashLen ; ++ i)
       ss << std::hex << std::setw(2) << std::setfill('0') << (int) hashBuff[i];

   // clean up
   EVP_MD_CTX_destroy(context);
   return ss.str();
} // end of hashString()
//To compile it g++ digest.cpp -l crypto -o digest.out
