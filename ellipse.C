#include<iostream>
using namespace std;


int ellipse(){
double N=1000;
double acc[1000];
double  rej[1000]; //accepted and total points
double n_t =0;

double xVal[1000];

// accepted X/Y values
  TRandom3 *rnd = new TRandom3();
 vector<double>sample; //sample number
 
 double x, y;
 
 for(int i=0; i<N; i++){
 
	 xVal[i] = i*0.001;
	 x = rnd->Rndm(i) ;
	 y= rnd->Rndm(i)+x;
//cout<<"x and y random values are "<<x<< "   "<<y<<endl;
    

    if((x*x)/1 + (y*y)/2 <= 1){
    
	  acc[i] = ( (x*x) + (y*y)/2);
  
	  cout<<acc[i]<<endl;
    }
   else {
        rej[i] = (x*x)/1 + (y*y)/2;
  cout<<"rej"<<rej[i]<<endl;
   }

//cout<<acc[i]<<"   "<<rej[i]<<endl;

 }

//func 
TF2 *f = new TF2("f", "x*x + y*y/2", 0, 1, 0, 2);

//plots from the data
auto *gr_acc = new TGraph(1000, xVal, acc);
auto *gr_rej = new TGraph(1000, xVal, rej);


TMultiGraph *gr = new TMultiGraph();
auto *c = new TCanvas();
gr_acc->SetMarkerStyle(21);
gr_acc->SetMarkerColor(3);
gr_rej->SetMarkerStyle(22);
gr_rej->SetMarkerColor(6);
gr_acc->SetMarkerColor(2);
gr->Add(gr_acc);
gr->Add(gr_rej);
gr->SetTitle("Accep/Reject Sampling");
f->Draw("pl");
gr->Draw("P");

c->SaveAs("samp.pdf");

return 0;
}
