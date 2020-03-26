/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Shahar Engel, Odeya Molodic
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK((find(text, "happi")).compare("Happi"));
    CHECK((find(text, "Happi")).compare("Happi"));
    CHECK((find(text, "HAPPI")).compare("Happi"));
    CHECK((find(text, "HaPpI")).compare("Happi"));
}

TEST_CASE("Test replacement of v and w") {
    string text = "xxx worry yyy";
    string text2 = "xxx very yyy";
    CHECK((find(text, "vorry")).compare("worry"));
    CHECK((find(text, "worry")).compare("worry"));
    CHECK((find(text2, "wery")).compare("very"));
}

TEST_CASE("Test replacement of p and f") {
    string text = "xxx happy yyy";
    CHECK((find(text, "habfy")).compare("happy"));
    CHECK((find(text, "hafby")).compare("happy"));
    CHECK((find(text, "haffy")).compare("happy"));
    CHECK((find(text, "hapfy")).compare("happy"));
    CHECK((find(text, "hafpy")).compare("happy"));
}

TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    string text2 = "xxx be yyy";
    CHECK((find(text, "happy")).compare("happy"));
    CHECK((find(text, "habby")).compare("happy"));
    CHECK((find(text, "hapby")).compare("happy"));
    CHECK((find(text, "habpy")).compare("happy"));
    CHECK((find(text2, "pe")).compare("be"));
    CHECK((find(text2, "Pe")).compare("be"));
}

