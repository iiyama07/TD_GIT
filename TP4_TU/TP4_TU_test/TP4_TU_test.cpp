#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
#include "../TP4_TU.h"
}	

namespace TP4TUtest
{
	TEST_CLASS(TP4TUtest)
	{
	public:
		
		TEST_METHOD(TestEstPair)
		{
			Assert::AreEqual(estPair(7), 0));
		}
	};
}
