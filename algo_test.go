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

func TestArgon2(t *testing.T) {
	// The block header of bitmark 0.9.7 testnet block 6d79b0b2ac43d8cc9ff4173e2f620dbdbfd026a7095abf61b2145be12890b82e (height 1232)
	headerHex := "02060000261bc74312004005d3c4c600eeaf5e2efdf86ed1a8f1b01e72c2aaec030236b1e54b9eb4057da91a470d9d7d398ea6b7d46d0eef98479812a3607367054ced6b640b025a332c731e666666c1"
	header, _ := hex.DecodeString(headerHex)
	hsh, _ := Argon2Hash(header)
	hshHex := hex.EncodeToString(hsh)
	// 00004186e967f1f34ef97290ff354ad014fbf3188fd8ba220506b755f6be8201 from explorer (rpc byte order)
	if "0182bef655b7060522bad88f18f3fb14d04a35ff9072f94ef3f167e986410000" != hshHex {
		t.Log(hshHex)
		t.FailNow()
	}
}
