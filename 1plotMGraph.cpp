void plot(const char* file1, const char* file3,const char* file4){

// Graphs and canvas
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 500,500,600,400);
c1->SetLogy();

TMultiGraph *mg = new TMultiGraph("mg","");

TGraph *gr = new TGraph(file1, "%lg %*s %lg %*s %*s %*s");
TGraph *grr = new TGraph(file1, "%lg %*s %*s %lg %*s %*s");
// TGraph *gr1 = new TGraph(file2, "%lg %*s %*s %lg %*s %*s");
TGraph *gr2 = new TGraph(file3, "%lg %*s %*s %lg");
TGraph *gr3 = new TGraph(file4, "%lg %*s %*s %lg");

// Options

gr->SetMarkerColor(1);
gr->SetMarkerStyle(21);
gr->SetLineWidth(2);
gr->SetLineColor(1);

grr->SetMarkerColor(4);
grr->SetMarkerStyle(20);
grr->SetLineColor(4);
grr->SetLineWidth(2);

// gr1->SetMarkerColor(kRed);
// gr1->SetMarkerStyle(20);

gr2->SetMarkerColor(kRed);
gr2->SetMarkerSize(1.5);
gr2->SetMarkerStyle(22);
gr2->SetLineColor(kRed);
gr2->SetLineWidth(2);

gr3->SetMarkerColor(kGreen+3);
gr3->SetMarkerSize(1.5);
gr3->SetMarkerStyle(43); 
gr3->SetLineColor(kGreen+3);
gr3->SetLineWidth(2);

mg->Add(gr);
mg->Add(grr,"l");
// mg->Add(gr1);
mg->Add(gr2,"l");
mg->Add(gr3,"l");

// mg->GetXaxis()->SetRangeUser(0,6);
// mg->GetYaxis()->SetRangeUser(1,300);


mg->GetXaxis()->SetTitle("E_{x} (MeV)");
mg->GetYaxis()->SetTitle("Cumulative NLD (a.u.)");

//Draw

mg->Draw("APL");

auto legend = new TLegend(0.6,0.2,0.85,0.45);
legend->SetBorderSize(0);
legend->AddEntry(gr, "Discrete States","lp");
legend->AddEntry(grr,"CTM + FGM","l");
// legend->AddEntry(gr1,"BSFGM","lp");
legend->AddEntry(gr2,"HFB + Skyrme","l");
legend->AddEntry(gr3,"HFB + Gogny","l");
legend->Draw();

TStyle *st1 = new TStyle("st1","my style");
   
st1->SetLabelFont(132,"xyz");
st1->SetTitleFont(132,"xyz");
st1->SetLegendFont(132);
st1->SetPalette(1,0); // avoid horrible default color scheme 
st1->SetOptStat(0); 
st1->SetOptTitle(0); 
st1->SetOptDate(0); 
st1->SetLabelSize(0.03,"xyz"); // size of axis value font 
st1->SetTitleSize(0.035,"xyz"); // size of axis title font 
st1->SetTitleOffset(1.2,"y");

// default canvas options 
st1->SetCanvasDefW(500); 
st1->SetCanvasDefH(500); 

st1->SetCanvasColor(0);  // canvas... 
st1->SetCanvasBorderMode(0); 
st1->SetCanvasBorderSize(0); 
st1->SetPadBottomMargin(0.1); //margins... 
st1->SetPadTopMargin(0.1); 
st1->SetPadLeftMargin(0.1); 
st1->SetPadRightMargin(0.1); 
st1->SetPadGridX(0); // grids, tickmarks 
st1->SetPadGridY(0); 
st1->SetPadTickX(1); 
st1->SetPadTickY(1); 
st1->SetFrameBorderMode(0); 
st1->SetPaperSize(20,24);
st1->cd(); 

gROOT->SetStyle("st1");
gPad->Modified();
gPad->Update();

}