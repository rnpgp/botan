/**
* Stream Cipher Default Implementation for IV and Seek
* (C) 1999-2007 Jack Lloyd
*/

#include <botan/base.h>

namespace Botan {

/*************************************************
* Default StreamCipher Resync Operation          *
*************************************************/
void StreamCipher::resync(const byte[], u32bit length)
   {
   if(length)
      throw Exception("The stream cipher " + name() +
                      " does not support resyncronization");
   }

/*************************************************
* Default StreamCipher Seek Operation            *
*************************************************/
void StreamCipher::seek(u32bit)
   {
   throw Exception("The stream cipher " + name() + " does not support seek()");
   }

}
