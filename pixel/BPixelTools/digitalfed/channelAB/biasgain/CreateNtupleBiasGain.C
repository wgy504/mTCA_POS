{ // ROOT scripts always need set of {} to do all the script
	
	string fileName = "./biasgainChannel_AB_25-08-2016_17:09:08";
	
	
	//first create a ROOT file. It automatically becomes the directory to save in.
	string rootFileName = fileName + ".root";
	TFile f(rootFileName.c_str(), "RECREATE");
	
	f.cd();
	
	
	//create a ROOT tree, automatically filled from the ascii file.
	TTree * t = new TTree();
	t.SetName("my_tree");
	t.SetTitle("my_tree");
	string branchDescriptor = "gain/I:bias/I:channel/C:freq/F:correctEvents/F:errorRate/F:errorUncert/F:badEvents/F:errorCount/F:missingHeaders/F:missingTrailers/F:flippedHT/F:eventNrErrors/F:tbmMissedTriggers/F:unknownErrors/F:eventNrResets/F";
	string dataFileName = fileName + ".txt";
	t.ReadFile(dataFileName.c_str(), branchDescriptor.c_str());
	
	//check what is in the tree...
	t.Print();
	
	
	//write the tree to the file, write the file, and close it
	t.Write();
	f.Write();
	f.Close();
} // end of {} for ROOT
