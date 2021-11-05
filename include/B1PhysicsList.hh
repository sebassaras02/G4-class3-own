/// \file B1DetectorConstruction.hh
/// \brief Definition of the B1DetectorConstruction class

#ifndef B1Physics_h
#define B1Physics_h

#include "globals.hh"
#include "G4VModularPhysicsList.hh"
#include "G4VUserPhysicsList.hh"
#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4PhysicsListHelper.hh"

#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"


#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Geantino.hh"
#include "G4NeutrinoE.hh"
#include "G4AntiNeutrinoE.hh"
#include "G4Proton.hh"
#include "G4Neutron.hh"
#include "G4Positron.hh"


#include "G4GammaConversion.hh"
#include "G4ComptonScattering.hh"
#include "G4RayleighScattering.hh"
#include "G4PhotoElectricEffect.hh"


class B1PhysicsList: public G4VUserPhysicsList{
  public:
    B1PhysicsList();
    ~B1PhysicsList();
    void ConstructParticle();
    void ConstructProcess();
    void SetCuts();
  // additional function to set
  // defined by user
    void ConstructEMProcess();
  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

