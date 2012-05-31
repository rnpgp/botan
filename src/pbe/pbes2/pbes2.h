/*
* PKCS #5 v2.0 PBE
* (C) 1999-2007 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_PBE_PKCS_v20_H__
#define BOTAN_PBE_PKCS_v20_H__

#include <botan/pbe.h>
#include <botan/block_cipher.h>
#include <botan/hash.h>
#include <botan/pipe.h>

namespace Botan {

/**
* PKCS #5 v2.0 PBE
*/
class BOTAN_DLL PBE_PKCS5v20 : public PBE
   {
   public:
      /**
      * @param cipher names a block cipher
      * @return true iff PKCS #5 knows how to use this cipher
      */
      static bool known_cipher(const std::string& cipher);

      OID get_oid() const;

      std::vector<byte> encode_params() const;

      std::string name() const;

      void write(const byte[], size_t);
      void start_msg();
      void end_msg();

      /**
      * Load a PKCS #5 v2.0 encrypted stream
      * @param input is the input source
      */
      PBE_PKCS5v20(const std::vector<byte>& params,
                   const std::string& passphrase);

      /**
      * @param cipher the block cipher to use
      * @param hash the hash function to use
      */
      PBE_PKCS5v20(BlockCipher* cipher,
                   HashFunction* hash,
                   const std::string& passphrase,
                   std::chrono::milliseconds msec,
                   RandomNumberGenerator& rng);

      ~PBE_PKCS5v20();
   private:
      void flush_pipe(bool);

      Cipher_Dir direction;
      BlockCipher* block_cipher;
      HashFunction* hash_function;
      secure_vector<byte> salt, key, iv;
      size_t iterations, key_length;
      Pipe pipe;
   };

}

#endif
