/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 4
 */

#include "gtest/gtest.h"
#include "../src/Autobot.h"
#include "../src/Decepticon.h"
#include "../src/Pretender.h"
#include "../src/Alliance.h"
#include <sstream>

// tests from Assignment3
TEST(AutobotTest, ConstructorAndGetters)
{
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

TEST(AutobotTest, Setters)
{
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

TEST(AutobotTest, MethodsReturnTrue)
{
    Alliance a("Autobots");
    Autobot bot("Test", 5, 50, 30, 10, "Gun", &a, false);
    EXPECT_TRUE(bot.transform());
    EXPECT_TRUE(bot.specialAbility());
    EXPECT_TRUE(bot.callForBackup());
}

TEST(DecepticonTest, AllFeatures)
{
    Alliance a("Decepticons");
    Decepticon d("Megatron", 10, 110, 40, 25, "Cannon", &a, true);
    EXPECT_EQ(d.getName(), "Megatron");
    EXPECT_TRUE(d.hasDarkSpark());
    d.setDarkSpark(false);
    EXPECT_FALSE(d.hasDarkSpark());
    EXPECT_TRUE(d.transform());
    EXPECT_TRUE(d.activateStealth());
}

TEST(PretenderTest, AllFeatures)
{
    Alliance a("Neutral");
    Pretender p("Ninja", 8, 80, 30, 15, "Launcher", &a, true);
    EXPECT_EQ(p.getName(), "Ninja");
    EXPECT_TRUE(p.isHumanShell());
    p.setHumanShell(false);
    EXPECT_FALSE(p.isHumanShell());
    EXPECT_TRUE(p.transform());
    EXPECT_TRUE(p.detachShell());
}

TEST(TransformerTest, BaseMethods)
{
    Alliance a("Autobots");
    Autobot bot("Test", 5, 50, 30, 10, "Gun", &a, false);
    EXPECT_TRUE(bot.move());
    EXPECT_TRUE(bot.fire());
}

// === Assignment 4: operator<< tests and virtual calls ===

TEST(Assignment4, OperatorOutput)
{
    Alliance a("Autobots");
    Autobot bot("TestBot", 5, 50, 30, 10, "Gun", &a, true);
    std::ostringstream oss;
    oss << bot;
    std::string result = oss.str();
    EXPECT_NE(result.find("TestBot"), std::string::npos);
    EXPECT_NE(result.find("Autobot"), std::string::npos);
}

TEST(Assignment4, VirtualCallsViaBasePointer)
{
    Alliance a("Autobots");
    Transformer* t = new Autobot("T", 1, 10, 10, 5, "G", &a, false);
    std::ostringstream oss;
    std::streambuf* orig = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    t->transform();

    std::cout.rdbuf(orig);
    delete t;
    EXPECT_NE(oss.str().find("Autobot::transform"), std::string::npos);
}

TEST(Assignment4, VectorOf9Objects)
{
    Alliance autobots("Autobots");
    Alliance decepticons("Decepticons");

    std::vector<Transformer*> bots;
    bots.push_back(new Autobot("A1", 3, 60, 30, 10, "G1", &autobots, true));
    bots.push_back(new Autobot("A2", 4, 65, 35, 12, "G2", &autobots, false));
    bots.push_back(new Autobot("A3", 5, 70, 40, 15, "G3", &autobots, true));
    bots.push_back(new Decepticon("D1", 6, 75, 45, 20, "C1", &decepticons, false));
    bots.push_back(new Decepticon("D2", 7, 80, 50, 25, "C2", &decepticons, true));
    bots.push_back(new Decepticon("D3", 8, 85, 55, 30, "C3", &decepticons, false));
    bots.push_back(new Pretender("P1", 2, 50, 25, 5, "S1", &autobots, true));
    bots.push_back(new Pretender("P2", 3, 55, 30, 8, "S2", &autobots, false));
    bots.push_back(new Pretender("P3", 4, 60, 35, 10, "S3", &decepticons, true));

    std::ostringstream oss;
    std::streambuf* orig = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    for (auto* bot : bots)
    {
        bot->transform();
        bot->specialAbility();
    }

    std::cout.rdbuf(orig);

    std::string output = oss.str();
    EXPECT_NE(output.find("Autobot::transform"), std::string::npos);
    EXPECT_NE(output.find("Decepticon::transform"), std::string::npos);
    EXPECT_NE(output.find("Pretender::transform"), std::string::npos);

    for (auto* bot : bots) delete bot;
}
