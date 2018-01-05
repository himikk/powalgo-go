package powalgo

/*
#include <stdlib.h>
#include "x17.h"
*/
import "C"

func X17hash(input []byte) ([]byte, error) {
	var output = C.malloc(32)
	defer C.free(output)
	in := C.CString(string(input))
	C.crypto_hash(in, (*C.char)(output))
	return C.GoBytes(output, 32), nil
}
