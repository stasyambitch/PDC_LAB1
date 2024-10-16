#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_1_PDS/main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit1 
{
    TEST_CLASS(unit1)
    {
    public:

        TEST_METHOD(TestImplication)
        {
            Assert::IsFalse(implication(1, 0)); 
            Assert::IsTrue(implication(1, 1));
        }

        TEST_METHOD(TestEquivalence)
        {
            Assert::IsTrue(equivalence(0, 0));
            Assert::IsFalse(equivalence(0, 1));
            Assert::IsFalse(equivalence(1, 0)); 
            Assert::IsTrue(equivalence(1, 1));
        }

        TEST_METHOD(TestBitwiseOperations) {
            std::string a = "11001100"; 
            std::string b = "10101011"; 
            std::string or_result, and_result, xor_result;
            bitwise_operations(a, b, or_result, and_result, xor_result);
            Assert::AreEqual(std::string("11101111"), or_result); 
            Assert::AreEqual(std::string("10001000"), and_result); 
            Assert::AreEqual(std::string("01100111"), xor_result); 
        }

        TEST_METHOD(TestBitwiseOperations_AllOnesAndZeros) {
            std::string a = "11111111"; 
            std::string b = "00000000"; 
            std::string or_result, and_result, xor_result;
            bitwise_operations(a, b, or_result, and_result, xor_result);
            Assert::AreEqual(std::string("11111111"), or_result); 
            Assert::AreEqual(std::string("00000000"), and_result); 
            Assert::AreEqual(std::string("11111111"), xor_result); 
        }

    };
}
