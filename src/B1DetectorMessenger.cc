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
/// \file B1DetectorConstruction.hh
/// \brief Definition of the B1DetectorConstruction class


#include "B1DetectorMessenger.hh"

B1DetectorMessenger::B1DetectorMessenger(B1DetectorConstruction* detector_):f_det(detector_){

  // set directory to change NaI
  fDetectorDir = new G4UIdirectory("/NaI/detector/");
  fDetectorDir->SetGuidance("Detector geometry position");

  //Various commands for modifying detector geometry
  pos_NaI = new G4UIcmdWith3VectorAndUnit("/NaI/detector/dimensions",this);
  pos_NaI->SetGuidance("Set the positions of the detector volume.");
  pos_NaI->SetParameterName("scint_x","scint_y","scint_z",false);
  pos_NaI->SetDefaultUnit("cm");
  pos_NaI->AvailableForStates(G4State_PreInit,G4State_Idle);
  pos_NaI->SetToBeBroadcasted(false);
}

B1DetectorMessenger::~B1DetectorMessenger(){
  delete pos_NaI;
}

void B1DetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
  if( command == pos_NaI ){
    f_det->SetPos_NaI(pos_NaI->GetNew3VectorValue(newValue));
  }
}

