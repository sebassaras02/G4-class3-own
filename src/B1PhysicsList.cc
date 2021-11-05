/// \file B1DetectorConstruction.hh
/// \brief Definition of the B1DetectorConstruction class

#include "B1PhysicsList.hh"

B1PhysicsList::B1PhysicsList(){
}


B1PhysicsList::~B1PhysicsList(){
}

void B1PhysicsList::ConstructProcess(){
  
  AddTransportation();
  ConstructEMProcess();
}

void B1PhysicsList::ConstructParticle(){
  // there are two ways to define particles
  // one way
  G4Gamma::Definition();

  G4Geantino::GeantinoDefinition();

  // leptons
  G4Electron::ElectronDefinition();
  G4Positron::PositronDefinition();
  /*
  G4NeutrinoE::NeutrinoEDefinition();
  G4AntiNeutrinoE::AntiNeutrinoEDefinition();
  
  // baryons
  G4Proton::ProtonDefinition();
  G4Neutron::NeutronDefinition();
  */

  // second way
  // G4Gamma gamma_p;
  // gamma_p.ConstructParticle();
}

void B1PhysicsList::ConstructEMProcess(){
  G4PhysicsListHelper* ph= G4PhysicsListHelper::GetPhysicsListHelper();
  auto particle_iterator = GetParticleIterator();
  particle_iterator->reset();
  while ((*particle_iterator)()){
    // to know what particle is
    G4ParticleDefinition* particle = particle_iterator->value();
    // assing a process to each kind of particle
      if (particle == G4Gamma::Definition()){
        ph->RegisterProcess(new G4GammaConversion(), particle);
        ph->RegisterProcess(new G4ComptonScattering(), particle);
        ph->RegisterProcess(new G4RayleighScattering(), particle);
        ph->RegisterProcess(new G4PhotoElectricEffect(), particle);
      }
  }
}

void B1PhysicsList::SetCuts(){
  G4VUserPhysicsList::SetCuts();
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


