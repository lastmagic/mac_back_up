#include <fstream>

struct indiTerm
{
	int exp;
	char var;
};

class Term()
{
	
	public:
		int coef;
		int sumOfexp;
		indiTerm termArray[26];

	//public:

		//Compare();
		//SumofTerm();
		//Bigger();

	public Term()
	{

	}
	public bool Compare(Term B)
	{
		int i;
		if(sumOfexp == B.sumOfexp)
		{
			for(i=0;termArray[i].var==B.termArray[i].var;i++)
			{

			}

			if(i==26)
				return true;

		}
		return false;
	}

	public bool Bigger(Term B)
	{
		int i;
		if(sumOfexp > B.sumOfexp)
		{
			return true;
		}

		else
		{
			for(i=0; i<26; i++)
			{
				if(termArray[i].exp > B.termArray[i].exp)
					return true;
				else if(termArray[i].exp < B.termArray[i].exp)
					return false;

				else
				{
					if(termArray[i].var < B.termArray[i].var)
						return true;
					else if(termArray[i].var > B.termArray[i].var)
						return false;
				}
			}	

			return false;
		}

	}


	public Term SumofTerm(Term B)
	{
		int i;

		Term C;
		for(i=0; i<26; i++)
		{
			C.termArray[i].var = termArray[i].var;
			C.termArray[i].exp = termArray[i].exp;
			C.coef = coef + B.coef;	

		}
		return C;
	}
}

class Polynomial()
{
	//friend class Term;
	public:
		int terms;
		Term Poly[100];

	//public:
		//SumofPoly();


	public Polynomial(String a)
	{
		Polynomial A;
		int i,length;
		int poPos=0,tePos=-1;
		bool minus;
		bool Ecnt;
		bool first;
		length = a.length();
		for(poPos=0; poPos<100; poPos++)
		{
			A.poly[poPos].coef = 0;
		}


		for(i=0; i<length; i++)
		{
			
			if(('0'<=a[i])&&(a[i]<='9'))
			{
				if(Ecnt==false)
				{
					A.Poly[poPos].coef = 10 * A.Poly[poPos].coef + (a[i]-'0');
				}	
				else(Ecnt==true)
				{
					A.Poly[poPos].termArray[tePos].exp = 10 * A.Poly[poPos].termArray[tePos].exp + (a[i]-'0');				}
				}
			}

			else if(('a'<=a[i])&&(a[i]<='z'))
			{
				if(A.Poly[poPos].coef==0)
				{
					A.Poly[poPos].coef=1;
				}

				if(minus==true)
				{
					A.Poly[poPos].coef = -A.Poly[poPos].coef;
					minus=false;
				}

				TePos++;
				A.Poly[poPos].termArray[tePos].var = a[i];
			}	

			else if(a[i]=='+')
			{
				poPos++;
				Ecnt = false;
				TePos=-1;
			}

			else if(a[i]=='-')
			{
				minus = true;
			}

			else if(a[i]=='^')
			{
				Ecnt=true;
			}

		} 

	}

	public Polynomial()
	{

	}
	public Polynomial SumofPoly(Polynomial B)
	{
		int i;
		Polynomial C;
		int aPos=0,bPos=0,cPos=0;
		While(1)
		{
			if(Poly[aPos].Compare(B.Poly[bPos]))
			{
				C.Poly[cPos] = Poly[aPos].SumofTerm(B.Poly[bPos]);
				aPos++; bPos++; cPos++;

			}
			else if(Poly[aPos].Bigger(B.Poly[bPos]))
			{
				C.Poly[cPos] = Poly[aPos];
				cPos++; aPos++;
			}	
			else if(!(Poly[aPos].Bigger(B.Poly[bPos])))
			{
				C.Poly[cPos] = B.Poly[bPos];
				cPos++; bPos++;
			}

			if(aPos == terms)
			{
				while(1)
				{
					if(bPos ==B.terms)
					{
						break;
					}
					C.Poly[cPos] = B.Poly[bPos];
					cPos++; bPos++;
					
				}

				break;
			}

			else if(bPos == B.terms)
			{
				while(1)
				{
					if(aPos == terms)
					{
						break;
					}
					C.Poly[cPos] = Poly[aPos];
					cPos++; aPos++;
					
				}

				break;
			}



		}
		return C;
	}


}

int main(int argc, char **argv)
{
	String str_a;
	String str_b;

	std:: ifstream input(argv[1]);
	std:: ofstream output(argvp[2]);
	

	while(getline(output, String str_a))
	{
		getline(output, String str_b)
	}
	
	
	Polynomial A(String str_a);
	Polynomial B(String str_b);
	Polynomial C();

	C = A.SumofPoly(B);

}