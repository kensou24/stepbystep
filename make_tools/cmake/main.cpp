#include <iostream>
#include "TestClass.h"
#include "config/config.h"
#include "Inc/TestClassInSrc.h"
#include "sub/sub1/TestInSub1.h"
#ifdef USE_SUB2
#include "TestInSub2.h"
#endif

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    //use TestClass
    TestClass tc;
    tc.testFunction();

    TestClassInSrc tcis;
    tcis.testFunction();

    TestInSub1 tisb1;
    tisb1.testFunction();

#ifdef USE_SUB2
    TestInSub2 tisb2;
    tisb2.testFunction();
#else
    cout << "not use sub2" << endl;
#endif
    return 0;
}