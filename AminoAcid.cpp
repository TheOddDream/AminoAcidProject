#include "AminoAcid.h"

AminoAcid::AminoAcid() : code('-') {
}

AminoAcid::AminoAcid(char c) : code(c) {
}

AminoAcid::AminoAcid(const AminoAcid &other) : code(other.code) {
}

char AminoAcid::getCode() const { return code; }
void AminoAcid::setCode(char c) { code = c; }

int AminoAcid::identify() const { return 0; }
