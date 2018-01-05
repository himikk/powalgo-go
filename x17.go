package service

/*
#include "x17.h"
*/
import "C"

func X17hash(input []byte) ([]byte, error) {
	var output *C.char
	in := C.CString(string(input))
	C.crypto_hash(output, in)
	return []byte(C.GoString(output)), nil
}
