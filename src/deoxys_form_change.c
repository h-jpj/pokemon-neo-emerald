#include "global.h"
#include "pokemon.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/form_change_types.h"
#include "event_data.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "menu.h"
#include "malloc.h"
#include "list_menu.h"
#include "task.h"
#include "window.h"
#include "script.h"
#include "constants/vars.h"

// Function to check if Deoxys is in the player's party
// Returns the party position (0-5) if found, PARTY_SIZE if not found
void CheckPartyForDeoxys(void)
{
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (species == SPECIES_DEOXYS ||
            species == SPECIES_DEOXYS_ATTACK ||
            species == SPECIES_DEOXYS_DEFENSE ||
            species == SPECIES_DEOXYS_SPEED)
        {
            gSpecialVar_Result = i;
            return;
        }
    }

    gSpecialVar_Result = PARTY_SIZE;
}

// Function to get the current form of Deoxys
// Sets gSpecialVar_Result to the form ID (0-3)
void GetDeoxysForm(void)
{
    u8 partyIndex = gSpecialVar_0x8004;
    u16 species = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES);

    switch (species)
    {
    case SPECIES_DEOXYS:
        gSpecialVar_Result = 0; // Normal Forme
        break;
    case SPECIES_DEOXYS_ATTACK:
        gSpecialVar_Result = 1; // Attack Forme
        break;
    case SPECIES_DEOXYS_DEFENSE:
        gSpecialVar_Result = 2; // Defense Forme
        break;
    case SPECIES_DEOXYS_SPEED:
        gSpecialVar_Result = 3; // Speed Forme
        break;
    default:
        gSpecialVar_Result = 0;
        break;
    }
}

// Function to change Deoxys's form
// Takes the party index in gSpecialVar_0x8004 and the form ID in gSpecialVar_0x8005
void ChangeDeoxysForm(void)
{
    u8 partyIndex = gSpecialVar_0x8004;
    u8 formId = gSpecialVar_0x8005;
    u16 targetSpecies;
    struct Pokemon *mon = &gPlayerParty[partyIndex];
    u16 currentSpecies = GetMonData(mon, MON_DATA_SPECIES);
    bool8 isDeoxys = (currentSpecies == SPECIES_DEOXYS ||
                      currentSpecies == SPECIES_DEOXYS_ATTACK ||
                      currentSpecies == SPECIES_DEOXYS_DEFENSE ||
                      currentSpecies == SPECIES_DEOXYS_SPEED);

    if (!isDeoxys)
        return;

    switch (formId)
    {
    case 0:
        targetSpecies = SPECIES_DEOXYS; // Normal Forme
        break;
    case 1:
        targetSpecies = SPECIES_DEOXYS_ATTACK; // Attack Forme
        break;
    case 2:
        targetSpecies = SPECIES_DEOXYS_DEFENSE; // Defense Forme
        break;
    case 3:
        targetSpecies = SPECIES_DEOXYS_SPEED; // Speed Forme
        break;
    default:
        targetSpecies = SPECIES_DEOXYS;
        break;
    }

    if (currentSpecies == targetSpecies)
        return; // No change needed

    // Use a simpler approach - just set the species directly
    SetMonData(mon, MON_DATA_SPECIES, &targetSpecies);

    // Calculate stats
    CalculateMonStats(mon);

    // Heal the Pokémon to full HP
    u16 maxHP = GetMonData(mon, MON_DATA_MAX_HP);
    SetMonData(mon, MON_DATA_HP, &maxHP);
}
