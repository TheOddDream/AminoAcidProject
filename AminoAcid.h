#ifndef AMINO_ACID_H
#define AMINO_ACID_H

class AminoAcid {
protected:
    char code;

public:
    AminoAcid();

    explicit AminoAcid(char c);

    AminoAcid(const AminoAcid &other);

    char getCode() const;

    void setCode(char c);

    virtual int identify() const;

    virtual ~AminoAcid() = default;
};

#endif // AMINO_ACID_H
