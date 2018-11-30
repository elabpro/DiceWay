/*
 * File:   newtestclass.cpp
 * Author: eugine
 *
 * Created on Nov 2, 2018
 */

#include "newtestclass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(testGameClass);

testGameClass::testGameClass() {
}

testGameClass::~testGameClass() {
}

void testGameClass::setUp() {
}

void testGameClass::tearDown() {
}

void testGameClass::testDice() {
    Dice* d = new Dice();
    CPPUNIT_ASSERT(d->getBottom() == 6);
    int result;
    result = d->roll(0);
    CPPUNIT_ASSERT(result == 6);
    result = d->roll(6);
    CPPUNIT_ASSERT(result == 3);
    result = d->roll(6);
    CPPUNIT_ASSERT(result == 1);
    result = d->roll(6);
    CPPUNIT_ASSERT(result == 4);
    result = d->roll(6);
    CPPUNIT_ASSERT(result == 6);
    result = d->roll(2);
    CPPUNIT_ASSERT(result == 2);
    result = d->roll(8);
    CPPUNIT_ASSERT(result == 6);
    result = d->roll(4);
    CPPUNIT_ASSERT(result == 4);
}

void testGameClass::testField() {
    Field *f = new Field(1);
    Dice* d = new Dice();
    f->startAt(0, 0, *d);
    CPPUNIT_ASSERT(f->findWay(5) == -1);
    f = new Field(2);
    f->startAt(0, 0, *d);
    CPPUNIT_ASSERT(f->findWay(6) == 0);
    f = new Field(3);
    f->startAt(0, 0, *d);
    CPPUNIT_ASSERT(f->findWay(10) == 1);
    f = new Field(4);
    f->startAt(0, 0, *d);
    CPPUNIT_ASSERT(f->findWay(13) == -1);
}

