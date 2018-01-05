package powalgo

import (
	"encoding/hex"
	"testing"
)

func TestX17(t *testing.T) {
	// The block header of bitmark 0.9.7 testnet block c8886f4d3b4073068d9487ad70bd21b081c9e1a472ee20b629e5ee2c3809c7dc (height 1239)
	headerHex := "020800007dbecff97f9766070363373737507e94660c375a8f497608131533ef5d7fb7d6502f70145c2b7eb6814bf400e7b1db406ef36c811199c3e2789913ccb348ffde1610025a6d48011ee6667ed2"
	header, _ := hex.DecodeString(headerHex)
	hsh, _ := X17hash(header)
	hshHex := hex.EncodeToString(hsh)
	if "340910a85e8c8a968d254dcd1d5c252fbf434f1d001c53cf5d83ef981a000000" != hshHex {
		t.Log(hshHex)
		t.FailNow()
	}
}