TEST_CASE("Test replacement of b and f") {
    string text = "xxx be yyy";
    string text2 = "xxx fly yyy";
    CHECK((find(text, "fe")).compare("be"));
    CHECK((find(text, "Fe")).compare("be"));
    CHECK((find(text2, "bly")).compare("fly"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "xxx gool yyy";
    string text2 = "xxx just yyy";
    CHECK((find(text, "jool")).compare("gool"));
    CHECK((find(text, "gool")).compare("gool"));
    CHECK((find(text2, "Gust")).compare("just"));
}

TEST_CASE("Test replacement of c and k") {
    string text = "xxx cheese yyy";
    string text2 = "xxx kill yyy";
    CHECK((find(text, "kheese")).compare("cheese"));
    CHECK((find(text, "Kheese")).compare("cheese"));
    CHECK((find(text2, "cill")).compare("kill"));
    CHECK((find(text2, "Cill")).compare("kill"));
}

TEST_CASE("Test replacement of k and q") {
    string text = "xxx kill yyy";
    string text2 = "xxx question yyy";
    CHECK((find(text, "qill")).compare("kill"));
    CHECK((find(text2, "kuestion")).compare("question"));
}

TEST_CASE("Test replacement of c and q") {
    string text = "xxx cheese yyy";
    string text2 = "xxx question yyy";
    CHECK((find(text, "qheese")).compare("cheese"));
    CHECK((find(text2, "cuestion")).compare("question"));
}

TEST_CASE("Test replacement of s and z") {
    string text = "xxx sort yyy";
    string text2 = "xxx zebra yyy";
    CHECK((find(text, "zort")).compare("sort"));
    CHECK((find(text2, "sebra")).compare("zebra"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "xxx dont yyy";
    CHECK((find(text, "dond")).compare("dont"));
    CHECK((find(text, "tont")).compare("dont"));
    CHECK((find(text, "tond")).compare("dont"));
    CHECK((find(text, "Tont")).compare("dont"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "xxx pool yyy";
    CHECK((find(text, "puol")).compare("pool"));
    CHECK((find(text, "poul")).compare("pool"));
    CHECK((find(text, "puul")).compare("pool"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "xxx happy yyy";
    string text2 = "xxx like yyy";
    CHECK((find(text, "happi")).compare("happy"));
    CHECK((find(text2, "lyke")).compare("like"));
}

// dont worry be happy

TEST_CASE("Test replacement in the word dont") {
    string text = "xxx dont yyy";
    CHECK((find(text, "tUnt")).compare("dont"));
    CHECK((find(text, "tunD")).compare("dont"));
    CHECK((find(text, "dund")).compare("dont"));
    CHECK((find(text, "dunt")).compare("dont"));
    CHECK((find(text, "DUnT")).compare("dont"));
    CHECK((find(text, "DUND")).compare("dont"));
}

TEST_CASE("Test replacement in the word worry") {
    string text = "xxx worry yyy";
    CHECK((find(text, "vurri")).compare("worry"));
    CHECK((find(text, "Vorri")).compare("worry"));
    CHECK((find(text, "wurry")).compare("worry"));
    CHECK((find(text, "wurri")).compare("worry"));
    CHECK((find(text, "Vurry")).compare("worry"));
    CHECK((find(text, "VUrRi")).compare("worry"));
}

TEST_CASE("Test replacement in the word happy") {
    string text = "xxx happy yyy";
    CHECK((find(text, "HabFI")).compare("happy"));
    CHECK((find(text, "hAbbi")).compare("happy"));
    CHECK((find(text, "haFpi")).compare("happy"));
    CHECK((find(text, "HAFBI")).compare("happy"));
    CHECK((find(text, "haFpy")).compare("happy"));
}

// I just cook all the day

TEST_CASE("Test replacement in the word just") {
    string text = "xxx just yyy";
    CHECK((find(text, "gust")).compare("just"));
    CHECK((find(text, "jost")).compare("just"));
    CHECK((find(text, "juzt")).compare("just"));
    CHECK((find(text, "jusd")).compare("just"));
    CHECK((find(text, "Gost")).compare("just"));
    CHECK((find(text, "joZt")).compare("just"));
    CHECK((find(text, "juzD")).compare("just"));
    CHECK((find(text, "Guzt")).compare("just"));
    CHECK((find(text, "GusD")).compare("just"));
    CHECK((find(text, "jozt")).compare("just"));
    CHECK((find(text, "josD")).compare("just"));
    CHECK((find(text, "juzd")).compare("just"));
    CHECK((find(text, "gOzt")).compare("just"));
    CHECK((find(text, "jOZD")).compare("just"));
    CHECK((find(text, "guZD")).compare("just"));
    CHECK((find(text, "gosD")).compare("just"));
    CHECK((find(text, "gozd")).compare("just"));
}

TEST_CASE("Test replacement in the word cook") {
    string text = "xxx cook yyy";
    CHECK((find(text, "kook")).compare("cook"));
    CHECK((find(text, "cuok")).compare("cook"));
    CHECK((find(text, "couk")).compare("cook"));
    CHECK((find(text, "cooc")).compare("cook"));
    CHECK((find(text, "kuok")).compare("cook"));
    CHECK((find(text, "cUUk")).compare("cook"));
    CHECK((find(text, "coUc")).compare("cook"));
    CHECK((find(text, "Kooc")).compare("cook"));
    CHECK((find(text, "Kouk")).compare("cook"));
    CHECK((find(text, "cuoC")).compare("cook"));
    CHECK((find(text, "KUUk")).compare("cook"));
    CHECK((find(text, "cUUC")).compare("cook"));
    CHECK((find(text, "kUoC")).compare("cook"));
    CHECK((find(text, "KoUC")).compare("cook"));
    CHECK((find(text, "kuuC")).compare("cook"));
    CHECK((find(text, "cook")).compare("cook"));
}

TEST_CASE("Test replacement in the word the") {
    string text = "xxx the yyy";
    CHECK((find(text, "dhe")).compare("the"));
    CHECK((find(text, "DHe")).compare("the"));
}

TEST_CASE("Test replacement in the word day") {
    string text = "xxx day yyy";
    CHECK((find(text, "tay")).compare("day"));
    CHECK((find(text, "tai")).compare("day"));
    CHECK((find(text, "daI")).compare("day"));
}

TEST_CASE("Test replacement in the word I") {
    string text = "xxx I yyy";
    CHECK((find(text, "y")).compare("I"));
    CHECK((find(text, "Y")).compare("I"));
}