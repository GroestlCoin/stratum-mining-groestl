/*-
 * Copyright 2009 Colin Percival, 2011 ArtForz, 2013 Neisklar,
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file was originally written by Colin Percival as part of the Tarsnap
 * online backup system.
 */

#include "blake.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "sphlib/sph_groestl.h"


void grs80(const char* input, char* output)
{
	uint32_t hashA[16],hashB[16];	
	sph_groestl512_context	ctx_groestl[2];

	sph_groestl512_init(&ctx_groestl[0]);
	sph_groestl512 (&ctx_groestl[0], input, 80); 
	sph_groestl512_close(&ctx_groestl[0], hashA); 

	sph_groestl512_init(&ctx_groestl[1]);
	sph_groestl512 (&ctx_groestl[1], hashA, 64); 
	sph_groestl512_close(&ctx_groestl[1], hashB); 

	memcpy(output, hashB, 32);
}

void grs21(const char* input, char* output)
{
        uint32_t hashA[16],hashB[16];
        sph_groestl512_context  ctx_groestl[2];

        sph_groestl512_init(&ctx_groestl[0]);
        sph_groestl512 (&ctx_groestl[0], input, 21);
        sph_groestl512_close(&ctx_groestl[0], hashA);

        sph_groestl512_init(&ctx_groestl[1]);
        sph_groestl512 (&ctx_groestl[1], hashA, 64);
        sph_groestl512_close(&ctx_groestl[1], hashB);

        memcpy(output, hashB, 32);
}
