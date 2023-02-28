void plot(const char* file1, const char* file2, const char* file3, const char* file5, const char* file6, const char* file7){

// Graphs and canvas
TCanvas *c1 = new TCanvas ("c1","Graph Draw Options", 500,500,600,400);
c1->SetLogy();

TMultiGraph *mg = new TMultiGraph("mg","");

TGraphAsymmErrors *g1 = new TGraphAsymmErrors(file1, "%lg %*s %lg %lg %lg");
TGraphAsymmErrors *gr1 = new TGraphAsymmErrors(g1->GetN(),g1->GetX(),g1->GetY(),g1->GetEXlow(),g1->GetEXhigh(),g1->GetEYhigh(),g1->GetEYlow());

TGraphAsymmErrors *g2 = new TGraphAsymmErrors(file2, "%lg %*s %lg %lg %lg");
TGraphAsymmErrors *gr2 = new TGraphAsymmErrors(g2->GetN(),g2->GetX(),g2->GetY(),g2->GetEXlow(),g2->GetEXhigh(),g2->GetEYhigh(),g2->GetEYlow());

TGraphAsymmErrors *g3 = new TGraphAsymmErrors(file3, "%lg %*s %lg %lg %lg");
TGraphAsymmErrors *gr3 = new TGraphAsymmErrors(g3->GetN(),g3->GetX(),g3->GetY(),g3->GetEXlow(),g3->GetEXhigh(),g3->GetEYhigh(),g3->GetEYlow());

// TGraphAsymmErrors *g4 = new TGraphAsymmErrors(file4, "%lg %*s %lg %lg %lg");
// TGraphAsymmErrors *gr4 = new TGraphAsymmErrors(g4->GetN(),g4->GetX(),g4->GetY(),g4->GetEXlow(),g4->GetEXhigh(),g4->GetEYhigh(),g4->GetEYlow());

TGraph *gr = new TGraph(file5, "%lg %lg");
TGraph *grr = new TGraph(file6, "%lg %lg");
TGraph *grrr = new TGraph(file7, "%lg %lg");
// TGraph *grrrr = new TGraph(file8, "%lg %lg");

// TGraph *gr1 = new TGraph(file3, "%lg %*s %*s %lg %*s %*s");
// TGraph *gr2 = new TGraph(file4, "%lg %*s %*s %lg %*s %*s");


// Options

gr1->SetMarkerColor(kBlue);
gr1->SetMarkerStyle(21);

gr2->SetMarkerColor(kRed);
gr2->SetMarkerStyle(21);

gr3->SetMarkerColor(kMagenta+3);
gr3->SetMarkerStyle(21);

// gr4->SetMarkerColor(kGreen-1);
// gr4->SetMarkerStyle(21);

gr->SetMarkerColor(kBlue-6);
gr->SetMarkerStyle(20);
gr->SetLineWidth(2);
gr->SetLineColor(kBlue-6);

grr->SetMarkerColor(kRed-3);
grr->SetMarkerStyle(22);
grr->SetMarkerSize(1.5);
grr->SetLineWidth(2);
grr->SetLineColor(kRed-3);

grrr->SetMarkerColor(kMagenta-1);
grrr->SetMarkerStyle(20);
grrr->SetLineWidth(2);
grrr->SetLineColor(kMagenta-1);

// grrrr->SetMarkerColor(kGreen+1);
// grrrr->SetMarkerStyle(20);
// grrrr->SetLineWidth(2);
// grrrr->SetLineColor(kGreen+1);

mg->Add(gr1,"p");
mg->Add(gr2,"p");
mg->Add(gr3,"p");
// mg->Add(gr4,"p");

mg->Add(gr);
mg->Add(grr);
mg->Add(grrr);
// mg->Add(grrrr);


// mg->GetXaxis()->SetRangeUser(6,12);
// mg->GetYaxis()->SetRangeUser(1E-9,1E-7);


mg->GetXaxis()->SetTitle("E_{#gamma} (MeV)");
mg->GetYaxis()->SetTitle("#font[12]{f_{1}}(MeV^{-3})");

//Draw

mg->Draw("APL");

auto legend = new TLegend(0.6,0.15,0.85,0.45);
legend->SetBorderSize(0);
legend->AddEntry(gr1, "{}^{71}As(p,#gamma) Szeflinska et al. (1979)","p");
legend->AddEntry(gr,"Brink-Axel PSF (71As,1979)","lp");
legend->AddEntry(gr2,"{}^{73}As(p,#gamma) Szeflinkska et al. (1979)","p");
legend->AddEntry(grr,"Brink-Axel PSF (73As,1979)","lp");
legend->AddEntry(gr3, "{}^{73}As(p,#gamma) Ratkevich et al. (1995)","p");
legend->AddEntry(grrr,"Brink-Axel PSF (1995)","lp");
// legend->AddEntry(gr4,"{}^{75}As(p,#gamma) Szeflinkska et al. (1979)","p");
// legend->AddEntry(grrrr,"Brink-Axel PSF (75As,1992)","lp");
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
