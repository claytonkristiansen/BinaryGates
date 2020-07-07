#include "pch.h"
#include "CppUnitTest.h"
#include "functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryUnitTests
{
	using std::bitset;
	TEST_CLASS(BinaryUnitTests)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			Assert::IsTrue(Add<8>(bitset<8>("01001011"), bitset<8>("10100001")) == bitset<8>("11101100"));
		}
		TEST_METHOD(Test2)
		{
			Assert::IsTrue(Add<8>(bitset<8>("00101011"), bitset<8>("10100110")) == bitset<8>("11010001"));
		}
		TEST_METHOD(Test3)
		{
			Assert::IsTrue(Add<8>(bitset<8>("01001101"), bitset<8>("00001001")) == bitset<8>("01010110"));
		}
		TEST_METHOD(Test4)
		{
			Assert::IsTrue(Add<8>(bitset<8>("11110000"), bitset<8>("00001111")) == bitset<8>("11111111"));
		}
		TEST_METHOD(Test5)
		{
			Assert::IsTrue(Add<8>(bitset<8>("01010101"), bitset<8>("10100010")) == bitset<8>("11110111"));
		}
	};
}
