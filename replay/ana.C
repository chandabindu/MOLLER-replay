#include "TSystem.h"
#include "TList.h"
#include "THaRun.h"
#include "THaEvent.h"
#include "THaAnalyzer.h"
#include "THaApparatus.h"
//#include "FadcScintillator.h"
//#include "MOLLERGenericDetector.h"
//#pragma cling load("libmoller.so");
//#include "MOLLERGEMStand.h"
//#include "MOLLERBigBite.h"
//using namespace HallA;
void ana(int argc, int lastevnt ){

    //gSystem->Load("libmoller.so");

    MOLLERSpectrometer *moller = new MOLLERSpectrometer("moller", "Generic apparatus");
    //SBSBigBite *sbs = new SBSBigBite("sbs", "Generic apparatus");
    //SBSGEMStand *gems = new SBSGEMStand("gems", "Collection of GEMs in stand");
    //FadcScintillator *det = new FadcScintillator("scint", "scint");
    MOLLERGenericDetector *det = new MOLLERGenericDetector("scint", "scint");
    det->SetModeADC(MOLLERModeADC::kWaveform);
    det->SetModeTDC(MOLLERModeTDC::kNone);
    //det->SetStoreEmptyElement(kFALSE);
    det->SetStoreRawHits(1);
    //THaScintillator *det = new THaScintillator("scint", "scint");

    //hrs->AddDetector(gems);
    moller->AddDetector(det);
    

  //
  //  Steering script for Hall A analyzer demo
  //
  
  // Set up the equipment to be analyzed.
  
  // add the two spectrometers with the "standard" configuration
  // (VDC planes, S1, and S2)
  // Collect information about a easily modified random set of channels
  // (see DB_DIR/db_D.dat)
  /*
  THaApparatus* DECDAT = new THaDecData("D","Misc. Decoder Data");
  gHaApps->Add( DECDAT );
  */
  

  // Set up the analyzer - we use the standard one,
  // but this could be an experiment-specific one as well.
  // The Analyzer controls the reading of the data, executes
  // tests/cuts, loops over Apparatus's and PhysicsModules,
  // and executes the output routines.
  THaAnalyzer* analyzer = new THaAnalyzer;
  
  gHaApps->Add(moller);

  // A simple event class to be output to the resulting tree.
  // Creating your own descendant of THaEvent is one way of
  // defining and controlling the output.
  THaEvent* event = new THaEvent;
  
  // Define the run(s) that we want to analyze.
  // We just set up one, but this could be many.
//  THaRun* run = new THaRun( "prod12_4100V_TrigRate25_4.dat" );
  //THaRun* run = new THaRun( "/home/chad/data/test_589.dat" );
  //int argc=0;
  //std::cout<<"enter file name: "<<std::endl;
  //cin>>argc;
  //THaRun* run = new THaRun(Form("/home/chad/data/test_%d.dat",argc));
  THaRun* run = new THaRun(Form("/lustre24/expphy/volatile/halla/moller12gev/chandan/RandomFiles/vtp_%d.evio.0",argc));
  run->SetLastEvent(lastevnt);
  //run->SetLastEvent(10);

  run->SetDataRequired(0);
  run->SetDate(TDatime());

  analyzer->SetVerbosity(0);
  TString odef_filename = "ana.odef";
  analyzer->SetOdefFile( odef_filename );
  
  // Define the analysis parameters
  analyzer->SetEvent( event );
  analyzer->SetOutFile(Form("/lustre24/expphy/volatile/halla/moller12gev/chandan/Rootfiles/test1_%d.root",argc));
  // File to record cuts accounting information
  analyzer->SetSummaryFile("summary_example.log"); // optional
  
  //analyzer->SetCompressionLevel(0); // turn off compression
  analyzer->Process(run);     // start the actual analysis
}
