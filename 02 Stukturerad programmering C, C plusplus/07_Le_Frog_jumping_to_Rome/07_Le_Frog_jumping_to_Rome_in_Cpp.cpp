//
//  07_Le_Frog_jumping_to_Rome_in_Cpp.cpp
//  07_Le_Frog_jumping_to_Rome_in_Cpp
//
//  Created by Daniel Eftodi on 2021-10-05.
//

#include "07_Le_Frog_jumping_to_Rome_in_Cpp.h"

//const bool bAlwaysTrue = true;
//const bool bAlwaysFalse = false;

void Le_Frog_jumping_to_Rome (int iNumRequireSteps) {
    /*
    Uppgift:    En groda kan hoppa 1 steg eller 2 steg åt gången.
     
                Man vill veta på hur många olika sätt som grodan
                kan hoppa fram för att nå 50 steg bort.

    Assignment: A frog can either jump 1 or 2 steps at a time.
     
                How many different ways can the frog jump, in 50 steps?
                
                Think: What are all of the possible "Roads to Rome" the
                       frog can jump in 50 steps.
     */
    
    // Variables

/* PSEUDO CODE
    
    COUNTER FOR 1-STEPS PER ROW
 
    COUNTER FOR 2-STEPS PER ROW
 
    COUNTER FOR HOW MANY STEPS LEFT PER ROW
    
    
*/
//    int MAX_FROG_STEPS = iNumRequireSteps;
    int iNumStepsTakenPerRow = 0;
    int iNumStepsLeftOnRow   = iNumRequireSteps;
    int iNumOfPermutations   = 0;
    
    // clear screen
    system("clear");
    
    printf("Lets figure out all of the possbile permutations a frog can jump 1 or 2 steps at a time, in %d steps.\n", iNumRequireSteps);
    
    // WE NEED TO MAKE A NESTED FOR LOOP TO LOOP THROUGH ALL PERMUTATIONS
//    for (int row=0; CONDITION WHEN MATH IS DONE ; INCREMENT_Y++){                   // Rows
    
    for (int col=0; ((iNumStepsLeftOnRow >= 0) && (col <= iNumRequireSteps)); col++) {             // Colums
        
        switch (iNumStepsLeftOnRow) {
            default:
                // Decrease 2-steps per col
                --iNumStepsLeftOnRow;
                --iNumStepsLeftOnRow;
                // Inrease 2-steps taken per col
                iNumStepsTakenPerRow++;
                iNumStepsTakenPerRow++;
                printf("\nDBG_LOG :: col: %d :: Taken [%d] Steps :: %d-steps left on row. Rest: %d", col, iNumStepsTakenPerRow, iNumStepsLeftOnRow, iNumStepsLeftOnRow );
                break;
            case 2:
                // Decrease 2-steps per col
                --iNumStepsLeftOnRow;
                --iNumStepsLeftOnRow;
                printf("\nDBG_LOG :: col: %d :: Last Two [%d] Steps left, lets take it in 2-step. Rest: %d", col, iNumStepsLeftOnRow, iNumStepsLeftOnRow );
                // Take 2-steps first per col
                iNumStepsTakenPerRow++;
                iNumStepsTakenPerRow++;
                break;
            case 1:
                // Increase 1-step taken per col
                iNumStepsTakenPerRow++;
                // Decrease 1-steps per col
                --iNumStepsLeftOnRow;
                printf("\nDBG_LOG :: col: %d :: Last [%d] Step left, lets take it in 1-step. Rest: %d", col, iNumStepsLeftOnRow, iNumStepsLeftOnRow );
                break;
            case 0:
                printf("\nDBG_LOG :: col: %d :: Zero [%d] Steps left, No Step left to take: Rest: %d", col, iNumStepsLeftOnRow, iNumStepsLeftOnRow );
                break;
            }
        
        // Calculate how many Steps there are for the frog to take, in 1-steps increment
        iNumStepsLeftOnRow = (iNumRequireSteps - (iNumStepsTakenPerRow));
    }
    
//    iNumOfPermutations = row;
    
    printf("\nDBG_LOC :: iNumOfPermutations: %d", iNumOfPermutations);
}

int main(int argc, char ** argv){
    
    // Let the frog loose
    Le_Frog_jumping_to_Rome(1);

    //Endnig with an extra new line
    printf("\n\n");
    
    return 0;
}
