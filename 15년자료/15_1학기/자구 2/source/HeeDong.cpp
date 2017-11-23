class Polynomial
{
private:
	int degree;
	float *coef;
	Term *termArray;
	int capacity;
	int terms;


public:
	Polynomial();

	Polynomial Add(Polynomial poly);

	Polynomial Mult(Polynomial poly);


	float Eval(float f);


};

Polynomial:: Polynomial(int d)
{
	degree = d;
	coef = new float[degree +1];
}

class Term
{

	friend class Polynomial;

private:
	float coef;
	int exp;

};

Polynomial Polynomial::Add(Polynomial b)
{
	Polynomial c;
	int aPos=0, bPos =0;
	while((aPos < terms)&&(bPos<b.terms))
		if((termArray[aPos].exp == b.termArray[bPos].exp))
		{
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if(t)c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;

		}

		else if(termArray[aPos].exp < termArray[bPos].exp)
		{
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}

		else
		{
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;

		}

		for(;aPos<terms;aPos++)
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
		
		for(;bPos<terms;bPos++)
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

		return c;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
	if(terms == capacity)
	{
		capacity *= 2;
		term *temp = new term[capacity];
		copy(termArray, termArray+ terms, temp);
		delete[] termArray;
		termArray =temp;

	}

	termArrayp[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}
