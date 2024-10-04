#include "ProteinogenicAminoAcid.h"
#include <stdexcept>

ProteinogenicAminoAcid::ProteinogenicAminoAcid() : AminoAcid() {
}

ProteinogenicAminoAcid::ProteinogenicAminoAcid(char c) : AminoAcid(c) {
}

ProteinogenicAminoAcid::ProteinogenicAminoAcid(
    const ProteinogenicAminoAcid &other
) : AminoAcid(other) {
}

void ProteinogenicAminoAcid::synthesize(const std::string &nucleotides) {
    if (nucleotides.length() != 3) {
        throw std::invalid_argument("Codon must be 3 nucleotides long");
    }
    auto it = codonTable.find(nucleotides);
    if (it != codonTable.end()) {
        setCode(it->second);
    } else {
        throw std::invalid_argument("Invalid codon");
    }
}

int ProteinogenicAminoAcid::identify() const { return 1; }

const std::unordered_map<std::string, char> ProteinogenicAminoAcid::codonTable = {
    {"UUU", 'F'}, {"UUC", 'F'}, {"UUA", 'L'}, {"UUG", 'L'},
    {"CUU", 'L'}, {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'},
    {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'}, {"AUG", 'M'},
    {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'},
    {"UCU", 'S'}, {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'},
    {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'},
    {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
    {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'},
    {"UAU", 'Y'}, {"UAC", 'Y'}, {"UAA", '*'}, {"UAG", '*'},
    {"CAU", 'H'}, {"CAC", 'H'}, {"CAA", 'Q'}, {"CAG", 'Q'},
    {"AAU", 'N'}, {"AAC", 'N'}, {"AAA", 'K'}, {"AAG", 'K'},
    {"GAU", 'D'}, {"GAC", 'D'}, {"GAA", 'E'}, {"GAG", 'E'},
    {"UGU", 'C'}, {"UGC", 'C'}, {"UGA", '*'}, {"UGG", 'W'},
    {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'},
    {"AGU", 'S'}, {"AGC", 'S'}, {"AGA", 'R'}, {"AGG", 'R'},
    {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'}
};
