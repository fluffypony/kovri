/**
 * Copyright (c) 2015-2016, The Kovri I2P Router Project
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 *    of conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be
 *    used to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_CORE_CRYPTO_SIGNATUREBASE_H_
#define SRC_CORE_CRYPTO_SIGNATUREBASE_H_

#include <cryptopp/osrng.h>

namespace i2p {
namespace crypto {

class Verifier {
 public:
  virtual ~Verifier() {}
  virtual bool Verify(
      const uint8_t* buf,
      size_t len,
      const uint8_t* signature) const = 0;
  virtual size_t GetPublicKeyLen() const = 0;
  virtual size_t GetSignatureLen() const = 0;
  virtual size_t GetPrivateKeyLen() const = 0;
};

class Signer {
 public:
  virtual ~Signer() {}
  virtual void Sign(
      const uint8_t* buf,
      size_t len,
      uint8_t* signature) const = 0;
};

class RawVerifier {
 public:
  virtual ~RawVerifier() {}

  virtual void Update(
      const uint8_t* buf,
      size_t len) = 0;

  virtual bool Verify(
      const uint8_t* signature) = 0;
};

}  // namespace crypto
}  // namespace i2p

#endif  // SRC_CORE_CRYPTO_SIGNATUREBASE_H_
