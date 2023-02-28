void plot(const char* file1, const char* file2, const char* file3, const char* file4){

// Graphs and canvas
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 500,500,600,400);
c1->SetLogy();

TMultiGraph *mg = new TMultiGraph("mg","");

TGraphAsymmErrors *g = new TGraphAsymmErrors(file1, "%lg %*s %lg %lg %lg");
TGraphAsymmErrors *gr = new TGraphAsymmErrors(g->GetN(),g->GetX(),g->GetY(),g->GetEXlow(),g->GetEXhigh(),g->GetEYhigh(),g->GetEYlow());
TGraphAsymmErrors *g1 = new TGraphAsymmErrors(file2, "%lg %*s %lg %lg %lg");
TGraphAsymmErrors *gr1 = new TGraphAsymmErrors(g1->GetN(),g1->GetX(),g1->GetY(),g1->GetEXlow(),g1->GetEXhigh(),g1->GetEYhigh(),g1->GetEYlow());
TGraph *grr = new TGraph(file3, "%lg %lg");
TGraph *gr2 = new TGraph(file4, "%lg %lg");

// TGraph *gr1 = new TGraph(file3, "%lg %*s %*s %lg %*s %*s");
// TGraph *gr2 = new TGraph(file4, "%lg %*s %*s %lg %*s %*s");


// Options

gr->SetMarkerColor(1);
gr->SetMarkerStyle(21);
// gr->SetLineWidth(2);
// gr->SetLineColor(1);

grr->SetMarkerColor(kGreen+3);
grr->SetMarkerStyle(20);
grr->SetLineWidth(2);
grr->SetLineColor(kGreen+3);

gr1->SetMarkerColor(kRed);
gr1->SetMarkerStyle(21);

gr2->SetMarkerColor(kAzure+4);
gr2->SetMarkerStyle(22);
gr2->SetMarkerSize(1.5);
gr2->SetLineWidth(2);
gr2->SetLineColor(kAzure+4);

// gr3->SetMarkerColor(kGreen+3);
// gr3->SetMarkerStyle(20); 

mg->Add(gr,"p");
mg->Add(grr);
mg->Add(gr1,"p");
mg->Add(gr2);
// mg->Add(gr3);

// mg->GetXaxis()->SetRangeUser(6,12);
// mg->GetYaxis()->SetRangeUser(1E-9,1E-7);


mg->GetXaxis()->SetTitle("E_{#gamma} (MeV)");
mg->GetYaxis()->SetTitle("#font[12]{f_{1}}(MeV^{-3})");

//Draw

mg->Draw("APL");

auto legend = new TLegend(0.6,0.15,0.85,0.45);
legend->SetBorderSize(0);
legend->AddEntry(gr, "{}^{50}Ti(p,#gamma) Erlandsson et al. (1979)","p");
legend->AddEntry(grr,"Brink-Axel PSF (1979)","lp");
legend->AddEntry(gr1,"{}^{50}Ti(p,#gamma) Nemashkalo et al. (1992)","p");
legend->AddEntry(gr2,"Brink-Axel PSF (1992)","lp");

// legend->AddEntry(gr2,"HFB + Skyrme","lp");
// legend->AddEntry(gr3,"HFB + Gogny","lp");
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
