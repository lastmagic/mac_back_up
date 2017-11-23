#include <fstream>
#include <string>

struct indiTerm
{
	int exp;
	char var;
};

class Term
{

public:
	int coef;
	int sumOfexp;
	indiTerm termArray[26];

	//public:

	//Compare();
	//SumofTerm();
	//Bigger();

	Term()
	{
		coef = 0;
		sumOfexp = 0;
		
		for (int i = 0; i < 26; i++)
		{
			termArray[i].exp = 0;
			termArray[i].var = '\0';
		}
	}
	bool Compare(Term B)
	{
		int i;
		if (sumOfexp == B.sumOfexp)
		{
			for (i = 0; termArray[i].var == B.termArray[i].var; i++)
			{

			}

			if (i == 26)
				return true;

		}
		return false;
	}

	bool Bigger(Term B)
	{
		int i;
		if (sumOfexp > B.sumOfexp)
		{
			return true;
		}

		else
		{
			for (i = 0; i < 26; i++)
			{
				if (termArray[i].exp > B.termArray[i].exp)
					return true;
				else if (termArray[i].exp < B.termArray[i].exp)
					return false;

				else
				{
					if (termArray[i].var < B.termArray[i].var)
						return true;
					else if (termArray[i].var > B.termArray[i].var)
						return false;
				}
			}

			return false;
		}

	}


	Term SumofTerm(Term B)
	{
		int i;

		Term C;
		for (i = 0; i < 26; i++)
		{
			C.termArray[i].var = termArray[i].var;
			C.termArray[i].exp = termArray[i].exp;
			C.coef = coef + B.coef;

		}
		return C;
	}
};

class Polynomial
{
	//friend class Term;
public:
	int terms;
	Term Poly[200];

	//public:
	//SumofPoly();

	Polynomial()
	{
		terms = 0;

	}
	Polynomial(std::string a)
	{
		//Polynomial A;
		terms = 0;
		int i, length;
		int poPos = 0, tePos = -1;
		int Tcnt = 0;
		bool minus = false;
		bool Ecnt = false;
		
		//bool first=false;
		length = a.length();
		for (poPos = 0; poPos < 100; poPos++)
			Poly[poPos].coef = 0;
		poPos = 0;

		for (i = 0; i < length; i++)
		{

			if (('0' <= a[i]) && (a[i] <= '9'))
			{
				if (Ecnt == false)
				{
					Poly[poPos].coef = 10 * Poly[poPos].coef + (a[i] - '0');
				}
				else if (Ecnt == true)
				{
					Poly[poPos].termArray[tePos].exp = 10 * Poly[poPos].termArray[tePos].exp + (a[i] - '0');
					
					//tePos++;
					//tepos check 1
				}
			}


			else if (('a' <= a[i]) && (a[i] <= 'z'))
			{
				if (Poly[poPos].coef == 0)
				{
					Poly[poPos].coef = 1;
				}

				if (minus == true)
				{
					Poly[poPos].coef = -Poly[poPos].coef;
					minus = false;
				}

				tePos++;
				Poly[poPos].termArray[tePos].var = a[i];
				
				//sumOfexp ¼³Á¤¿ë
			}


			else if (a[i] == '+')
			{
				
			//	Poly[poPos].sumOfexp += Poly[poPos].termArray[tePos].exp;
				poPos++;
				Ecnt = false;
				tePos = -1;
				terms = poPos;
			//	Poly[poPos].sumOfexp = 0;

			}

			else if (a[i] == '-')
			{
				minus = true;
			}

			else if (a[i] == '^')
			{
				Ecnt = true;
			}

			
			
		}
		int x, y;//for  loop var

		for (x = 0; x < length; x++)
		{
			for (y = 0; y < 26; y++)
			{
				if ((Poly[x].termArray[y].exp == 0) && (Poly[x].termArray[y].var != '\0'))
				{
					Poly[x].termArray[y].exp = 1;
				}
				Poly[x].sumOfexp = Poly[x].sumOfexp + Poly[x].termArray[y].exp;

			}
		}

		
	}
	

	Polynomial SumofPoly(Polynomial B)
	{
		int i;
		Polynomial C;
		int aPos = 0, bPos = 0, cPos = 0;
		while (1)
		{
			if (Poly[aPos].Compare(B.Poly[bPos]))
			{
				
				C.Poly[cPos] = Poly[aPos].SumofTerm(B.Poly[bPos]);
				if (C.Poly[cPos].coef == 0)
				{
					cPos--;
				}
				aPos++; bPos++; cPos++;
				

			}
			else if (Poly[aPos].Bigger(B.Poly[bPos]))
			{
				C.Poly[cPos] = Poly[aPos];
				cPos++; aPos++;
			}
			else if (!(Poly[aPos].Bigger(B.Poly[bPos])))
			{
				C.Poly[cPos] = B.Poly[bPos];
				cPos++; bPos++;
			}

			if (aPos-1 == terms)
			{
				while (1)
				{
					if (bPos-1 == B.terms)
					{
						break;
					}
					C.Poly[cPos] = B.Poly[bPos];
					cPos++; bPos++;

				}

				break;
			}

			else if (bPos-1 == B.terms)
			{
				while (1)
				{
					if (aPos-1 == terms)
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


};

std::ofstream& operator<<(std::ofstream& os, Polynomial &p)
{
	int i,j;
	for (i = 0; i < 200; i++)
	{
		if (p.Poly[i].coef == 0)
		{
			break;
		}
		if ((p.Poly[i].coef > 0) && (i != 0))
		{
			os << '+';
		}
		else if (p.Poly[i].coef < 0)
		{
			os << '-';
		}

		if ((p.Poly[i].coef == 1) || (p.Poly[i].coef == -1))
		{
			if ((p.Poly[i].coef == 1) && (p.Poly[i].termArray[0].exp == 0)){
				os << 1;
				continue;
			}
		}
		else if (p.Poly[i].coef > 0)
		{
			os << p.Poly[i].coef;
		}
		else
		{
			
			os << -p.Poly[i].coef;
		}
		for (j = 0; j < 26; j++)
		{
			if (p.Poly[i].termArray[j].exp == 0)
				break
				;
			else if (p.Poly[i].termArray[j].exp == 1)
				os << p.Poly[i].termArray[j].var;
			else
			{
				os << p.Poly[i].termArray[j].var;
				os << '^';
				os << p.Poly[i].termArray[j].exp;
			}


		}
			
	}
	
	return os;
}


int main(int argc, char **argv)
{
	std::string str_a;
	std::string str_b;

	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);


	while (std::getline(input, str_a))
	{
		std::getline(input, str_b);
		Polynomial A(str_a);
		Polynomial B(str_b);
		Polynomial C;

		C = A.SumofPoly(B);

		output << C;
		output << '\n';
	}

	input.close();
	output.close();
}