/*
	Author: John Nemeth
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ATTRIBUTECOUNT 9

double posExamples = 6.0f;
double negExamples = 6.0f;
char examplesUsed[13];

struct Attribute {
        char attrName[256];
	int numVals;
	int posArray[10];
        int negArray[10];
	char attr[13];
};

struct Example {

};

double EntropyGivenTrueProbability(double term) {
	if (term == 0.0)
		term = 0.00000001;
	if (term == 1.0)
		term = 0.99999999;
	double t1 = (log2(term)) * term;
	double t2 = (log2(1.0 - term)) * (1.0 - term);
	//fprintf(stderr, "term: %f, t1: %f, t2: %f, result: %f\n", term, t1, t2, (-(t1+t2)));
	return -(t1 + t2);
}

double Remainder(struct Attribute * attr) {

	int i;
	double sumTotal = 0.0f;
	for (int i = 0; i < attr->numVals; i++) {
		double posCount = (double) attr->posArray[i];
		double negCount = (double) attr->negArray[i];
		double term1 = (posCount + negCount) / (posExamples + negExamples);
		double term2 = posCount / (posCount + negCount);
		term2 = EntropyGivenTrueProbability(term2);
		//fprintf(stderr, "\tremainder check - term1: %f, term2: %f\n", term1, term2);
		sumTotal += (term1 * term2);
	}
	//fprintf(stderr, "\tsumtotal entropy for attribute %s: %f\n", attr->attrName, sumTotal);
	return sumTotal;
}

double CalcInfoGain(struct Attribute * attr) {

	double goalProbability = posExamples / (posExamples + negExamples);
	double term1 = EntropyGivenTrueProbability(goalProbability);
	double term2 = Remainder(attr);

	return term1 - term2;
	
}

int main() {

	struct Attribute list[9];

	// "Alternate" vals = yes, no 
        strcpy(list[0].attrName, "Alternative");
        list[0].numVals = 2;
        list[0].posArray[0] = 3;
        list[0].posArray[1] = 3;
        list[0].negArray[0] = 3;
        list[0].negArray[1] = 3;
	
	// "has bar" vals = yes, no
        strcpy(list[1].attrName, "Bar");
        list[1].numVals = 2;
        list[1].posArray[0] = 3;
        list[1].posArray[1] = 3;
        list[1].negArray[0] = 3;
        list[1].negArray[1] = 3;
	// "is fri/sat?" vals = yes, no
        strcpy(list[2].attrName, "Fri/Sat");
        list[2].numVals = 2;
        list[2].posArray[0] = 2;
        list[2].posArray[1] = 4;
        list[2].negArray[0] = 3;
        list[2].negArray[1] = 3;
	// "patrons" vals = none, some, full
        strcpy(list[3].attrName, "Patron");
        list[3].numVals = 3;
        list[3].posArray[0] = 0;
        list[3].posArray[1] = 4;
        list[3].posArray[2] = 2;
        list[3].negArray[0] = 2;
        list[3].negArray[1] = 0;
        list[3].negArray[2] = 4;
	// "price" vals = $, $$, $$$
        strcpy(list[4].attrName, "Price");
        list[4].numVals = 3;
        list[4].posArray[0] = 3;
        list[4].posArray[1] = 2;
        list[4].posArray[2] = 1;
	list[4].negArray[0] = 4;
	list[4].negArray[1] = 0;
	list[4].negArray[2] = 2;
	// "rain" vals = yes, no
        strcpy(list[5].attrName, "Raining");
        list[5].numVals = 2;
        list[5].posArray[0] = 3;
        list[5].posArray[1] = 3;
	list[5].negArray[0] = 4;
	list[5].negArray[1] = 2;
	// "reservation" values = yes, no
        strcpy(list[6].attrName, "Reservation");
        list[6].numVals = 2;
        list[6].posArray[0] = 3;
        list[6].posArray[1] = 3;
	list[6].negArray[0] = 4;
	list[6].negArray[1] = 2;
	// "type" values = french, tahi, burger, italian
	strcpy(list[7].attrName, "Food");
	list[7].numVals = 4;
	list[7].posArray[0] = 1;
	list[7].posArray[1] = 2;
	list[7].posArray[2] = 2;
	list[7].posArray[3] = 1;
	list[7].negArray[0] = 1;
	list[7].negArray[1] = 2;
	list[7].negArray[2] = 2;
	list[7].negArray[3] = 1;
	// "estimation" values = 0-10, 10-30, 30-60, >60
	strcpy(list[8].attrName, "Estimated Wait");
	list[8].numVals = 4;
	list[8].posArray[0] = 4;
	list[8].posArray[1] = 1;
	list[8].posArray[2] = 1;
	list[8].posArray[3] = 0;
	list[8].negArray[0] = 2;
	list[8].negArray[1] = 1;
	list[8].negArray[2] = 1;
	list[8].negArray[3] = 2;

	int i;
	double curInfoGain = 0.0f;
	for (int i = 0; i < ATTRIBUTECOUNT; i++) {
		fprintf(stderr, "---Attribute '%s'\n", list[i].attrName);
		curInfoGain = CalcInfoGain(&list[i]);
		fprintf(stderr, "Info Gain with Attribute '%s': %f\n\n", list[i].attrName, curInfoGain);
	}

	return 0;
}
