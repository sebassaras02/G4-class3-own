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

#ifndef B1DetectorMessenger_h
#define B1DetectorMessenger_h 


#include "G4UImessenger.hh"
#include "globals.hh"
#include "B1DetectorConstruction.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcommand.hh"

class B1DetectorConstruction;

/// Detector construction class to define materials and geometry.

class B1DetectorMessenger : public  G4UImessenger
{
  public:
    B1DetectorMessenger(B1DetectorConstruction* detector_);
    virtual ~B1DetectorMessenger();

    virtual void SetNewValue(G4UIcommand*, G4String);

  private:
    
    G4UIdirectory *fDetectorDir;
    G4UIcmdWith3VectorAndUnit *pos_NaI;
    B1DetectorConstruction *f_det;

    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

