//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B1DetectorConstruction.cc
/// \brief Implementation of the B1DetectorConstruction class

#include "B1DetectorConstruction.hh"
#include "G4VisAttributes.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::B1DetectorConstruction()
{ 
  DefineMaterials();
  DefaultValues();
  
  fDetectorMessenger = new B1DetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::~B1DetectorConstruction()
{ }

void B1DetectorConstruction::DefineMaterials(){
  G4NistManager* nist = G4NistManager::Instance();
  nist->SetVerbose(1);
  world_mat = nist->FindOrBuildMaterial("G4_AIR");
  NaI = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
}

void B1DetectorConstruction::SetPos_NaI(G4ThreeVector dims) {
  posNaI_x=dims[0];
  posNaI_y=dims[1];
  posNaI_z=dims[2];
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void B1DetectorConstruction::DefaultValues(){
  posNaI_x=0*cm;
  posNaI_y=0*cm;
  posNaI_z=0*cm;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B1DetectorConstruction::Construct()
{  
   // Se llama a la clase que define materiales preestablecidos en el nucleo
  
  // G4UnitDefinition::BuildUnitsTable();

  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  // define the world 
  // define the size
  G4double long_x1= 50*cm;
  G4double long_y1= 50*cm;
  G4double long_z1= 50*cm;
  
   
  solidWorld =    
    new G4Box("World",                       //its name
       long_x1, long_y1, long_z1);           //its size
      
  logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                     
   
  
  G4ThreeVector pos4 = G4ThreeVector(posNaI_x, posNaI_y, posNaI_z);

  trackerTub4= new G4Tubs("cristalNaI",0.0*cm,3.809*cm,3.809*cm,0.*deg,360.*deg);
                      
  logicShape4 =                         
    new G4LogicalVolume(trackerTub4,         //its solid
                        NaI,                 //its material
                        "DiscoNaI");         //its name
               
  nai_phys= new G4PVPlacement(0,                       //no rotation
                    pos4,                    //at position
                    logicShape4,             //its logical volume
                    "DiscoNaI",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  fScoringVolume=logicShape4;

  auto dt4_VisAtt= new G4VisAttributes(G4Colour(1.0,0.0,1.0,0.3));
  dt4_VisAtt->SetVisibility(true);
  logicWorld->SetVisAttributes(dt4_VisAtt);


  return physWorld;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
