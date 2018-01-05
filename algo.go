package powalgo

/*
#include <stdlib.h>
#include "x17.h"
#include "argon2.h"
*/
import "C"
import "unsafe"

func X17hash(input []byte) ([]byte, error) {
	var output = C.malloc(32)
	defer C.free(output)
	in := C.CString(string(input))
	C.crypto_hash(in, (*C.char)(output))
	return C.GoBytes(output, 32), nil
}

func Argon2Hash(input []byte) ([]byte, error) {
	var output = C.malloc(32)
	defer C.free(output)
	C.argon2d_hash_raw(2, 16, 1, unsafe.Pointer(&input[0]), C.size_t(len(input)), unsafe.Pointer(&input[0]), C.size_t(len(input)), output, 32)
	return C.GoBytes(output, 32), nil
}
