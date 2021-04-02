# PROJECT MARS PLAN


## MONEY
### SPENDING MONEY

Use a bool function to return whether or not a player can purchase something. 

E.g., 
```C++
bool CanPlayerPurchase(float PlayerTreasury, float ItemCost)
{
    if((PlayerTreasury - ItemCost) >= 0.f)
    {
        return true;
    }
    else
    {
        return false;
    }
}
```

If CanPlayerPurchase returns true, then we can buy an item, else whe cannot.


## CHARACTERS 

### TRAITS

Character traits should be acquired in 3 different ways: 1) Genetic inheritance; 
2) Environmental factors/decisions; 3) Random events.

The first is obvious, if a parent has a trait that relates to geneology, this 
has a chance of being passed on. E.g., If the father has the Genius trait, then
there is a x% chance of that being passed on to the child. If both the mother
and father have a genetic trait, then there is an even greater liklihood of 
inheriteace. Traits such as those that relate to earned traits (E.g., Inspiring
Commander) cannot be inherited genetically.

The second trait type involves traits earned through decisions made by the 
character and events happening to that character. E.g., Inspiring Commander
could be earned after making a relevant decision in a battle. Traits such
as these can either be taught to others, or made more likely to be adopted
by another character if character X has a trait and character Y is a student
of character X. E.g., Inspiring Commander cannot be taught by X to Y, however,
if Y is an under-study of X then there is a higher liklihood of Y acquiring 
the Inspiring Commander trait due to exposure to someone with that trait.

Finally, there are random events. This overalap with environmental and 
genetic traits, however, they also can be out of the player's control. 
E.g., A random event could occur during a battle which leads to the character
acquiring the Brave trait. However, a character could also have a percentage
chance of developing Cancer randomly throughout their life. In addition, 
certain traits can lead to a higher liklihood of other traits being acquired.
E.g., If a character has the Alcoholic trait, there is a higher liklihood of
this character acquiring the Ill trait.

Traits can be stored as enums to begin with:
```C++
enum class ECharacterTraits
{
    Genius = 0,
    QuickThinking,
    WellRead,
    Charismatic,
    Slow,
    Rude,
    Max
}
```

We could organise these enums so that they house trait types for organisiation purposes:
```C++
enum class EIntelligenceTraits
{

}
enum class EHealthTraits
{

}
enum class EMilitaryTraits
{

}
```