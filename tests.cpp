#include <gtest/gtest.h>
#include "AminoAcid.h"
#include "ProteinogenicAminoAcid.h"
#include "ProteinSequence.h"

// Test AminoAcid class
TEST(AminoAcidTest, DefaultConstructor) {
    AminoAcid aa;
    EXPECT_EQ(aa.getCode(), '-');
}

TEST(AminoAcidTest, InitializationConstructor) {
    AminoAcid aa('A');
    EXPECT_EQ(aa.getCode(), 'A');
}

TEST(AminoAcidTest, CopyConstructor) {
    AminoAcid aa1('B');
    AminoAcid aa2(aa1);
    EXPECT_EQ(aa2.getCode(), 'B');
}

TEST(AminoAcidTest, AccessMethods) {
    AminoAcid aa;
    aa.setCode('C');
    EXPECT_EQ(aa.getCode(), 'C');
}

TEST(AminoAcidTest, Identify) {
    AminoAcid aa;
    EXPECT_EQ(aa.identify(), 0);
}

// Test ProteinogenicAminoAcid class
TEST(ProteinogenicAminoAcidTest, DefaultConstructor) {
    ProteinogenicAminoAcid paa;
    EXPECT_EQ(paa.getCode(), '-');
}

TEST(ProteinogenicAminoAcidTest, InitializationConstructor) {
    ProteinogenicAminoAcid paa('D');
    EXPECT_EQ(paa.getCode(), 'D');
}

TEST(ProteinogenicAminoAcidTest, CopyConstructor) {
    ProteinogenicAminoAcid paa1('E');
    ProteinogenicAminoAcid paa2(paa1);
    EXPECT_EQ(paa2.getCode(), 'E');
}

TEST(ProteinogenicAminoAcidTest, Synthesize) {
    ProteinogenicAminoAcid paa;
    paa.synthesize("UUU");
    EXPECT_EQ(paa.getCode(), 'F');

    EXPECT_THROW(paa.synthesize("INVALID"), std::invalid_argument);
    EXPECT_THROW(paa.synthesize("AA"), std::invalid_argument);
}

TEST(ProteinogenicAminoAcidTest, Identify) {
    ProteinogenicAminoAcid paa;
    EXPECT_EQ(paa.identify(), 1);
}

// Test ProteinSequence class
TEST(ProteinSequenceTest, DefaultConstructor) {
    ProteinSequence ps;
    EXPECT_EQ(ps.size(), 0);
}

TEST(ProteinSequenceTest, InitializationConstructor) {
    std::vector<ProteinogenicAminoAcid> vec{
        ProteinogenicAminoAcid('A'), ProteinogenicAminoAcid('B')
    };
    ProteinSequence ps(vec);
    EXPECT_EQ(ps.size(), 2);
    EXPECT_EQ(ps[0].getCode(), 'A');
    EXPECT_EQ(ps[1].getCode(), 'B');
}

TEST(ProteinSequenceTest, CopyConstructor) {
    ProteinSequence ps1;
    ps1.synthesizeFromNucleotides("AUGUUU");
    ProteinSequence ps2(ps1);
    EXPECT_EQ(ps2.toString(), "MF");
}

TEST(ProteinSequenceTest, SynthesizeFromNucleotides) {
    ProteinSequence ps;
    ps.synthesizeFromNucleotides("AUGCUUUAA");
    EXPECT_EQ(ps.toString(), "ML");

    EXPECT_THROW(
        ps.synthesizeFromNucleotides("INVALID"),
        std::invalid_argument
    );
}

TEST(ProteinSequenceTest, AddAminoAcid) {
    ProteinSequence ps;
    ps.addAminoAcid(ProteinogenicAminoAcid('G'));
    ps.addAminoAcid(ProteinogenicAminoAcid('H'));
    EXPECT_EQ(ps.toString(), "GH");
}

TEST(ProteinSequenceTest, OperatorPlus) {
    ProteinSequence ps1, ps2;
    ps1.synthesizeFromNucleotides("AUGGCC");
    ps2.synthesizeFromNucleotides("GCCUUC");
    ProteinSequence combined = ps1 + ps2;
    EXPECT_EQ(combined.toString(), "MAF");
}

TEST(ProteinSequenceTest, Identify) {
    ProteinSequence ps;
    EXPECT_EQ(ps.identify(), 2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
