#include "pch.h"
#include "CppUnitTest.h"
#include "../Rougelikedev-Tutorial/Room.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RogueLikeTests
{
	TEST_CLASS(RogueLikeTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Room r{10,10,10,10};
			Room r2{10,10,10,10};
			Assert::AreEqual(r.overlaps(r2),true);
		}
	};
}
