# PROJECT MARS PLAN

## SPENDING MONEY

Use a bool function to return whether or not a player can purchase something. 

E.g., 

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

If CanPlayerPurchase returns true, then we can buy an item, else whe cannot.