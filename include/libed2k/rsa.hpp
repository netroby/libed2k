/*

Copyright (c) 2011, Arvid Norberg, Magnus Jonsson
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the distribution.
    * Neither the name of the author nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef LIBED2K_SIGN_HPP_INCLUDED
#define LIBED2K_SIGN_HPP_INCLUDED

#include "libed2k/config.hpp"
#include "libed2k/hasher.hpp"
#include "libed2k/peer_id.hpp" // for sha1

namespace libed2k
{
	// both of these use SHA-1 as the message digest to be signed/verified

	// returns the size of the resulting signature
    LIBED2K_EXTRA_EXPORT int sign_rsa(sha1_hash const& digest
		, char const* private_key, int private_len
		, char* signature, int sig_len);

	// returns true if the signature is valid
    LIBED2K_EXTRA_EXPORT bool verify_rsa(sha1_hash const& digest
		, char const* public_key, int public_len
		, char const* signature, int sig_len);

	// returns false if it fails, for instance if the key
	// buffers are too small. public_len and private_len
	// are in-out values, set to the actual sizes
    LIBED2K_EXTRA_EXPORT bool generate_rsa_keys(char* public_key, int* public_len
		, char* private_key, int* private_len, int key_size);
}

#endif // LIBED2K_SIGN_HPP_INCLUDED
