/*
We have to develop a coffee machine with TDD. The machine uses the automated source of ingredients, which implements the interface ISourceOfIngredients.

Our machine should be able to produce the coffee accordingly to the next receipts:
- americano: water & coffee 1:2 or 1:3. Water temp 60C
- cappuccino - milk & coffee & milk foam 1:3, 1:3, 1:3. Water temp 80C
- latte - milk & coffee & milk foam 1:4, 1:2, 1:4. Water temp 90C
- marochino - chocolate & coffee & milk foam, 1:4, 1:4, 1:4 and 1:4 is empty

We have 2 possible sizes of the cup:
- little 100 gram
- big 140 gram

Implement worked coffee machine using ISourceOfIngredients to controll the process of coffee production.
*/

/*
 * Tests:
 * Make americano
 * Make cappuccino
 * Make latte
 * Make marochino
*/

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class ISourceOfIngredients
{
public:
    ~ISourceOfIngredients() {}
    virtual void SetCupSize(int gram) = 0;
    virtual void AddWater(int gram, int temperature) = 0;
    virtual void AddSugar(int gram) = 0;
    virtual void AddCoffee(int gram) = 0;
    virtual void AddMilk(int gram) = 0;
    virtual void AddMilkFoam(int gram) = 0;
    virtual void AddChocolate(int gram) = 0;
    virtual void AddCream(int gram) = 0;
};

class MockSource: public ISourceOfIngredients
{
public:
    MOCK_METHOD1(SetCupSize, void(int));
    MOCK_METHOD2(AddWater, void(int, int));
    MOCK_METHOD1(AddSugar, void(int));
    MOCK_METHOD1(AddCoffee, void(int));
    MOCK_METHOD1(AddMilk, void(int));
    MOCK_METHOD1(AddMilkFoam, void(int));
    MOCK_METHOD1(AddChocolate, void(int));
    MOCK_METHOD1(AddCream, void(int));
};

class CoffeeMachine
{
public:
    CoffeeMachine(ISourceOfIngredients& source)
        : m_source(source)
    { }

    void CreateCappucino(int cupSize)
    {
        m_source.SetCupSize(cupSize);
        m_source.AddWater(cupSize - (cupSize / 3), 60);
        m_source.AddCoffee(cupSize / 3);
    }

private:
    ISourceOfIngredients& m_source;
};

TEST(CoffeeMachine, CreateMachine)
{
    MockSource source;
    CoffeeMachine machine(source);
}

TEST(CoffeeMachine, MakeAmericano)
{
    MockSource source;
    CoffeeMachine machine(source);

    EXPECT_CALL(source, SetCupSize(100)).Times(1);
    EXPECT_CALL(source, AddCoffee(100/3)).Times(1);
    EXPECT_CALL(source, AddWater(100 - 100/3, 60)).Times(1);

    machine.CreateCappucino(100);
}

