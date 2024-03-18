#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP2.3/LongLong.h"
#include "../OOP2.3/LongLong.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest23
{
	TEST_CLASS(UnitTest23)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			LongLong a(1234, 5677);
			LongLong b(1111, 2222);
			LongLong expectedProduct(2345, 7899);

			// Act
			LongLong sum = a.add(b);

			// Assert
			Assert::AreEqual(expectedProduct.getHighPart(),sum.getHighPart());
			Assert::AreEqual(expectedProduct.getLowPart(), sum.getLowPart());
		}
	};
}
