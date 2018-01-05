#include "x17.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sph_blake.h"
#include "sph_bmw.h"
#include "sph_groestl.h"
#include "sph_jh.h"
#include "sph_keccak.h"
#include "sph_skein.h"
#include "sph_luffa.h"
#include "sph_cubehash.h"
#include "sph_shavite.h"
#include "sph_simd.h"
#include "sph_echo.h"
#include "sph_hamsi.h"
#include "sph_fugue.h"
#include "sph_shabal.h"
#include "sph_whirlpool.h"
#include "sph_haval.h"
#include "sph_sha2.h"

void crypto_hash(const char* input, char* output)
{
    sph_blake512_context       ctx_blake;
    sph_bmw512_context         ctx_bmw;
    sph_groestl512_context     ctx_groestl;
    sph_skein512_context       ctx_skein;
    sph_jh512_context          ctx_jh;
    sph_keccak512_context      ctx_keccak;
    sph_luffa512_context          ctx_luffa1;
    sph_cubehash512_context       ctx_cubehash1;
    sph_shavite512_context        ctx_shavite1;
    sph_simd512_context	          ctx_simd1;
    sph_echo512_context           ctx_echo1;
    sph_hamsi512_context          ctx_hamsi1;
    sph_fugue512_context          ctx_fugue1;
    sph_shabal512_context         ctx_shabal1;
    sph_whirlpool_context         ctx_whirlpool1;
    sph_haval256_5_context        ctx_haval1;
    sph_sha512_context            ctx_sha1;

    //these uint512 in the c++ source of the client are backed by an array of uint32
    uint32_t hashA[16], hashB[16];	

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, 80);
    sph_blake512_close (&ctx_blake, hashA);

    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, hashA, 64);
    sph_bmw512_close(&ctx_bmw, hashB);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, hashB, 64);
    sph_groestl512_close(&ctx_groestl, hashA);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, hashA, 64);
    sph_skein512_close (&ctx_skein, hashB);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, hashB, 64);
    sph_jh512_close(&ctx_jh, hashA);

    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, hashA, 64);
    sph_keccak512_close(&ctx_keccak, hashB);
	
    sph_luffa512_init (&ctx_luffa1);
    sph_luffa512 (&ctx_luffa1, hashB, 64);
    sph_luffa512_close (&ctx_luffa1, hashA);	
	
    sph_cubehash512_init (&ctx_cubehash1); 
    sph_cubehash512 (&ctx_cubehash1, hashA, 64);   
    sph_cubehash512_close(&ctx_cubehash1, hashB);  
	
    sph_shavite512_init (&ctx_shavite1);
    sph_shavite512 (&ctx_shavite1, hashB, 64);   
    sph_shavite512_close(&ctx_shavite1, hashA);  
	
    sph_simd512_init (&ctx_simd1); 
    sph_simd512 (&ctx_simd1, hashA, 64);   
    sph_simd512_close(&ctx_simd1, hashB); 
	
    sph_echo512_init (&ctx_echo1); 
    sph_echo512 (&ctx_echo1, hashB, 64);   
    sph_echo512_close(&ctx_echo1, hashA); 

    sph_hamsi512_init (&ctx_hamsi1); 
    sph_hamsi512 (&ctx_hamsi1, hashA, 64);   
    sph_hamsi512_close(&ctx_hamsi1, hashB); 

    sph_fugue512_init (&ctx_fugue1); 
    sph_fugue512 (&ctx_fugue1, hashB, 64);   
    sph_fugue512_close(&ctx_fugue1, hashA); 

    sph_shabal512_init (&ctx_shabal1); 
    sph_shabal512 (&ctx_shabal1, hashA, 64);   
    sph_shabal512_close(&ctx_shabal1, hashB); 

    sph_whirlpool_init (&ctx_whirlpool1); 
    sph_whirlpool (&ctx_whirlpool1, hashB, 64);   
    sph_whirlpool_close(&ctx_whirlpool1, hashA); 

    sph_sha512_init (&ctx_sha1); 
    sph_sha512 (&ctx_sha1, hashA, 64);   
    sph_sha512_close(&ctx_sha1, hashB); 

    sph_haval256_5_init (&ctx_haval1); 
    sph_haval256_5 (&ctx_haval1, hashB, 64);   
    sph_haval256_5_close(&ctx_haval1, hashA); 


    memcpy(output, hashA, 32);
	
}