#include "ProteinSequence.h"
#include <stdexcept>
#include <algorithm>

ProteinSequence::ProteinSequence() = default;

ProteinSequence::ProteinSequence(
    const std::vector<ProteinogenicAminoAcid> &seq
) : sequence(seq) {
}

ProteinSequence::ProteinSequence(
    const ProteinSequence &other
) : sequence(other.sequence) {
}

void ProteinSequence::synthesizeFromNucleotides(
    const std::string &nucleotides
) {
    if (nucleotides.length() % 3 != 0) {
        throw std::invalid_argument(
            "Nucleotide sequence length must be divisible by 3"
        );
    }
    sequence.clear();
    for (size_t i = 0; i < nucleotides.length(); i += 3) {
        ProteinogenicAminoAcid aa;
        aa.synthesize(nucleotides.substr(i, 3));
        if (aa.getCode() == '*') break; // Stop codon
        sequence.push_back(aa);
    }
}

void ProteinSequence::addAminoAcid(const ProteinogenicAminoAcid &aa) {
    sequence.push_back(aa);
}

size_t ProteinSequence::size() const { return sequence.size(); }

ProteinogenicAminoAcid &ProteinSequence::operator[](size_t index) {
    return sequence[index];
}

const ProteinogenicAminoAcid &ProteinSequence::operator[](size_t index) const {
    return sequence[index];
}

ProteinSequence ProteinSequence::operator+(
    const ProteinSequence &other
) const {
    ProteinSequence result(*this);
    size_t overlap = 0;
    for (size_t i = 1; i <= std::min(size(), other.size()); ++i) {
        bool match = true;
        for (size_t j = 0; j < i; ++j) {
            if (sequence[size() - i + j].getCode() != other[j].getCode()) {
                match = false;
                break;
            }
        }
        if (match) {
            overlap = i;
        }
    }
    for (size_t i = overlap; i < other.size(); ++i) {
        result.addAminoAcid(other[i]);
    }
    return result;
}

std::string ProteinSequence::toString() const {
    std::string result;
    for (const auto &aa: sequence) {
        result += aa.getCode();
    }
    return result;
}

int ProteinSequence::identify() const { return 2; }
