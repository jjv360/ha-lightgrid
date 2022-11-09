//
// Holder for the light grid

// Vars
Thickness = 4;
Rows = 6;
Cols = 6;//10;
CellSize = 22;
HoleThickness = 1;
HoleOuterSize = 18;
HoleInnerSize = 12;

// Base
difference() {
    
    // Base area
    cube([CellSize * Rows, CellSize * Cols, Thickness]);
    
    // Each hole
    for (x = [0:Rows]) {
        for (y = [0:Cols]) {
        
            // Outer hole, the big one ... leaves a gap for the inner one
            translate([x * CellSize + CellSize/2, y * CellSize + CellSize/2, HoleThickness])
            cylinder(h = 1000, d = HoleOuterSize, center = false, $fn = 32);
            
            // Inner hole, grips the LED
            translate([x * CellSize + CellSize/2, y * CellSize + CellSize/2, HoleThickness])
            cylinder(h = 1000, d = HoleInnerSize, center = true, $fn = 32);
        
        }
    }
    
};