/*
 * File:   newtestclass.h
 * Author: eugine
 *
 * Created on Nov 2, 2018
 */

#ifndef NEWTESTCLASS_H
#define NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Dice.h"
#include "../Field.h"

class testGameClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(testGameClass);

    CPPUNIT_TEST(testDice);
    CPPUNIT_TEST(testField);

    CPPUNIT_TEST_SUITE_END();

public:
    testGameClass();
    virtual ~testGameClass();
    void setUp();
    void tearDown();

private:
    void testDice();
    void testField();
};

#endif /* NEWTESTCLASS_H */

