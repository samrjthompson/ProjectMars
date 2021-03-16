# Divide and Conquer

Developed with Unreal Engine 4


## Factions

Factions are objects of the FFaction struct. Seeing as a faction object has no physical presence in the world, it doesn't really make
sense to have the faction as an AActor. In addition, it is just a container of data that the player interacts with. Therefore, it seems
to make sense to have factions as USTRUCTS rather than UCLASS.


## Province System

The original plan was to go with the Paradox style provincial/regional system where each region has its own RGB value and this
RGB value is the key for the region. However, I think I prefer the total war style where the player cannot easily see provincial 
boarders. 

I think the best way to implement this would be to break the map up and have each province as a separate mesh/actor in the map.
Therefore, when we click on a province, we return the actor in order to identify it. Will see how this goes.


## Money

Money is earned through tax, trade, tribute, and/or looting.

Tax is earned from your population. Each pop type will give a different level of tax (except slaves who will give no tax).
Tax will also be modified based on event modifiers (e.g., a sacrifice to the Gods will boost productivity), and pop happiness.

Trade/Commerce is earned through imports and exports. Slaves also increase your import and export value.

Tribute is earned through clients/satrapies/war reparations.

Looting is earned through piracy/sacking and looting settlements.


## Population

Population is the literal number of people in your city (i.e., the number of pops his not hidden in some way. If there are 50,000 people
in a city, then the game will tell you that). 

This total population will be split up into different classes. These are the Patricians (Upper/Aristocratic class), the Plebes 
(Middle class), Proletariat (Lower class), Foreigners, and Slaves.

Pops are gained through war, migration, and reproduction rates of your pops. 

In the case of war, obviously slaves are the main pop type you will gain. 

Migration is affected through region attraction which, in turn, is affected by fertility, economic opportunities, and border security.

Reproduction rates, and pop growth from this, is affected by health of the population and the food abundance of the region. Food abundance
will directly affect pop capacity. If food abundance drops below pop capacity, then people will start to starve and overall productivity
and economic output of the region will go down.