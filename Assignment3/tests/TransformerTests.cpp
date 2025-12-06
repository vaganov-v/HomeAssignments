/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#include "gtest/gtest.h"
#include "../src/Autobot.h"
#include "../src/Decepticon.h"
#include "../src/Pretender.h"
#include "../src/Alliance.h"

TEST(AutobotTest, ConstructorAndGetters) {
    Alliance a("Autobots");
    Autobot bot("Optimus", 10, 100, 50, 20, "Blaster", &a, true);
    EXPECT_EQ(bot.getName(), "Optimus");
    EXPECT_EQ(bot.getLevel(), 10);
    EXPECT_EQ(bot.getStrength(), 100);
    EXPECT_EQ(bot.getFuel(), 50);
    EXPECT_EQ(bot.getGun().getModel(), "Blaster");
    EXPECT_EQ(bot.getGun().getAmmo(), 20);
    EXPECT_EQ(bot.getAlliance()->getName(), "Autobots");
    EXPECT_TRUE(bot.hasMatrixOfLeadership());
}

TEST(AutobotTest, Setters) {
    Alliance a("Autobots");
    Autobot bot("Test", 5, 50, 30, 10, "Gun", &a, false);
    bot.setLevel(6);
    bot.setStrength(60);
    bot.setFuel(40);
    bot.setMatrixOfLeadership(true);
    EXPECT_EQ(bot.getLevel(), 6);
    EXPECT_EQ(bot.getStrength(), 60);
    EXPECT_EQ(bot.getFuel(), 40);
    EXPECT_TRUE(bot.hasMatrixOfLeadership());
}

TEST(AutobotTest, MethodsReturnTrue) {
    Alliance a("Autobots");
    Autobot bot("Test", 5, 50, 30, 10, "Gun", &a, false);
    EXPECT_TRUE(bot.transform());
    EXPECT_TRUE(bot.specialAbility());
    EXPECT_TRUE(bot.callForBackup());
}

TEST(DecepticonTest, AllFeatures) {
    Alliance a("Decepticons");
    Decepticon d("Megatron", 10, 110, 40, 25, "Cannon", &a, true);
    EXPECT_EQ(d.getName(), "Megatron");
    EXPECT_TRUE(d.hasDarkSpark());
    d.setDarkSpark(false);
    EXPECT_FALSE(d.hasDarkSpark());
    EXPECT_TRUE(d.transform());
    EXPECT_TRUE(d.activateStealth());
}

TEST(PretenderTest, AllFeatures) {
    Alliance a("Neutral");
    Pretender p("Ninja", 8, 80, 30, 15, "Launcher", &a, true);
    EXPECT_EQ(p.getName(), "Ninja");
    EXPECT_TRUE(p.isHumanShell());
    p.setHumanShell(false);
    EXPECT_FALSE(p.isHumanShell());
    EXPECT_TRUE(p.transform());
    EXPECT_TRUE(p.detachShell());
}

TEST(TransformerTest, BaseMethods) {
    Alliance a("Autobots");
    Autobot bot("Test", 5, 50, 30, 10, "Gun", &a, false);
    EXPECT_TRUE(bot.move());
    EXPECT_TRUE(bot.fire());
}
