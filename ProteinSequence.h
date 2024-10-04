#ifndef PROTEIN_SEQUENCE_H
#define PROTEIN_SEQUENCE_H

#include "ProteinogenicAminoAcid.h"
#include <vector>
#include <string>

class ProteinSequence {
private:
    std::vector<ProteinogenicAminoAcid> sequence;

public:
    ProteinSequence();

    explicit ProteinSequence(const std::vector<ProteinogenicAminoAcid> &seq);

    ProteinSequence(const ProteinSequence &other);

    void synthesizeFromNucleotides(const std::string &nucleotides);

    void addAminoAcid(const ProteinogenicAminoAcid &aa);

    size_t size() const;

    ProteinogenicAminoAcid &operator[](size_t index);

    const ProteinogenicAminoAcid &operator[](size_t index) const;

    ProteinSequence operator+(const ProteinSequence &other) const;

    std::string toString() const;

    int identify() const;
};

#endif
