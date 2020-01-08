#pragma once
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class CMSCN{

public:
	
	CMSCN(int d, int f, int m, int s)
	{
	
		if (d < 0 || f < 0 || m < 0 || s < 0) 
		
			cout << "Wrong numbers\n";
		
		else {
			
			this->d = d;
			
			this->f = f;
			
			this->m = m;
			
			this->s = s;

			cd = new double* [d];
			
			for (int i = 0; i < d; i++) {
			
				cd[i] = new double[f];
				
				for (int j = 0; j < f; j++)
				
					cd[i][j] = 1;
			}
			
			cf = new double* [f];
			
			for (int i = 0; i < f; i++) {
			
				cf[i] = new double[m];
				
				for (int j = 0; j < m; j++) 
				
					cf[i][j] = 1;
				
			}
			
			cm = new double* [m];
			
			for (int i = 0; i < m; i++) {
			
				cm[i] = new double[s];
				
				for (int j = 0; j < s; j++) 
				
					cm[i][j] = 1;
				
			}
			xd = new double* [d];
			
			for (int i = 0; i < d; i++) 
			
				xd[i] = new double[f];
			
			xf = new double* [f];
		
			for (int i = 0; i < f; i++) 

				xf[i] = new double[m];
			
			xm = new double* [m];
		
			for (int i = 0; i < m; i++) 
			
				xm[i] = new double[s];
			
			sd = new double[d];
			
			for (int i = 0; i < d; i++) { sd[i] = 1; }
			
			sf = new double[f];
			
			for (int i = 0; i < f; i++) { sf[i] = 1; }
			
			sm = new double[m];
			
			for (int i = 0; i < m; i++) { sm[i] = 1; }
			
			ss = new double[s];
			
			for (int i = 0; i < s; i++) { ss[i] = 1; }
			
			ud = new double[s];
			
			for (int i = 0; i < d; i++) { ud[i] = 1; }
			
			uf = new double[s];
			
			for (int i = 0; i < f; i++) { uf[i] = 1; }
			
			um = new double[s];
			
			for (int i = 0; i < m; i++) { um[i] = 1; }
			
			ps = new double[s];
			
			for (int i = 0; i < s; i++) { ps[i] = 1; }
		}
	}
	~CMSCN(){
		delete[] cd, cf, cm, xd, xf, xd, sd, sf, sm, ss, ud, uf, um, ps;
	}
	
	void setD(int n)
	{
		if (n < 0)	cout << "Negative N is detected on setD" << endl;
		
		else{
			
			int dd = d;
			
			d = n;
			
			double** ccd = new double* [d];
			
			for (int i = 0; i < d; i++) 
			
				ccd[i] = new double[f];
			
			for (int i = 0; i < d; i++) {
			
				for (int j = 0; j < f; j++) 
				
					if (i < dd) ccd[i][j] = cd[i][j];
					
					else ccd[i][j] = 1;
				
			}
			
			delete[]cd;
			
			cd = ccd;
			
			double* sdd = new double[d];
			
			for (int i = 0; i < d; i++) {
			
				if (i < dd) sdd[i] = sd[i];
				
				else sdd[i] = 1;
			}
			
			delete[] sd;
			
			sd = sdd;
			
			double* udd = new double[d];
			
			for (int i = 0; i < d; i++) 
			
				if (i < dd) udd[i] = ud[i];
				
				else udd[i] = 1;
			
			delete[] ud;

			ud = udd;
			
			xd = new double* [d];
			
			for (int i = 0; i < d; i++) 
			
				xd[i] = new double[f];
			
		}
	}
	void setF(int n)
	{
		if (n < 0)	cout << "Wrong setF n\n";
		
		else
		{
			int ff = f;
		
			f = n;
		
			double** ccd = new double* [d];
		
			for (int i = 0; i < d; i++) 	ccd[i] = new double[f];
			
			for (int i = 0; i < d; i++) {
				
				for (int j = 0; j < f; j++) 
				
					if (j < ff) ccd[i][j] = cd[i][j];
				
					else ccd[i][j] = 1;
				
			}
			
			delete[]cd;
		
			cd = ccd;
		
			double** ccf = new double* [f];
			
			for (int i = 0; i < f; i++) 
			
				ccf[i] = new double[m];
			
			for (int i = 0; i < f; i++) {
		
				for (int j = 0; j < m; j++) 
				
					if (i < ff) ccf[i][j] = cf[i][j];
					
					else ccf[i][j] = 1;
				
			}
			
			delete[]cf;
			
			cf = ccf;
			
			double* sff = new double[f];
			
			for (int i = 0; i < f; i++) 
			
				if (i < ff) sff[i] = sd[i];
				
				else sff[i] = 1;
			
			delete[] sf;
		
			sf = sff;
			
			double* uff = new double[f];
			
			for (int i = 0; i < f; i++) 
			
				if (i < ff) uff[i] = ud[i];
				
				else uff[i] = 1;
			
			delete[] uf;

			uf = uff;
			
			xd = new double* [d];
			
			for (int i = 0; i < d; i++) 
			
				xd[i] = new double[f];
			
			xf = new double* [f];

			for (int i = 0; i < f; i++) 
			
				xf[i] = new double[m];
			
		}
	}

	void setM(int n)
	{
		if (n < 0)
		
			cout << "Wrong n is detected on setM\n";
		
		else
		{
			int mm = m;
		
			m = n;
			
			double** ccm = new double* [m];
			
			for (int i = 0; i < m; i++) 
			
				ccm[i] = new double[s];
			
			for (int i = 0; i < m; i++) {
			
				for (int j = 0; j < s; j++) 
				
					if (j < mm) ccm[i][j] = cm[i][j];
					
					else ccm[i][j] = 1;
			}
			
			delete[]cm;
			
			cm = ccm;
			
			double** ccf = new double* [f];
			
			for (int i = 0; i < f; i++)
			
				ccf[i] = new double[m];
			
			for (int i = 0; i < f; i++) {

				for (int j = 0; j < m; j++) 
				
					if (i < mm) ccf[i][j] = cf[i][j];
					
					else ccf[i][j] = 1;
				
			}

			delete[]cf;
			
			cf = ccf;
			
			double* smm = new double[m];
			
			for (int i = 0; i < m; i++) {
			
				if (i < mm) smm[i] = sm[i];
				
				else sm[i] = 1;
			}
			
			delete[] sm;
			
			sm = smm;
			
			double* umm = new double[m];
			
			for (int i = 0; i < m; i++) {
			
				if (i < mm) umm[i] = um[i];
				
				else um[i] = 1;
			}
			
			delete[] um;
			
			um = umm;
			
			xf = new double* [f];
			
			for (int i = 0; i < f; i++) 
			
				xf[i] = new double[m];
			
			xm = new double* [m];
			
			for (int i = 0; i < m; i++)

				xm[i] = new double[s];
			
		}
	}
	
	void setS(int n){

		if (n < 0)
		
			cout << "Wrong n is detected on setS\n";
		
		else
		{
			int sss = s;
		
			s = n;
			
			double** ccs = new double* [m];
			
			for (int i = 0; i < m; i++) 
			
				ccs[i] = new double[s];
		
			for (int i = 0; i < m; i++) {
			
				for (int j = 0; j < s; j++) 
			
					if (j < sss) ccs[i][j] = cm[i][j];
				
					else ccs[i][j] = 1;
				
			}
			
			delete[]cm;
		
			cm = ccs;
		
			double* ssss = new double[s];
		
			for (int i = 0; i < s; i++) {
			
				if (i < sss) ssss[i] = ss[i];
			
				else ssss[i] = 1;
			}
			
			delete[] ss;
		
			ss = ssss;
		
			double* pss = new double[s];
			
			for (int i = 0; i < s; i++) {
		
				if (i < sss) pss[i] = ps[i];
		
				else pss[i] = 1;
			}
		
			delete[] ps;
		
			ps = pss;
		
			xm = new double* [m];
		
			for (int i = 0; i < m; i++) xm[i] = new double[s];
							
		}
	}
	void fillCD() {
	
		for (int i = 0; i < d; i++) {
		
			for (int j = 0; j < f; j++) {
		
				cout << "cd[" << i << "][" << j << "] ";
		
				cin >> cd[i][j];
		
				if (cd[i][j] < 0) {
				
					cout << "\nWrong number one more time on fillCD:\n";
				
					j--;
				}
			}
		}
	}
	
	void fillCF() {
		
		for (int i = 0; i < f; i++) {
		
			for (int j = 0; j < m; j++) {
			
				cout << "cf[" << i << "][" << j << "] ";
			
				cin >> cf[i][j];
			}
		}
	}
	
	void fillCM() {
	
		for (int i = 0; i < m; i++) {
		
			for (int j = 0; j < s; j++) {
		
				cout << "cm[" << i << "][" << j << "] ";
		
				cin >> cm[i][j];
			}
		}
	}

	void fillSD() {
	
		for (int i = 0; i < d; i++) {
		
			cout << "sd[" << i << "]";
		
			cin >> sd[i];

		}
	}
	
	void fillSF() {
	
		for (int i = 0; i < f; i++) {
	
			cout << "sf[" << i << "]";
	
			cin >> sf[i];

		}
	}
	
	void fillSM() {
	
		for (int i = 0; i < m; i++) {
	
			cout << "sm[" << i << "]";
		
			cin >> sm[i];

		}
	}
	
	void fillSS() {
	
		for (int i = 0; i < s; i++) {
		
			cout << "ss[" << i << "]";
		
			cin >> ss[i];

		}
	}
	
	void fillUD() {
	
		for (int i = 0; i < d; i++) {
		
			cout << "ud[" << i << "]";
		
			cin >> ud[i];

		}
	}
	
	void fillUF() {
	
		for (int i = 0; i < s; i++) {
		
			cout << "uf[" << i << "]";
			
			cin >> uf[i];

		}
	}
	
	void fillUM() {
	
		for (int i = 0; i < m; i++) {
		
			cout << "um[" << i << "]";
			
			cin >> um[i];
		}
	}
	
	void fillPS() {
	
		for (int i = 0; i < s; i++) {
		
			cout << "ps[" << i << "]";
			
			cin >> ps[i];

		}
	}
	void autofillCD() {
		
		for (int i = 0; i < d; i++) {
		
			for (int j = 0; j < f; j++)

				cd[i][j] = 100;
		}
	}

	void autofillCF() {
	
		for (int i = 0; i < f; i++) {
		
			for (int j = 0; j < m; j++) 
			
				cf[i][j] = 100;
			
		}
	}
	
	void autofillCM() {
	
		for (int i = 0; i < m; i++) {
		
			for (int j = 0; j < s; j++) 
			
				cm[i][j] = 100;
			
		}
	}

	void autofillSD() {
		
		for (int i = 0; i < d; i++) 
		
			sd[i] = 10000;

		
	}
	void autofillSF() {

		for (int i = 0; i < f; i++) 
		
			sf[i] = 10000;
	}
	
	void autofillSM() {
	
		for (int i = 0; i < m; i++) 

			sm[i] = 10000;

	}
	
	void autofillSS() {
	
		for (int i = 0; i < s; i++) 
		
			ss[i] = 10000;

	}
	void autofillUD() {
		
		for (int i = 0; i < d; i++) 
		
			ud[i] = 100;
	
	}
	void autofillUF() {
	
		for (int i = 0; i < s; i++) 
			
			uf[i] = 100;

	}
	void autofillUM() {
		
		for (int i = 0; i < m; i++) 
		
			um[i] = 100;
	}
	
	void autofillPS() {
	
		for (int i = 0; i < s; i++) 
		
			ps[i] = 100;

		
	}
	void autofillall() {
		
		autofillCD();
		
		autofillCF();
		
		autofillCM();
		
		autofillPS();
		
		autofillSD();
		
		autofillSF();
		
		autofillSM();
		
		autofillSS();
		
		autofillUD();
		
		autofillUF();
		
		autofillUM();
	}
	
	void fillall() {
	
		fillCD();
		
		fillCF();
		
		fillCM();
		
		fillSD();
		
		fillSF();
		
		fillSM();
		
		fillSS();
		
		fillUD();
		
		fillUF();
		
		fillUM();
		
		fillPS();
	}
	
	void fillGivenCD(int i, int j, double n) { if (n < 0 || j>f || j < 0 || i<0 || i>d) cout << "Wrong number\n"; else  cd[i][j] = n; }
	
	void fillGivenCF(int i, int j, double n) { if (n < 0 || j>m || j < 0 || i<0 || i>f) cout << "Wrong number\n"; else  cf[i][j] = n; }
	
	void fillGivenCM(int i, int j, double n) { if (n < 0 || j>s || j < 0 || i<0 || i>m) cout << "Wrong number\n"; else  cm[i][j] = n; }
	
	void fillGivenSD(int i, double n) { if (n < 0 || i<0 || i>d) cout << "Wrong number\n"; else  sd[i] = n; }
	
	void fillGivenSF(int i, double n) { if (n < 0 || i<0 || i>f) cout << "Wrong number\n"; else  sf[i] = n; }
	
	void fillGivenSM(int i, double n) { if (n < 0 || i<0 || i>m) cout << "Wrong number\n"; else  sm[i] = n; }
	
	void fillGivenSS(int i, double n) { if (n < 0 || i<0 || i>s) cout << "Wrong number\n"; else  ss[i] = n; }
	
	void fillGivenUD(int i, double n) { if (n < 0 || i<0 || i>d) cout << "Wrong number\n"; else  ud[i] = n; }
	
	void fillGivenUF(int i, double n) { if (n < 0 || i<0 || i>f) cout << "Wrong number\n"; else  uf[i] = n; }
	
	void fillGivenUM(int i, double n) { if (n < 0 || i<0 || i>m) cout << "Wrong number\n"; else  um[i] = n; }
	
	void fillGivenPS(int i, double n) { if (n < 0 || i<0 || i>s) cout << "Wrong number\n"; else  ps[i] = n; }
	
	void showCD(){

		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < f; j++)
			
				cout << cd[i][j] << " ";
			
			cout << endl;
		}
	}

	void showCF(){
	
		for (int i = 0; i < f; i++)
		{
			for (int j = 0; j < m; j++)
			
				cout << cf[i][j] << " ";
			
			cout << endl;
		}
	}

	void showCM()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < s; j++)
			
				cout << cm[i][j] << " ";
			
			cout << endl;
		}
	}
	void showXD(){

		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < f; j++)
			
				cout << xd[i][j] << " ";
			
			cout << endl;
		}
	}
	
	void showXF(){

		for (int i = 0; i < f; i++)
		{
			for (int j = 0; j < m; j++)
			
				cout << xf[i][j] << " ";
			
			cout << endl;
		}
	}
	void showXM(){

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < s; j++)
			
				cout << xm[i][j] << " ";
			
			cout << endl;
		}
	}

	void showSD(){
	
		for (int i = 0; i < m; i++)
		
			cout << sd[i] << " ";
		
		cout << "\n";
	}
	
	void showSF(){

		for (int i = 0; i < m; i++)
		
			cout << sf[i] << " ";
		
		cout << "\n";
	}
	void showSM(){

		for (int i = 0; i < m; i++)
		
			cout << sm[i] << " ";
		
		cout << "\n";
	}
	void showSS()
	{
		for (int i = 0; i < m; i++)
		
			cout << ss[i] << " ";
		
		cout << "\n";
	}
	void showUD()
	{
		for (int i = 0; i < m; i++)
		
			cout << ud[i] << " ";
		
		cout << "\n";
	}
	void showUF()
	{
		for (int i = 0; i < m; i++)
		
			cout << uf[i] << " ";
		
		cout << "\n";
	}
	void showUM()
	{
		for (int i = 0; i < m; i++)
		
			cout << um[i] << " ";
		
		cout << "\n";
	}
	void showPS()
	{
		for (int i = 0; i < m; i++)
		
			cout << ps[i] << " ";
		
		cout << "\n";
	}
	int size(double* some)
	{
		
		return 30;
	}

	bool changeToMatrixes(double* pdSolution, int size)
	{
		if (size != (d * f) + (f * m) + (m * s)) 
			
			return false;
		
		else {
			
			for (int i = 0; i < d; i++) {
			
				for (int j = 0; j < f; j++) 
				
					xd[i][j] = pdSolution[(i * f) + j];
				
			}
			for (int i = 0; i < f; i++) {
			
				for (int j = 0; j < m; j++) 
				
					xf[i][j] = pdSolution[(d * f) + (i * m) + j];
				
			}
			for (int i = 0; i < m; i++) {
			
				for (int j = 0; j < s; j++) 
			
					xm[i][j] = pdSolution[(d * f) + (f * m) + (i * s) + j];
				
			}
			return true;
		}
	}
	bool checkOne()
	{
		bool checker = true;
	
		for (int i = 0; i < d; i++)
		{
			double sum = 0;
			
			for (int j = 0; j < f; j++)
			
				sum = sum + xd[i][j];
			
			if (sum > sd[i]){

				checker = false;
				
				break;
			}
		}
		return checker;
	}
	bool checkTwo()
	{
		bool checker = true;
	
		for (int i = 0; i < f; i++)
		{
			double sum = 0;
		
			for (int j = 0; j < m; j++)
			
				sum += xf[i][j];
			
			if (sum > sf[i]){

				checker = false;
				
				break;
			}
		}
		return checker;
	}
	bool checkThree()
	{
		bool checker = true;
		
		for (int i = 0; i < m; i++)
		{
			double sum = 0;
		
			for (int j = 0; j < s; j++)
			
				sum += xm[i][j];
			
			if (sum > sm[i])
			{
				checker = false;
			
				break;
			}
		}
		return checker;
	}
	bool checkFour()
	{
		bool checker = true;
		
		for (int i = 0; i < s; i++)
		{
			double sum = 0;
			
			for (int j = 0; j < m; j++)
			
				sum += xm[i][j];
			
			if (sum > ss[i])
			{
				checker = false;
			
				break;
			}
		}
		return checker;
	}
	bool checkFive()
	{
		bool checker = true;
		
		for (int i = 0; i < f; i++){

			double sumd = 0;
		
			for (int j = 0; j < d; j++)
			
				sumd += xd[j][i];
			
			double summ = 0;
			
			for (int j = 0; j < m; j++)
			
				summ += xf[i][j];
			
			if (sumd < summ)
			{
				checker = false;
			
				break;
			}
		}
		return checker;
	}
	bool checkSix()
	{
		bool checker = true;
	
		for (int i = 0; i < m; i++)
		{
			double sumf = 0;
			
			for (int j = 0; j < f; j++)
			
				sumf += xf[j][i];
			
			
			double sums = 0;
			
			for (int j = 0; j < s; j++)
			
				sums += xm[i][j];
			
			if (sumf < sums)
			{
				checker = false;
				
				break;
			}
		}
		return checker;
	}
	bool isGood()
	{
		if (checkOne() == false || checkTwo() == false || checkThree() == false || checkFive() == false || checkSix() == false)
		
			return false;
		
		else
		
			return true;
		
	}
	bool bConstraintsSatisfied(double* pdSolution, int size) {
	
		if (changeToMatrixes(pdSolution, size) == false) { return false; }
	
		if (isGood() == false) { return false; }
	
		return true;
	}

	double calculateP()
	{
		double sum = 0;
	
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < s; j++)
			
				sum = sum + (ps[j] * xm[i][j]);
			
		}
		return sum;
	}
	
	double calculateKT()
	{
		double sumOne = 0;
		
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < f; j++)
			
				sumOne = sumOne + (cd[i][j] * xd[i][j]);
			
		}
		
		double sumTwo = 0;
		
		for (int i = 0; i < f; i++)
		{
			for (int j = 0; j < m; j++)
			
				sumTwo = sumTwo + (cf[i][j] * xf[i][j]);
			
		}
		
		double sumThree = 0;
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < s; j++)
			
				sumThree = sumThree + (cm[i][j] * xm[i][j]);
			
		}
		return sumOne + sumTwo + sumThree;
	}
	double calculateKU()
	{
		double sumOne = 0;
		
		for (int i = 0; i < d; i++)
		{
			double sumPart = 0;
			
			for (int j = 0; j < f; j++)
			
				sumPart = sumPart + xd[i][j];
			
			if (sumPart > 0) sumOne = sumOne + ud[i];
		}
		
		double sumTwo = 0;
		
		for (int i = 0; i < f; i++)
		{
			double sumPart = 0;
			
			for (int j = 0; j < m; j++)
			
				sumPart = sumPart + xf[i][j];
			
			if (sumPart > 0) sumTwo = sumTwo + uf[i];
		}
		
		double sumThree = 0;
		
		for (int i = 0; i < m; i++)
		{
			double sumPart = 0;
			
			for (int j = 0; j < s; j++)
			
				sumPart = sumPart + xm[i][j];
			
			if (sumPart > 0) sumThree = sumThree + um[i];
		}
		return sumOne + sumTwo + sumThree;
	}
	double dGetQuality(double* pdSolution, int size)
	{
		if (bConstraintsSatisfied(pdSolution, size) == false)
		{
			cout << "WrongdGetQuality size" << endl;
		
			return 0.0;
		}
		else
		
			return calculateP() - calculateKU() - calculateKT();
		

	}
	void setRange(double min, double max)
	{
		this->max = max;
		
		this->min = min;
	}
	bool isInRange(double* pdSolution)
	{
		for (int i = 0; i < size(pdSolution); i++)
		
			if (pdSolution[i]<min || pdSolution[i]>max)
			
				return false;

		return true;
	}
	void save(string filename)
	{
		ofstream file;
		
		file.open(filename);
		
		file << "D: \n" << d << "\nF: \n" << f << "\nM: \n" << m << "\nS: \n" << s << "\nCD:\n";
		
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < f; j++)
			
				file << cd[i][j] << " ";
			
			file << "\n";
		}
	
		file << "CF:\n";
	
		for (int i = 0; i < f; i++)
		{
			for (int j = 0; j < m; j++)
			
				file << cf[i][j] << " ";
			
			file << "\n";
		}
		
		file << "CM:\n";
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < s; j++)
			
				file << cm[i][j] << " ";
			
			file << "\n";
		}
		
		file << "SD:\n";
		
		for (int i = 0; i < d; i++)
		
			file << sd[i] << " ";
		
	
		file << "\nSF:\n";
	
		for (int i = 0; i < f; i++)
		
			file << sf[i] << " ";
		
	
		file << "\nSM:\n";
	
		for (int i = 0; i < m; i++)
		
			file << sm[i] << " ";
		
		
		file << "\nSS:\n";
		
		for (int i = 0; i < s; i++)
		
			file << ss[i] << " ";
		
		
		file << "\nUD:\n";
		
		for (int i = 0; i < d; i++)
		
			file << ud[i] << " ";
		
		
		file << "\nUF:\n";
		
		for (int i = 0; i < f; i++)
		
			file << uf[i] << " ";
		
		
		file << "\nUM:\n";
		
		for (int i = 0; i < m; i++)
		
			file << um[i] << " ";
		
		file << "\nPS:\n";
		
		for (int i = 0; i < s; i++)
		
			file << ps[i] << " ";
		
		file.close();
	}
	void load(string filename)
	{
		string line;
	
		ifstream file;
		
		file.open(filename);
		
		for (int i = 0; getline(file, line); i++)
		{
			if (i == 1) { setD(stoi(line)); }
			
			if (i == 3) { setF(stoi(line)); }
			
			if (i == 5) { setM(stoi(line)); }
			
			if (i == 7) { setS(stoi(line)); }
		
			if (i > 8 && i <= 8 + d)

				cd[i - 9] = split(line, f);
			
			if (i > 9 + d && i <= 9 + d + f)

				cf[i - 10 - d] = split(line, m);
			
			if (i > 10 + d + f && i <= 10 + d + f + m)

				cm[i - 11 - d - f] = split(line, s);
			
			if (i == 12 + d + f + m)

				sd = split(line, d);
			
			if (i == 14 + d + f + m)

				sf = split(line, f);
			
			if (i == 16 + d + f + m)

				sm = split(line, m);
			
			if (i == 18 + d + f + m)

				ss = split(line, s);
			
			if (i == 20 + d + f + m)

				ud = split(line, d);
			
			if (i == 22 + d + f + m)

				uf = split(line, f);
			
			if (i == 24 + d + f + m)

				um = split(line, m);
			
			if (i == 26 + d + f + m)

				ps = split(line, s);
			
		}
		file.close();

	}

	double* split(string line, int num){

		double* ret = new double[num];
	
		int iter = 0;
		
		for (auto j = 0; j < num; j++){

			string number;

			while (isdigit(line[iter]) || line[iter] == '.')
			
				number += line[iter++];

			ret[j] = stod(number);

			iter++;
		}
		return ret;
	}

private:

	int f, m, s, d;

	double** cd, ** cf, ** cm, ** xd, ** xf, ** xm;

	double* sd, * sf, * sm, * ss, * ud, * uf, * um, * ps;

	double min = 0, max = 10000;
};