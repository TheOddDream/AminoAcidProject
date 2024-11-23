#include "ProteinSequence.h"
#include <stdexcept>
#include <algorithm>

ProteinSequence::ProteinSequence() = default;

ProteinSequence::ProteinSequence(
    const std::vector<ProteinogenicAminoAcid*>& seq
) {
    for (auto ptr : seq) {
        sequence.push_back(new ProteinogenicAminoAcid(*ptr));
    }
}

ProteinSequence::ProteinSequence(
    const ProteinSequence& other
) {
    for (auto ptr : other.sequence) {
        sequence.push_back(new ProteinogenicAminoAcid(*ptr));
    }
}

ProteinSequence::~ProteinSequence() {
    for (auto ptr : sequence) {
        delete ptr;
    }
    sequence.clear();
}

void ProteinSequence::synthesizeFromNucleotides(
    const std::string& nucleotides
) {
    if (nucleotides.length() % 3 != 0) {
        throw std::invalid_argument(
            "Nucleotide sequence length must be divisible by 3"
        );
    }

    // Clear existing sequence
    for (auto ptr : sequence) {
        delete ptr;
    }
    sequence.clear();

    for (size_t i = 0; i < nucleotides.length(); i += 3) {
        auto* aa = new ProteinogenicAminoAcid();
        aa->synthesize(nucleotides.substr(i, 3));
        if (aa->getCode() == '*') {
            delete aa;
            break; // Stop codon
        }
        sequence.push_back(aa);
    }
}

void ProteinSequence::addAminoAcid(const ProteinogenicAminoAcid& aa) {
    sequence.push_back(new ProteinogenicAminoAcid(aa));
}

size_t ProteinSequence::size() const {
    return sequence.size();
}

ProteinogenicAminoAcid& ProteinSequence::operator[](size_t index) {
    return *sequence[index];
}

const ProteinogenicAminoAcid& ProteinSequence::operator[](size_t index) const {
    return *sequence[index];
}

ProteinSequence ProteinSequence::operator+(
    const ProteinSequence& other
) const {
    ProteinSequence result(*this);
    size_t overlap = 0;

    for (size_t i = 1; i <= std::min(size(), other.size()); ++i) {
        bool match = true;
        for (size_t j = 0; j < i; ++j) {
            if (sequence[size() - i + j]->getCode() != other[j].getCode()) {
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
    for (const auto& ptr : sequence) {
        result += ptr->getCode();
    }
    return result;
}

int ProteinSequence::identify() const {
    return 2;
}
