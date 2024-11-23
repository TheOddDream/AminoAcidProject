#ifndef PROTEINOGENIC_AMINO_ACID_H
#define PROTEINOGENIC_AMINO_ACID_H

#include "AminoAcid.h"
#include <string>
#include <unordered_map>

class ProteinogenicAminoAcid : public AminoAcid {
private:
    static const std::unordered_map<std::string, char> codonTable;

public:
    ProteinogenicAminoAcid();

    explicit ProteinogenicAminoAcid(char c);

    ProteinogenicAminoAcid(const ProteinogenicAminoAcid &other);

    void synthesize(const std::string &nucleotides);

    int identify() const override;
};

#endif
